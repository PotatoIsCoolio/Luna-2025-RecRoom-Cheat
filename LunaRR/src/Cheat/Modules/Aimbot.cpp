/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Aimbot.h"
#include "obf.h"

using namespace Cheat;
using namespace Cheat::Modules;



Player_T Aimbot::Utils::getClosestPlayer(SDK::Unity::Camera* camera) {
	float maxRadius = Globals::Aimbot::fovCircleRadius;
	Player_T closestPlayer{};
	
	auto screenCenter = ImVec2(ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y / 2.0f);

	for (const auto& player : playersVector) {
		if (!player.instance || !player.head || !player.body)
			continue;

		auto headTransform = player.head->get_transform();
		auto headPosition = camera->WorldToScreenPoint(headTransform->get_position());

		auto bodyTransform = player.body->get_transform();
		auto bodyPosition = camera->WorldToScreenPoint(bodyTransform->get_position());

		auto usedPosition = (Globals::Aimbot::selectedBodyPart == 0) ? headPosition : bodyPosition;

		if (usedPosition.z > 3.f) {
			auto screenCenter = Luma::Unity::Vector2(ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y / 2.0f);
			auto positionToCenterDistance = Luma::Unity::Vector2::Distance({ usedPosition.x, usedPosition.y }, screenCenter);

			if (positionToCenterDistance < maxRadius)
				maxRadius = positionToCenterDistance;

			if (maxRadius == positionToCenterDistance)
				closestPlayer = player;
		}
	}

	return closestPlayer;
}

void Aimbot::Update(Player_T player) {
	if (!Globals::Aimbot::enableAimbot)
		return;

	if (Globals::Aimbot::renderFovCircle) {
		ImVec4 usedColor = ImVec4(Globals::Aimbot::fovCircleColor[0], Globals::Aimbot::fovCircleColor[1], 
							      Globals::Aimbot::fovCircleColor[2], Globals::Aimbot::fovCircleColor[3]);
		
		ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(ImGui::GetIO().DisplaySize.x / 2.0f,
												         ImGui::GetIO().DisplaySize.y / 2.0f),
														 Globals::Aimbot::fovCircleRadius, 
														 ImColor(usedColor.x, usedColor.y, usedColor.z, usedColor.w), 360);
	}

	auto camera = SDK::Unity::Camera::get_current();
	if (!camera || !player.instance || player.instance == Globals::Pointers::localPlayer) 
		return;

	auto closestPlayer = Utils::getClosestPlayer(camera);
	if (!closestPlayer.instance || !closestPlayer.head || !closestPlayer.body)
		return;



	auto cameraTransform = camera->get_transform();
	Luma::Unity::Vector3 cameraPosition = cameraTransform->get_position();

	auto headTransform = closestPlayer.head->get_transform();
	Luma::Unity::Vector3 headPosition = headTransform->get_position();

	auto bodyTransform = closestPlayer.body->get_transform();
	Luma::Unity::Vector3 bodyPosition = bodyTransform->get_position();

	Luma::Unity::Vector3 usedPosition = (Globals::Aimbot::selectedBodyPart == 0) ? headPosition : bodyPosition;

	auto screenPlayer = SDK::Game::LocalPlayerController::get_ScreenPlayerControllerInstance();
	if (screenPlayer) {
		auto cameraSystem = screenPlayer->get_CameraSystem();
		if (cameraSystem) {
			
			Luma::Unity::Quaternion currentRotation = cameraSystem->GetRotation();
			bool isAimbotting = (Globals::Aimbot::selectedAimKey == 0) ? (GetAsyncKeyState(VK_RBUTTON) & 0x8000) : (GetAsyncKeyState(VK_XBUTTON2) & 0x8000);
			
			if (isAimbotting)
			{
				Luma::Unity::Vector3 targetDirection = Luma::Unity::Vector3::Normalize(usedPosition - cameraPosition);
				
				Luma::Unity::Quaternion targetRotation = Luma::Unity::Quaternion::Slerp(currentRotation,
														 Luma::Unity::Quaternion::LookRotation(targetDirection),
														 ImGui::GetIO().DeltaTime * Globals::Aimbot::strength);
				
				cameraSystem->SetRotation(targetRotation);
			}
		}
	}
}


void Aimbot::LoopFire() {
	if (!Globals::Aimbot::loopFire) return;
	auto toolsHeld = Globals::Pointers::localPlayer->get_AllToolsHeld();
	if (toolsHeld && toolsHeld->get_Length() >= 1) {
		for (int i = 0; i < toolsHeld->get_Length(); ++i) {
			
			auto toolHeld = toolsHeld->get_Data()[i];

			if (toolHeld)
			{
				auto rangedWeapon = toolHeld->GetComponent<SDK::Game::RangedWeapon*>(OBFUSCATE("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));
				if (rangedWeapon)
				{
					float bulletSpeed = (Globals::Aimbot::bulletSpeedModifier) 
										? Globals::Aimbot::bulletSpeed 
										: *(float*)((uint64_t)rangedWeapon + 0x238);

					auto barrelTransform = *(SDK::Unity::Transform**)((uint64_t)rangedWeapon + 0x298);

					auto velocity = barrelTransform->get_forward() * bulletSpeed;

					rangedWeapon->Fire(velocity, 1.0f);
				}
			}
		}
	}
}