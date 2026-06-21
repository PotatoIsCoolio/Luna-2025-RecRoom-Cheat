/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "Empty/RRNetworkBehavior.h"

namespace SDK::Game {
	struct PlayerGameRoleManager : RRNetworkBehavior {
	public:
		static PlayerGameRoleManager* get_Instance();

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<PlayerGameRoleManager*> method_get_Instance;
	};
}