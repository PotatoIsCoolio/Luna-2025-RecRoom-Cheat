/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Render.h"
#include <Console/Console.h>
#include "obf.h"

GUI::Render* GUI::gui = nullptr;


void PurpleStyle()
{	
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(15.0f, 15.0f);
	style.WindowRounding = 4.0f;
	style.WindowBorderSize = 0.0f;
	style.WindowMinSize = ImVec2(20.0f, 20.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_None;
	style.ChildRounding = 4.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 4.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(6.0f, 5.0f);
	style.FrameRounding = 4.0f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(12.0f, 6.0f);
	style.ItemInnerSpacing = ImVec2(6.0f, 3.0f);
	style.CellPadding = ImVec2(12.0f, 6.0f);
	style.IndentSpacing = 20.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 4.0f;
	style.GrabMinSize = 12.0f;
	style.GrabRounding = 4.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	ImVec4* colors = style.Colors;
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.07f, 0.12f, 0.98f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.12f, 0.09f, 0.15f, 0.95f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.15f, 0.10f, 0.22f, 1.0f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.25f, 0.15f, 0.40f, 1.0f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.12f, 0.08f, 0.18f, 0.9f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.12f, 0.20f, 1.0f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.16f, 0.28f, 1.0f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.25f, 0.18f, 0.35f, 1.0f);
	colors[ImGuiCol_Button] = ImVec4(0.50f, 0.25f, 0.75f, 1.0f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.60f, 0.35f, 0.90f, 1.0f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.40f, 0.18f, 0.65f, 1.0f);
	colors[ImGuiCol_Text] = ImVec4(0.97f, 0.97f, 0.99f, 1.0f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.55f, 1.0f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.70f, 0.45f, 1.0f, 1.0f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.60f, 0.35f, 0.90f, 1.0f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.75f, 0.50f, 1.0f, 1.0f);
	colors[ImGuiCol_Border] = ImVec4(0.30f, 0.20f, 0.45f, 0.5f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0, 0, 0, 0);
	colors[ImGuiCol_Separator] = ImVec4(0.35f, 0.25f, 0.50f, 0.6f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.55f, 0.30f, 0.80f, 0.5f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.70f, 0.40f, 0.95f, 0.7f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.85f, 0.55f, 1.0f, 1.0f);
	colors[ImGuiCol_Tab] = ImVec4(0.25f, 0.15f, 0.40f, 0.9f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.45f, 0.25f, 0.70f, 1.0f);
	colors[ImGuiCol_TabActive] = ImVec4(0.35f, 0.20f, 0.55f, 1.0f);
	colors[ImGuiCol_Header] = ImVec4(0.35f, 0.20f, 0.55f, 0.8f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.28f, 0.70f, 0.9f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.55f, 0.35f, 0.85f, 1.0f);
}

void GUI::Render::ModRunner() const
{
	static bool threadInitializer{ false };
	if (!threadInitializer) {
		threadInitializer = true;
		auto domain = Luma::IL2CPP::Structures::Il2CppDomain::Get();
		if (!domain) return;
		domain->AttachToThread();
	}

	static bool varInitializer{ false };
	if (!varInitializer) {
		varInitializer = true;

		// cache line positions
		Globals::Visual::linePositions = {
		{ImVec2(ImGui::GetIO().DisplaySize.x / 2.f, 0.0f)},
		{ImVec2(ImGui::GetIO().DisplaySize.x / 2.f, ImGui::GetIO().DisplaySize.y / 2.f)},
		{ImVec2(ImGui::GetIO().DisplaySize.x / 2.f, ImGui::GetIO().DisplaySize.y)}
		};
	}

	/*
	* Additionally run these managers specifically here, and not FunctionRunner function.
	* This is to avoid iteration lag caused by Update being invoked once per frame.
	*/
	for (auto& plr : playersVector) {
		Cheat::Modules::Visuals::Update(plr);
		Cheat::Modules::Aimbot::Update(plr);
	}

	
}

void GUI::Render::Run() const
{
	if (m_active)
	{

		ImGui::Begin(m_title.c_str());
		{

			if (ImGui::BeginTabBar(OBFUSCATE("Menu")))
			{
				if (ImGui::BeginTabItem(OBFUSCATE("Main")))
				{

					if (Globals::Pointers::localPlayer)
					{
						ImGui::BeginChild(OBFUSCATE("##movementFeatures"), ImVec2(ImGui::GetContentRegionAvail().x / 2.0f, ImGui::GetContentRegionAvail().y - 2.0f), ImGuiChildFlags_Border);
						{
							ImGui::Checkbox(OBFUSCATE("Loop Toggle Fly"), &Globals::Movement::loopFlyToggle);
							if (ImGui::Button(OBFUSCATE("Enable Fly"))) Cheat::Modules::Movement::EnableFly(Globals::Pointers::localPlayer);
							ImGui::SameLine();
							if (ImGui::Button(OBFUSCATE("Disable Fly"))) Cheat::Modules::Movement::DisableFly(Globals::Pointers::localPlayer);

							ImGui::SeparatorText(OBFUSCATE("Movement Properties"));
							{
								ImGui::Checkbox(OBFUSCATE("Loop Override Movement Speed"), &Globals::Movement::loopOverrideMovementSpeed);
								ImGui::SameLine();
								ImGui::PushItemWidth(105.f);
								ImGui::InputFloat(OBFUSCATE("##movementSpeed"), &Globals::Movement::movementSpeed);
								ImGui::PopItemWidth();
								if (ImGui::Button(OBFUSCATE("Set Speed"))) Cheat::Modules::Movement::OverrideWalkSpeed(Globals::Pointers::localPlayer, Globals::Movement::movementSpeed);
								ImGui::SameLine();
								if (ImGui::Button(OBFUSCATE("Restore##walkSpeed"))) {
									Globals::Movement::loopOverrideMovementSpeed = false;
									Cheat::Modules::Movement::RestoreWalkSpeed(Globals::Pointers::localPlayer);
								}
								if (ImGui::IsItemHovered()) ImGui::SetTooltip(OBFUSCATE("Notice: Restores to default game walk speed value"));

								ImGui::Separator();

								ImGui::Checkbox(OBFUSCATE("Loop Override Jump Height"), &Globals::Movement::loopOverrideJumpHeight);
								ImGui::SameLine();
								ImGui::PushItemWidth(105.f);
								ImGui::InputFloat(OBFUSCATE("##jumpHeight"), &Globals::Movement::jumpHeight);
								ImGui::PopItemWidth();
								if (ImGui::Button(OBFUSCATE("Set Height"))) Cheat::Modules::Movement::OverrideJumpHeight(Globals::Pointers::localPlayer, Globals::Movement::jumpHeight);
								ImGui::SameLine();
								if (ImGui::Button(OBFUSCATE("Restore##jumpHeight"))) {
									Globals::Movement::loopOverrideJumpHeight = false;
									Cheat::Modules::Movement::RestoreJumpHeight(Globals::Pointers::localPlayer);
								}
								if (ImGui::IsItemHovered()) ImGui::SetTooltip(OBFUSCATE("Notice: Restores to default game jump height value"));
							}
						} // end of movement side logic
						ImGui::EndChild();

						ImGui::SameLine();

						ImGui::BeginChild(OBFUSCATE("##miscMods"), ImVec2(ImGui::GetContentRegionAvail().x - 2.0f, ImGui::GetContentRegionAvail().y - 2.0f), ImGuiChildFlags_Border);
						{
							ImGui::Checkbox(OBFUSCATE("Player List (Viewing Purposes)"), &Globals::Misc::playerList);
							ImGui::Checkbox(OBFUSCATE("Loop Grant Master"), &Globals::Exclusive::loopGrantMaster);
							ImGui::Checkbox(OBFUSCATE("Asset Spawn Window"), &Globals::Exclusive::assetSpawnWindow);
							ImGui::Checkbox(OBFUSCATE("Gift Spawn Window"), &Globals::Exclusive::giftSpawnWindow);
							ImGui::InputFloat(OBFUSCATE("##headScale"), &Globals::Misc::headScale);
							if (ImGui::Button(OBFUSCATE("Change Head Scale"))) Globals::Pointers::localPlayer->SetHeadScale(Globals::Misc::headScale);
							ImGui::SameLine();
							if (ImGui::Button(OBFUSCATE("Restore Head Scale"))) Globals::Pointers::localPlayer->SetHeadScale(1.0f);
						} // end of misc side logic
						ImGui::EndChild();

					}

					else
					{
						ImGui::TextUnformatted(OBFUSCATE("Player not found!"));
					}

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem(OBFUSCATE("Visuals")))
				{
					ImGui::BeginChild(OBFUSCATE("##espMenu"), ImVec2(ImGui::GetContentRegionAvail().x / 2.0f, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_Border);
					{
						ImGui::Checkbox(OBFUSCATE("Enable ESP"), &Globals::Visual::enableEsp);
						if (Globals::Visual::enableEsp)
						{
							ImGui::Checkbox(OBFUSCATE("Line ESP"), &Globals::Visual::lineEsp);
							{
								ImGui::SameLine();
								
								ImGui::PushItemWidth(105.0f);
								ImGui::SliderFloat(OBFUSCATE("##lineThickness"), &Globals::Visual::lineThickness, 1.f, 3.f);
								ImGui::PopItemWidth();

								ImGui::Combo(OBFUSCATE("Line Position"), &Globals::Visual::selectedLinePosition, Globals::Visual::linePositionNames, IM_ARRAYSIZE(Globals::Visual::linePositionNames));
							}
							
							ImGui::Separator();

							ImGui::Checkbox(OBFUSCATE("Skeleton ESP"), &Globals::Visual::skeletonEsp);

							ImGui::Separator();

							if (ImGui::Checkbox(OBFUSCATE("2D Box ESP"), &Globals::Visual::boxEsp2D)) Globals::Visual::boxEsp3D = false;
							if (ImGui::Checkbox(OBFUSCATE("Filled Box ESP"), &Globals::Visual::boxEspFilled)) Globals::Visual::boxOutlines = false;
							if (ImGui::Checkbox(OBFUSCATE("Outline Box ESP"), &Globals::Visual::boxOutlines)) Globals::Visual::boxEspFilled = false;
							if (ImGui::Checkbox(OBFUSCATE("3D Box ESP"), &Globals::Visual::boxEsp3D)) Globals::Visual::boxEsp2D = false;
							ImGui::PushItemWidth(105.0f);
							ImGui::SliderFloat(OBFUSCATE("Box Thickness"), &Globals::Visual::boxThickness, 1.f, 3.f);
							ImGui::PopItemWidth();
						}
					} // end of esp menu logic
					ImGui::EndChild();

					ImGui::SameLine();

					ImGui::BeginChild(OBFUSCATE("##espColorsMenu"), ImVec2(ImGui::GetContentRegionAvail().x - 2.f, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_Border);
					{
						ImGui::SeparatorText(OBFUSCATE("Line"));
						{
							ImGui::ColorEdit4(OBFUSCATE("Player Color ##line"), Globals::Visual::lineColor, ImGuiColorEditFlags_NoInputs);
						}

						ImGui::SeparatorText(OBFUSCATE("Skeleton"));
						{
							ImGui::ColorEdit4(OBFUSCATE("Player Color ##skeleton"), Globals::Visual::skeletonColor, ImGuiColorEditFlags_NoInputs);
						}

						ImGui::SeparatorText(OBFUSCATE("Box"));
						{
							ImGui::ColorEdit4(OBFUSCATE("Player Color ##box"), Globals::Visual::boxColor, ImGuiColorEditFlags_NoInputs);
						}

					} // end of esp menu colors logic
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem(OBFUSCATE("Aimbot")))
				{
					ImGui::BeginChild(OBFUSCATE("##aimbotMenu"), ImVec2(ImGui::GetContentRegionAvail().x / 2.0f, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_Border);
					{
						ImGui::Checkbox(OBFUSCATE("Enable Aimbot"), &Globals::Aimbot::enableAimbot);
						ImGui::SameLine();
						ImGui::PushItemWidth(125.0f);
						ImGui::SliderFloat(OBFUSCATE("##aimRadius"), &Globals::Aimbot::fovCircleRadius, 25.0f, 250.0f);
						ImGui::PopItemWidth();
						ImGui::SliderFloat(OBFUSCATE("Strength"), &Globals::Aimbot::strength, 0.0f, 100.0f);
						ImGui::Combo(OBFUSCATE("Body Part"), &Globals::Aimbot::selectedBodyPart, Globals::Aimbot::bodyPartNames, IM_ARRAYSIZE(Globals::Aimbot::bodyPartNames));
						ImGui::Combo(OBFUSCATE("Aim Key"), &Globals::Aimbot::selectedAimKey, Globals::Aimbot::aimKeyNames, IM_ARRAYSIZE(Globals::Aimbot::aimKeyNames));
						ImGui::Checkbox(OBFUSCATE("Render FOV Circle"), &Globals::Aimbot::renderFovCircle);
						
						ImGui::SeparatorText(OBFUSCATE("Weapon Exploits (MORE COMING SOON)"));
						
						ImGui::Checkbox(OBFUSCATE("Loop Fire"), &Globals::Aimbot::loopFire);

						ImGui::Checkbox(OBFUSCATE("Bullet Speed Modifier (Loop Fire)"), &Globals::Aimbot::bulletSpeedModifier);
						ImGui::SameLine();
						ImGui::PushItemWidth(125.0f);
						ImGui::InputFloat(OBFUSCATE("##bulletSpeed"), &Globals::Aimbot::bulletSpeed);
						ImGui::PopItemWidth();
					}
					ImGui::EndChild();
					
					ImGui::SameLine();

					ImGui::BeginChild(OBFUSCATE("##aimbotColorsMenu"), ImVec2(ImGui::GetContentRegionAvail().x - 2.0f, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_Border);
					{
						ImGui::ColorEdit4(OBFUSCATE("Circle Color"), Globals::Aimbot::fovCircleColor, ImGuiColorEditFlags_NoInputs);
					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem(OBFUSCATE("Settings (Under Construction)")))
				{
					ImGui::Text(OBFUSCATE("Hello!"));
					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
}

void GUI::Render::RunExtra() const
{
	if (!m_active)
		return;

	if (Globals::Misc::playerList)
	{
		ImGui::Begin(OBFUSCATE("Basic Player List"));
		{
			for (auto& plr : playersVector) {
				if (!plr.instance) continue;
				auto localHeadPosition = Globals::Pointers::localPlayer->get_Head()->get_transform()->get_position();
				auto headPosition = plr.head->get_transform()->get_position();
				ImGui::BulletText(
					OBFUSCATE("Player: [%i, %s] | Position: (%f, %f, %f) | Distance: [%f]"),
					plr.index,
					plr.playerName.c_str(),
					headPosition.x,
					headPosition.y,
					headPosition.z,
					Luma::Unity::Vector3::Distance(headPosition, localHeadPosition)
				);
				ImGui::Separator();
			}
		}
		ImGui::End();
	}

	if (Globals::Exclusive::assetSpawnWindow)
	{
		ImGui::Begin(OBFUSCATE("Asset Spawn Window (Exclusive)"), NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		if (ImGui::Button(OBFUSCATE("Spawn Asset"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f))) Globals::Exclusive::spawnAssetExecute = true;
		
		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
		ImGui::InputInt(OBFUSCATE("##prefabAmount"), &Globals::Exclusive::prefabAmount);
		ImGui::PopItemWidth();

		ImGui::Checkbox(OBFUSCATE("No Asset Render"), &Globals::Exclusive::noRender);

		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Override Prefab Scale (Vector3)"), &Globals::Exclusive::overrideScale);
		if (Globals::Exclusive::overrideScale)
		{
			ImGui::PushItemWidth(95.0f);
			ImGui::InputFloat(OBFUSCATE("X Scale"), &Globals::Exclusive::prefabScale.x);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Y Scale"), &Globals::Exclusive::prefabScale.y);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Z Scale"), &Globals::Exclusive::prefabScale.z);
			ImGui::PopItemWidth();
			ImGui::TextUnformatted(OBFUSCATE("Use same value on each axis input for fixed scale"));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Override Vector/Position"), &Globals::Exclusive::overrideVector);
		if (Globals::Exclusive::overrideVector)
		{
			ImGui::PushItemWidth(95.0f);
			ImGui::InputFloat(OBFUSCATE("X Vector"), &Globals::Exclusive::overridenVector.x);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Y Vector"), &Globals::Exclusive::overridenVector.y);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Z Vector"), &Globals::Exclusive::overridenVector.z);
			ImGui::PopItemWidth();
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Override Quaternion/Rotation"), &Globals::Exclusive::overrideQuaternion);
		if (Globals::Exclusive::overrideQuaternion)
		{
			ImGui::PushItemWidth(95.0f);
			ImGui::InputFloat(OBFUSCATE("X Axis"), &Globals::Exclusive::overridenQuaternion.x);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Y Axis"), &Globals::Exclusive::overridenQuaternion.y);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("Z Axis"), &Globals::Exclusive::overridenQuaternion.z);
			ImGui::SameLine();
			ImGui::InputFloat(OBFUSCATE("W Scalar"), &Globals::Exclusive::overridenQuaternion.w);
			ImGui::PopItemWidth();
		}

		ImGui::Separator();

		static ImGuiTextFilter prefabFilter;

		if (ImGui::Button(OBFUSCATE("Clear Input"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)))
			prefabFilter.Clear();

		prefabFilter.Draw(OBFUSCATE("##prefabInput"), ImGui::GetContentRegionAvail().x);

		ImGui::Separator();

		for (int i = 0; i < Globals::Lists::prefabList.size(); ++i)
			if (prefabFilter.PassFilter(Globals::Lists::prefabList[i].c_str()))
				if (ImGui::Selectable(Globals::Lists::prefabList[i].c_str(), Globals::Lists::selectedPrefab == i))
					Globals::Lists::selectedPrefab = i;

		ImGui::End();
	}

	if (Globals::Exclusive::giftSpawnWindow)
	{
		ImGui::Begin(OBFUSCATE("Gift Spawn Window"));
		if (ImGui::Button(OBFUSCATE("Spawn Gift Box"), ImVec2(ImGui::GetContentRegionAvail().x, 0.f))) {
			Globals::Exclusive::spawnGiftExecute = true;
		}

		static std::vector<const char*> tempContextVector{};
		if (tempContextVector.empty())
			for (const auto& [value, contextName] : Globals::Lists::giftContexList)
				tempContextVector.push_back(contextName.c_str());

		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
		ImGui::Combo(OBFUSCATE("##giftRarity"), &Globals::Exclusive::selectedGiftRarity, Globals::Exclusive::giftRarityNames, IM_ARRAYSIZE(Globals::Exclusive::giftRarityNames));
		ImGui::Combo(OBFUSCATE("##giftConfig"), &Globals::Exclusive::selectedGiftConfig, Globals::Exclusive::giftConfigNames, IM_ARRAYSIZE(Globals::Exclusive::giftConfigNames));
		ImGui::Combo(OBFUSCATE("##giftContext"), &Globals::Lists::selectedGiftContext, tempContextVector.data(), tempContextVector.size());
		ImGui::PopItemWidth();

		ImGui::Separator();

		static std::vector<const char*> tempCurrencyVector{};
		if (tempCurrencyVector.empty())
			for (const auto& [value, name] : Globals::Lists::currencyTypeList)
				tempCurrencyVector.push_back(name.c_str());

		switch (Globals::Exclusive::selectedGiftConfig) {
		case 0:
			ImGui::Combo(OBFUSCATE("##currencyType"), &Globals::Lists::selectedCurrencyType, tempCurrencyVector.data(), tempCurrencyVector.size());
			ImGui::InputInt(OBFUSCATE("Currency Amount"), &Globals::Exclusive::currencyAmount);

			break; // Currency
		case 1: // Consumable
			ImGui::InputText(OBFUSCATE("Consumable Desc"), &Globals::Exclusive::consumableItemDesc);
			break;
		case 2: // Skin
			ImGui::InputText(OBFUSCATE("Equipment Prefab Name (Skin Prefab)"), &Globals::Exclusive::equipmentPrefabName);
			ImGui::InputText(OBFUSCATE("Equipment Modification GUID (Skin GUID)"), &Globals::Exclusive::equipmentModificationGuid);
			break;
		case 3:
			ImGui::InputText(OBFUSCATE("Avatar Item Description (Clothing GUID)"), &Globals::Exclusive::avatarItemDescription);
			break; // Avatar
		}

		ImGui::End();
	}
}

void GUI::Render::Create(const std::string& title) {
	if (!GUI::gui) GUI::gui = new Render(title);
}

bool GUI::Render::IsActive() { return m_active; }

void GUI::Render::InitImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context) {
	ImGui::CreateContext();
	
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontFromFileTTF(OBFUSCATE("C:\\Windows\\Fonts\\Arial.ttf"), 18.0f);
	PurpleStyle();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, context);
}

void GUI::Render::KeyManager() {
	if (GetAsyncKeyState(VK_INSERT) & 1 || GetAsyncKeyState(VK_DELETE) & 1)
		m_active = !m_active;
	ImGui::GetIO().MouseDrawCursor = m_active;
}