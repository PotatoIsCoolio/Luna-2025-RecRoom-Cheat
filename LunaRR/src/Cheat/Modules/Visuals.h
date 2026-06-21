/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <imgui_internal.h>
#include "../Managers/Players.h"
#include "../Globals.h"

namespace Cheat::Modules::Visuals {
	namespace Drawing {
		// Helper
		extern bool IsOnScreen(Luma::Unity::Vector3 screenPosition);

		// lines (base for lots of drawing)
		extern void DrawLine(ImVec2 a, ImVec2 b, ImVec4 col, float thickness = 1.0f);
		extern void DrawLine(ImVec2 a, Luma::Unity::Vector3 b, ImVec4 col, float thickness = 1.0f);
		extern void DrawLine(Luma::Unity::Vector3 a, Luma::Unity::Vector3 b, ImVec4 col, float thickness = 1.0f);


		extern void DrawLineESP(SDK::Unity::Camera* camera, Player_T player);
		extern void DrawSkeleton(SDK::Unity::Camera* camera, Player_T player);
		extern void Draw2DBox(SDK::Unity::Camera* camera, Player_T player);
		extern void Draw3DBox(SDK::Unity::Camera* camera, Player_T player);
	}

	extern void Update(Player_T player);
}