/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "PlayerGameRoleManager.h"
#include "obf.h"

namespace SDK::Game {

	PlayerGameRoleManager* PlayerGameRoleManager::get_Instance() { return method_get_Instance.Invoke().Get(); }

	void PlayerGameRoleManager::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecRoom.Systems.PlayerRoles"), OBFUSCATE("PlayerGameRoleManager"));
		method_get_Instance = klass.GetMethod(OBFUSCATE("get_Instance"));
	}

	Luma::IL2CPP::Class PlayerGameRoleManager::klass{};
	Luma::IL2CPP::Method<PlayerGameRoleManager*> PlayerGameRoleManager::method_get_Instance;
}