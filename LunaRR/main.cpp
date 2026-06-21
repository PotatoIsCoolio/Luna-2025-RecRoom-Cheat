/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/

#include <fstream>
#include <thread>
#include <Console/Console.h>
#include <GUI/Setup.h>
#include <minhook/include/MinHook.h>
#include "obf.h"

// replace with an actual system soon.
bool isAuthenticated{ true };
bool requireAuthentication{ true };

void FunctionRunner() 
{

	Globals::Pointers::localPlayer = SDK::Game::Player::get_LocalPlayer();

	if (Globals::Pointers::localPlayer)
	{
		Cheat::Modules::Aimbot::LoopFire();
		Cheat::Modules::Movement::Update(Globals::Pointers::localPlayer);
		Cheat::Modules::Exclusive::Update(Globals::Pointers::localPlayer);
		if (Globals::Exclusive::spawnGiftExecute)
		{
			SDK::Game::GiftPackage* newGiftPackage = SDK::Game::GiftPackage::ctor();
			// default data required
			newGiftPackage->set_Id(SDK::System::Nullable::ctor(1));
			newGiftPackage->set_PlayerId(1);
			newGiftPackage->set_FromPlayerId(SDK::System::Nullable::ctor(1));
			newGiftPackage->set_GiftContext(Globals::Lists::giftContexList[Globals::Lists::selectedGiftContext].first);
			newGiftPackage->set_GiftRarity(Globals::Exclusive::selectedGiftRarity * 10);
			newGiftPackage->set_RawMessage("Thank you for using Luna! (https://discord.gg/Bv9fhQHe4Z)");
			newGiftPackage->set_Signature(OBFUSCATE("LUNA_SIGNATURE"));
			newGiftPackage->set_IsSignatureValid(true);
			newGiftPackage->set_Platform(-1);
			// parse data accordingly
			switch (Globals::Exclusive::selectedGiftConfig) {
			case 0:
				newGiftPackage->set_CurrencyType(Globals::Lists::currencyTypeList[Globals::Lists::selectedCurrencyType].first);
				newGiftPackage->set_Currency(Globals::Exclusive::currencyAmount);
				break; // Currency
			case 1:
				newGiftPackage->set_ConsumableItemDesc(Globals::Exclusive::consumableItemDesc.c_str());
				break; // Consumable
			case 2:
				newGiftPackage->set_EquipmentPrefabName(Globals::Exclusive::equipmentPrefabName.c_str());
				newGiftPackage->set_EquipmentModificationGuid(Globals::Exclusive::equipmentModificationGuid.c_str());
				break; // Skin
			case 3:
				newGiftPackage->set_AvatarItemType(SDK::System::Nullable::ctor(0));
				newGiftPackage->set_CustomAvatarItemId(SDK::System::Nullable::ctor(0));
				newGiftPackage->set_AvatarItemDescOrHairDyeDesc(Globals::Exclusive::avatarItemDescription.c_str());
				break; // Avatar
			}
			SDK::Game::GiftManager::SpawnGiftPackage(newGiftPackage);
			Globals::Exclusive::spawnGiftExecute = false;
		}
	}
}

void (*old_PlayerUpdate)(SDK::Game::Player* instance);
void PlayerUpdate(SDK::Game::Player* instance) {
	Cheat::Managers::Players.AddPlayer(instance);
	return old_PlayerUpdate(instance);
}

void (*old_PlayerOnDestroy)(SDK::Game::Player* instance);
void PlayerOnDestroy(SDK::Game::Player* instance) {
	Cheat::Managers::Players.RemovePlayer(instance);
	return old_PlayerOnDestroy(instance);
}

void NotifyServerCertificate() {}



struct VirtualInvokeData {
	void* methodPtr;
	Luma::IL2CPP::Structures::Il2CppMethod* method;
};


void LumaInitialize() {
	// init function runner
	auto functionRunnerMethod = Luma::IL2CPP::Structures::Il2CppClass::Get(
		OBFUSCATE("CodeStage.AntiCheat.Detectors"),
		OBFUSCATE("SpeedHackDetector"))
		->GetMethod(OBFUSCATE("Update"));
	*(void**)((uint64_t)functionRunnerMethod + Luma::IL2CPP::Structures::Il2CppMethod::MethodPtr::location) = &FunctionRunner;


	Luma::IL2CPP::Class LegacyTlsAuthentication = Luma::IL2CPP::Class(OBFUSCATE("Org.BouncyCastle.Crypto.Tls"), OBFUSCATE("LegacyTlsAuthentication"));
	uint16_t vtableCount = *(uint16_t*)((uint64_t)LegacyTlsAuthentication.GetPTR() + 0x142);
	auto vtable = (VirtualInvokeData*)((uint64_t)LegacyTlsAuthentication.GetPTR() + 0x160); // or 16LL - 0x10
	for (uint16_t i = 0; i < vtableCount; ++i) {
		if (!vtable[i].method) continue;
		if (strcmp(vtable[i].method->GetName(), OBFUSCATE("NotifyServerCertificate")) == 0)
			vtable[i].methodPtr = &NotifyServerCertificate;
	}

	// init luma's unity addon
	Luma::Unity::Initialize();

	// init sdk
	SDK::Initialize();

	// init player list & local player managers
	auto playerClass = Luma::IL2CPP::Class("", OBFUSCATE("Player"));
	auto updateMethod = playerClass.GetMethod(OBFUSCATE("Update"));
	auto destroyMethod = playerClass.GetMethod(OBFUSCATE("OnDestroy"));

	old_PlayerUpdate = (decltype(old_PlayerUpdate)) updateMethod->GetMethodPtr();
	*(void**)((uint64_t)updateMethod + Luma::IL2CPP::Structures::Il2CppMethod::MethodPtr::location) = &PlayerUpdate;

	old_PlayerOnDestroy = (decltype(old_PlayerOnDestroy)) destroyMethod->GetMethodPtr();
	*(void**)((uint64_t)destroyMethod + Luma::IL2CPP::Structures::Il2CppMethod::MethodPtr::location) = &PlayerOnDestroy;

	Console::Get().Log(clr::cyan, OBFUSCATE("[Luma][Initialize] Initialized Luma, have fun, make sure to support Mison Sere!"));
}


void Setup(HMODULE hMod) 
{
	Console::Create(OBFUSCATE("Luna <3 | @pillowguy._. & @PotatoIsCool & MisonSere"));
	Console::Get().Log(clr::yellow, OBFUSCATE("[Main][Setup] Welcome to Luna, created by @pillowguy._. & @PotatoIsCool"));

	if (requireAuthentication) {
		if (!isAuthenticated) {
			Console::Get().Log(clr::red, OBFUSCATE("[Main][Setup] User not authenticated, please contact in Discord server for assistance!"));
			Sleep(1500);
			std::exit(0);
		}
		Console::Get().Log(clr::green, OBFUSCATE("[Main][Setup] User is authenticated, enjoy the hookless nightmare of Luna!\n"));
		Console::Get().Log(clr::yellow, OBFUSCATE("Credits:"));
		{
			Console::Get().Log(clr::magenta, OBFUSCATE("\t- @pillowguy._. | Career: \"Professional onlyfans model & GPT skid\""));
			Console::Get().Log(clr::magenta, OBFUSCATE("\t- @PotatoIsCool | Career: \"Former Mison Sere secret agent\""));
			Console::Get().Log(clr::blue, OBFUSCATE("\t- @LuckyCharms | He approved our cheat, as I quote: \"This cheat is magically okay!\""));
			Console::Get().Log(clr::cyan, OBFUSCATE("\t- Luma Resolver (Our Custom UwU IL2CPP Resolver) | @pillowguy._. & @PotatoIsCool <3"));
			Console::Get().Log(clr::cyan, OBFUSCATE("\t- If you would like to receive updates, join our Discord server: https://discord.gg/Bv9fhQHe4Z"));
		}

		Console::Get().Log(clr::yellow, OBFUSCATE("\n[Main][Setup] Initializing Luma & Spawning GUI in....."));
		Luma::Dev::Invoker::SetSpoofStub(Luma::Dev::Memory::FindPattern(OBFUSCATE("UnityPlayer.dll"), OBFUSCATE("\xFF\x23"), OBFUSCATE("xx")));
		Sleep(1000);
		Luma::Loading::LumaOnEventCallback(LumaInitialize);
		std::thread(&GUI::Setup::Run, hMod, OBFUSCATE("Luna | [10/16/25] | @pillowguy._. & @PotatoIsCool | https://discord.gg/Bv9fhQHe4Z")).detach();

	} // AUTHENTICATED LOGIC ENDS HERE

	else {
		Console::Get().Log(clr::green, OBFUSCATE("[Main][Setup] User is logged in, auth mode is not currently active. Enjoy the hookless nightmare of Luna!\n"));
		Console::Get().Log(clr::yellow, OBFUSCATE("Credits:"));
		{
			Console::Get().Log(clr::magenta, OBFUSCATE("\t- @pillowguy._. | Career: \"Professional onlyfans model & GPT skid\""));
			Console::Get().Log(clr::magenta, OBFUSCATE("\t- @PotatoIsCool | Career: \"Former Mison Sere secret agent\""));
			Console::Get().Log(clr::blue, OBFUSCATE("\t- @LuckyCharms | He approved our cheat, as I quote: \"This cheat is magically okay!\""));
			Console::Get().Log(clr::cyan, OBFUSCATE("\t- Luma Resolver (Our Custom UwU IL2CPP Resolver) | @pillowguy._. & @PotatoIsCool <3"));
			Console::Get().Log(clr::cyan, OBFUSCATE("\t- If you would like to receive updates, join our Discord server: https://discord.gg/Bv9fhQHe4Z"));
		}
		
		Console::Get().Log(clr::yellow, OBFUSCATE("\n[Main][Setup] Initializing Luma & Spawning GUI in....."));
		Luma::Dev::Invoker::SetSpoofStub(Luma::Dev::Memory::FindPattern(OBFUSCATE("UnityPlayer.dll"), OBFUSCATE("\xFF\x23"), OBFUSCATE("xx")));
		Sleep(1000);
		Luma::Loading::LumaOnEventCallback(LumaInitialize);
		std::thread(&GUI::Setup::Run, hMod, OBFUSCATE("Luna | [10/16/25] | @pillowguy._. & @PotatoIsCool | https://discord.gg/Bv9fhQHe4Z")).detach();

	} // NON-AUTHENTICATED LOGIC ENDS HERE
}


BOOL APIENTRY DllMain(HMODULE hMod, UINT ulReason, LPVOID lpReserved) {
	switch (ulReason) {
	case DLL_PROCESS_ATTACH:
		std::thread(&Setup, hMod).detach();
		break;
	}
	return TRUE;
}