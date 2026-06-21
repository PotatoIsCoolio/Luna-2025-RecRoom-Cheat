/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "../Managers/Players.h"
#include "../Globals.h"

namespace Cheat::Modules::Aimbot {
	namespace Utils {
		extern Player_T getClosestPlayer(SDK::Unity::Camera* camera);
	}
	extern void Update(Player_T player);
	extern void LoopFire();
}