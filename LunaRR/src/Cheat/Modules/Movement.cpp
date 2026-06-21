/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Movement.h"


namespace Cheat::Modules {
    inline bool PerformChecks(SDK::Game::Player* player) {
        if (!player) return false;
        auto playerMovement = player->get_PlayerMovement();
        if (!playerMovement) return false;
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        if (!roleManager) return false;
        return true;
    }

    void Movement::Update(SDK::Game::Player* player) {
        if (Globals::Movement::loopFlyToggle) EnableFly(player);
        if (Globals::Movement::loopOverrideMovementSpeed) OverrideWalkSpeed(player, Globals::Movement::movementSpeed);
        if (Globals::Movement::loopOverrideJumpHeight) OverrideJumpHeight(player, Globals::Movement::jumpHeight);
    }

    void Movement::EnableFly(SDK::Game::Player* player) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        if (!playerMovement->get_IsFlyingEnabled())
            playerMovement->AddFlyEnabled(true, roleManager, 0);
    }

    void Movement::DisableFly(SDK::Game::Player* player) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        if (playerMovement->get_IsFlyingEnabled())
            playerMovement->RemoveFlyEnabled(roleManager);
    }

    void Movement::OverrideWalkSpeed(SDK::Game::Player* player, float maxSpeed) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        playerMovement->AddMaxWalkSpeed(maxSpeed, roleManager, 0);
    }


    void Movement::OverrideJumpHeight(SDK::Game::Player* player, float maxHeight) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        playerMovement->AddMaxJumpHeight(maxHeight, roleManager, 0);
    }

    void Movement::RestoreJumpHeight(SDK::Game::Player* player) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        playerMovement->RemoveMaxJumpHeight(roleManager);
    }

    void Movement::RestoreWalkSpeed(SDK::Game::Player* player) {
        if (!PerformChecks(player)) return;
        auto playerMovement = player->get_PlayerMovement();
        auto roleManager = SDK::Game::PlayerGameRoleManager::get_Instance();
        playerMovement->RemoveMaxWalkSpeed(roleManager);
    }
}