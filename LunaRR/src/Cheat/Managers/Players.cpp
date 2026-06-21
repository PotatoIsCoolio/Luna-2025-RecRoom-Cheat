/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Players.h"

std::vector<Player_T> playersVector;

namespace Cheat::Managers {
	U_Players Players;

	bool U_Players::IsPlayerPresent(SDK::Game::Player* player) {
		return std::ranges::any_of(playersVector.begin(), playersVector.end(), [&](Player_T plr) { return plr.instance == player; });
	}

	void U_Players::AddPlayer(SDK::Game::Player* player) {
		if (!player || IsPlayerPresent(player))
			return;

		Player_T newPlayer{};

		// this is the only property you can cache in this method, as invoking anything else causes a crash.
		newPlayer.instance = player;

		newPlayer.index = player->get_PlayerIndex();
		newPlayer.respawnDuration = player->get_RespawnDuration();
		newPlayer.despawnDuration = player->get_DespawnDuration();
		newPlayer.isUsingFullbody = player->get_UsesFullBodyAvatar();
		newPlayer.playerName = player->get_PlayerName();
		newPlayer.objectName = player->get_name();

		newPlayer.playerMovement = player->get_PlayerMovement();
		newPlayer.toolsHeld = player->get_AllToolsHeld();

		newPlayer.head = player->get_Head();
		newPlayer.body = player->get_Body();
		newPlayer.leftHand = player->get_LeftHand();
		newPlayer.rightHand = player->get_RightHand();

		playersVector.push_back(newPlayer);
	}

	void U_Players::RemovePlayer(SDK::Game::Player* player) {
		if (!player) return;
		for (int idx = 0; idx < playersVector.size(); idx++) {
			if (playersVector[idx].instance == player) {
				playersVector.erase(playersVector.begin() + idx);
				break; // exit loop immediately after erasing target
			}
		}
	}
}