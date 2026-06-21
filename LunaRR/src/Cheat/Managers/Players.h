/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <SDK/SDK.h>

struct Player_T
{
	// basic obj
	SDK::Game::Player* instance;

	// player info
	int index;
	float respawnDuration;
	float despawnDuration;
	bool isUsingFullbody;
	std::string playerName;
	std::string objectName;
	int accountId;

	// player objects
	SDK::Game::PlayerMovement* playerMovement;
	Luma::Mono::Array<SDK::Game::Tool*>* toolsHeld;

	// skeleton
	SDK::Game::PlayerHead* head;
	SDK::Game::PlayerBody* body;
	SDK::Game::PlayerHand* leftHand;
	SDK::Game::PlayerHand* rightHand;

};


extern std::vector<Player_T> playersVector;

namespace Cheat::Managers {
	struct U_Players {
		bool IsPlayerPresent(SDK::Game::Player* player);
		void AddPlayer(SDK::Game::Player* player);
		void RemovePlayer(SDK::Game::Player* player);
	};
	extern U_Players Players;
}