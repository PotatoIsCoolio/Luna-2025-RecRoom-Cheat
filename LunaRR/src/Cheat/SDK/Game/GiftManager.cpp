/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "GiftManager.h"
#include "obf.h"

namespace SDK::Game {

	void GiftManager::SpawnGiftPackage(GiftPackage* packageToSpawn) { method_SpawnGiftPackage.Invoke(packageToSpawn); }

	void GiftManager::Setup() {
		klass = Luma::IL2CPP::Class("", OBFUSCATE("GiftManager"));
		method_SpawnGiftPackage = klass.GetMethod(OBFUSCATE("SpawnGiftPackage"), 1);
	}

	Luma::IL2CPP::Class GiftManager::klass{};
	Luma::IL2CPP::Method<void> GiftManager::method_SpawnGiftPackage;
}