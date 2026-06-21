/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Cheat/Globals.h>

namespace Cheat::Modules::Movement {
    extern void Update(SDK::Game::Player* player);

    extern void EnableFly(SDK::Game::Player* player);
    extern void DisableFly(SDK::Game::Player* player);
    extern void OverrideWalkSpeed(SDK::Game::Player* player, float maxSpeed);
    extern void OverrideJumpHeight(SDK::Game::Player* player, float maxHeight);

    extern void RestoreWalkSpeed(SDK::Game::Player* player);
    extern void RestoreJumpHeight(SDK::Game::Player* player);
}