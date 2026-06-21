/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Visuals.h"
#undef min
#undef max

using namespace Cheat::Modules;

bool Visuals::Drawing::IsOnScreen(Luma::Unity::Vector3 screenPosition) { return screenPosition.z > 3.f; }

void Visuals::Drawing::DrawLine(ImVec2 a, ImVec2 b, ImVec4 col, float thickness) {
	ImGui::GetBackgroundDrawList()->AddLine(a, b, ImColor(col.x, col.y, col.z, col.w), thickness);
}

void Visuals::Drawing::DrawLine(ImVec2 a, Luma::Unity::Vector3 b, ImVec4 col, float thickness) {
	DrawLine(a, ImVec2(b.x, b.y), col, thickness);
}

void Visuals::Drawing::DrawLine(Luma::Unity::Vector3 a, Luma::Unity::Vector3 b, ImVec4 col, float thickness) {
	DrawLine(ImVec2(a.x, a.y), b, col, thickness);
}

void Visuals::Drawing::DrawLineESP(SDK::Unity::Camera* camera, Player_T player) {
	if (!camera || !player.instance || !player.body)
		return;

	float screenWidth = ImGui::GetIO().DisplaySize.x;
	float screenHeight = ImGui::GetIO().DisplaySize.y;


	auto headTransform = player.head->get_transform();
	auto headPos = headTransform->get_position();

	auto bodyTransform = player.body->get_transform();
	auto bodyPos = bodyTransform->get_position();

	auto lineOffset = (Globals::Visual::boxEsp3D)
		? Luma::Unity::Vector3(0.f, 0.31f, 0.f)
		: Luma::Unity::Vector3(0.f, 0.31f, 0.f);

	auto usedPosition = (Globals::Visual::selectedLinePosition == 1 || Globals::Visual::selectedLinePosition == 2)
		? bodyPos
		: headPos + lineOffset;

	auto usedPositionScreen = camera->WorldToScreenPoint(usedPosition);


	auto usedColor = ImVec4(Globals::Visual::lineColor[0], Globals::Visual::lineColor[1], 
						    Globals::Visual::lineColor[2], Globals::Visual::lineColor[3]);

	if (IsOnScreen(usedPositionScreen)) DrawLine(Globals::Visual::linePositions[Globals::Visual::selectedLinePosition],
												usedPositionScreen, usedColor, Globals::Visual::lineThickness);
}

void Visuals::Drawing::DrawSkeleton(SDK::Unity::Camera* camera, Player_T player) {
	if (!camera || !player.instance || !player.head || !player.body || !player.leftHand || !player.rightHand)
		return;

	auto headTransform = player.head->get_transform();
	auto headPos = camera->WorldToScreenPoint(headTransform->get_position());

	auto bodyTransform = player.body->get_transform();
	auto bodyPos = camera->WorldToScreenPoint(bodyTransform->get_position());

	auto leftHandTransform = player.leftHand->get_transform();
	auto leftHandPos = camera->WorldToScreenPoint(leftHandTransform->get_position());

	auto rightHandTransform = player.rightHand->get_transform();
	auto rightHandPos = camera->WorldToScreenPoint(rightHandTransform->get_position());

	if (IsOnScreen(headPos) && IsOnScreen(bodyPos) && IsOnScreen(leftHandPos) && IsOnScreen(rightHandPos)) {
		auto usedColor = ImVec4(Globals::Visual::skeletonColor[0], Globals::Visual::skeletonColor[1],
								Globals::Visual::skeletonColor[2], Globals::Visual::skeletonColor[3]);
		DrawLine(headPos, bodyPos, usedColor);
		DrawLine(bodyPos, leftHandPos, usedColor);
		DrawLine(bodyPos, rightHandPos, usedColor);
	}
}

void Visuals::Drawing::Draw2DBox(SDK::Unity::Camera* camera, Player_T player) {
	if (!camera || !player.instance || !player.head || !player.body || !player.leftHand || !player.rightHand)
		return;

	auto headTransform = player.head->get_transform();
	auto headPos = camera->WorldToScreenPoint(headTransform->get_position() + Luma::Unity::Vector3(0.f, 0.3f, 0.f));

	auto bodyTransform = player.body->get_transform();
	auto bodyPos = camera->WorldToScreenPoint(bodyTransform->get_position() - Luma::Unity::Vector3(0.f, 0.43f, 0.f));

	if (IsOnScreen(headPos) && IsOnScreen(bodyPos)) {

		auto usedColor = ImVec4(Globals::Visual::boxColor[0], Globals::Visual::boxColor[1],
							    Globals::Visual::boxColor[2], Globals::Visual::boxColor[3]);


		float boxHeight = std::abs(headPos.y - bodyPos.y);
		float boxWidth = boxHeight * 0.60f;
		auto box = Luma::Unity::Vector2(headPos.x - (boxWidth / 2), headPos.y);

		if (Globals::Visual::boxEspFilled) {
			ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(box.x, box.y), ImVec2(box.x + boxWidth, box.y + boxHeight), ImColor(usedColor.x, usedColor.y, usedColor.z, 0.4f), 0.0f, 0);
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(box.x - 1.2f, box.y - 1.2f), ImVec2((box.x + 1.2f) + boxWidth, (box.y + 1.2f) + boxHeight), ImColor(usedColor.x, usedColor.y, usedColor.z, usedColor.w), 0.0f, 0, 1.4f);
		}
		else if (Globals::Visual::boxOutlines) {
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(box.x + 1.0f, box.y + 1.0f), ImVec2((box.x - 1.0f) + boxWidth, (box.y - 1.0f) + boxHeight), ImColor(0, 0, 0, 255), 0.0f, 0, Globals::Visual::boxThickness);
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(box.x - 1.0f, box.y - 1.0f), ImVec2((box.x + 1.0f) + boxWidth, (box.y + 1.0f) + boxHeight), ImColor(0, 0, 0, 255), 0.0f, 0, Globals::Visual::boxThickness);
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(box.x, box.y), ImVec2(box.x + boxWidth, box.y + boxHeight), ImColor(usedColor.x, usedColor.y, usedColor.z, usedColor.w), 0.0f, 0, Globals::Visual::boxThickness);
		}
		else {
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(box.x, box.y), ImVec2(box.x + boxWidth, box.y + boxHeight), ImColor(usedColor.x, usedColor.y, usedColor.z, usedColor.w), 0.0f, 0, Globals::Visual::boxThickness);
		}
	}
}

void Visuals::Drawing::Draw3DBox(SDK::Unity::Camera* camera, Player_T player) {
	if (!camera || !player.instance || !player.head || !player.body || !player.leftHand || !player.rightHand)
		return;

	auto headTransform = player.head->get_transform();
	auto headPos = headTransform->get_position();

	auto bodyTransform = player.body->get_transform();
	auto bodyPos = bodyTransform->get_position();

	auto leftHandTransform = player.leftHand->get_transform();
	auto leftHandPos = leftHandTransform->get_position();

	auto rightHandTransform = player.rightHand->get_transform();
	auto rightHandPos = rightHandTransform->get_position();

	// store for dynamic verticies
	float minX = std::min({ headPos.x, bodyPos.x, leftHandPos.x, rightHandPos.x });
	float maxX = std::max({ headPos.x, bodyPos.x, leftHandPos.x, rightHandPos.x });

	float minY = std::min({ headPos.y, bodyPos.y, leftHandPos.y, rightHandPos.y });
	float maxY = std::max({ headPos.y, bodyPos.y, leftHandPos.y, rightHandPos.y });

	float minZ = std::min({ headPos.z, bodyPos.z, leftHandPos.z, rightHandPos.z });
	float maxZ = std::max({ headPos.z, bodyPos.z, leftHandPos.z, rightHandPos.z });

	// offsets
	float boxWidth = 0.31f;
	float boxTop = 0.05f;
	float boxBottom = 0.05f;
	float boxLength = 0.31f; // use same value to width to keep box proportional

	auto centeredHandsForMisonSere = (leftHandPos.y + rightHandPos.y) / 2.f;

	// verticies
	Luma::Unity::Vector3 topLeftFront = Luma::Unity::Vector3((headPos.x - boxWidth), headPos.y + 0.2f, maxZ + boxLength);
	Luma::Unity::Vector3 topRightFront = Luma::Unity::Vector3((headPos.x + boxWidth), headPos.y + 0.2f, maxZ + boxLength);
	Luma::Unity::Vector3 bottomRightFront = Luma::Unity::Vector3((headPos.x + boxWidth), centeredHandsForMisonSere, maxZ + boxLength);
	Luma::Unity::Vector3 bottomLeftFront = Luma::Unity::Vector3((headPos.x - boxWidth), centeredHandsForMisonSere, maxZ + boxLength);

	Luma::Unity::Vector3 topLeftBack = Luma::Unity::Vector3((headPos.x - boxWidth), headPos.y + 0.2f, minZ - boxLength);
	Luma::Unity::Vector3 topRightBack = Luma::Unity::Vector3((headPos.x + boxWidth), headPos.y + 0.2f, minZ - boxLength);
	Luma::Unity::Vector3 bottomRightBack = Luma::Unity::Vector3((headPos.x + boxWidth), centeredHandsForMisonSere, minZ - boxLength);
	Luma::Unity::Vector3 bottomLeftBack = Luma::Unity::Vector3((headPos.x - boxWidth), centeredHandsForMisonSere, minZ - boxLength);

	// convert verticies to screen pos
	Luma::Unity::Vector3 topLeftFrontScreen = camera->WorldToScreenPoint(topLeftFront);
	Luma::Unity::Vector3 topRightFrontScreen = camera->WorldToScreenPoint(topRightFront);
	Luma::Unity::Vector3 bottomRightFrontScreen = camera->WorldToScreenPoint(bottomRightFront);
	Luma::Unity::Vector3 bottomLeftFrontScreen = camera->WorldToScreenPoint(bottomLeftFront);

	Luma::Unity::Vector3 topLeftBackScreen = camera->WorldToScreenPoint(topLeftBack);
	Luma::Unity::Vector3 topRightBackScreen = camera->WorldToScreenPoint(topRightBack);
	Luma::Unity::Vector3 bottomRightBackScreen = camera->WorldToScreenPoint(bottomRightBack);
	Luma::Unity::Vector3 bottomLeftBackScreen = camera->WorldToScreenPoint(bottomLeftBack);


	if (IsOnScreen(topLeftFrontScreen) && IsOnScreen(topRightFrontScreen) && IsOnScreen(bottomRightFrontScreen) && IsOnScreen(bottomLeftFrontScreen)
		&& IsOnScreen(topLeftBackScreen) && IsOnScreen(topRightBackScreen) && IsOnScreen(bottomRightBackScreen) && IsOnScreen(bottomLeftBackScreen))
	{
		auto usedColor = ImVec4(Globals::Visual::boxColor[0], Globals::Visual::boxColor[1],
			Globals::Visual::boxColor[2], Globals::Visual::boxColor[3]);

		// draw front plate
		DrawLine(topLeftFrontScreen, topRightFrontScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(topRightFrontScreen, bottomRightFrontScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomRightFrontScreen, bottomLeftFrontScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomLeftFrontScreen, topLeftFrontScreen, usedColor, Globals::Visual::boxThickness);

		// draw back plate
		DrawLine(topLeftBackScreen, topRightBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(topRightBackScreen, bottomRightBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomRightBackScreen, bottomLeftBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomLeftBackScreen, topLeftBackScreen, usedColor, Globals::Visual::boxThickness);

		// connect front & back top & bottom corners to complete box
		DrawLine(topLeftFrontScreen, topLeftBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(topRightFrontScreen, topRightBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomLeftFrontScreen, bottomLeftBackScreen, usedColor, Globals::Visual::boxThickness);
		DrawLine(bottomRightFrontScreen, bottomRightBackScreen, usedColor, Globals::Visual::boxThickness);
	}
}

void Visuals::Update(Player_T player) {
	if (!Globals::Visual::enableEsp)
		return;

	auto camera = SDK::Unity::Camera::get_current();
	if (!camera || !player.instance || player.instance == Globals::Pointers::localPlayer) 
		return;

	if (Globals::Visual::lineEsp) Drawing::DrawLineESP(camera, player);
	if (Globals::Visual::skeletonEsp) Drawing::DrawSkeleton(camera, player);
	if (Globals::Visual::boxEsp2D) Drawing::Draw2DBox(camera, player);
	if (Globals::Visual::boxEsp3D) Drawing::Draw3DBox(camera, player);
}