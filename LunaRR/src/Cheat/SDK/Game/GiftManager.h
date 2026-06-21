/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "../Unity/Empty/MonoBehaviour.h"

namespace SDK::Game {
	struct GiftPackage;

	struct GiftManager : Unity::MonoBehaviour {
	public:
		static void SpawnGiftPackage(GiftPackage* packageToSpawn);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<void> method_SpawnGiftPackage;
	};
}