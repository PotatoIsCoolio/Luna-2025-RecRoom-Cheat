/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "GiftPackage.h"
#include "obf.h"

namespace SDK::Game {

	GiftPackage* GiftPackage::ctor() { return klass.NewInstance<GiftPackage*>(); }
	void GiftPackage::set_Id(System::Nullable* value) { method_set_Id[this].Invoke(value); }
	void GiftPackage::set_PlayerId(int value) { method_set_PlayerId[this].Invoke(value); }
	void GiftPackage::set_FromPlayerId(System::Nullable* value) { method_set_FromPlayerId[this].Invoke(value); }
	void GiftPackage::set_ConsumableItemDesc(const char* value) { method_set_ConsumableItemDesc[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_AvatarItemType(System::Nullable* value) { method_set_AvatarItemType[this].Invoke(value); }
	void GiftPackage::set_AvatarItemDescOrHairDyeDesc(const char* value) { method_set_AvatarItemDescOrHairDyeDesc[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_CustomAvatarItemId(System::Nullable* value) { method_set_CustomAvatarItemId[this].Invoke(value); }
	void GiftPackage::set_EquipmentPrefabName(const char* value) { method_set_EquipmentPrefabName[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_EquipmentModificationGuid(const char* value) { method_set_EquipmentModificationGuid[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_CurrencyType(int currencyType) { method_set_CurrencyType[this].Invoke(currencyType); }
	void GiftPackage::set_Currency(int value) { method_set_Currency[this].Invoke(value); }
	void GiftPackage::set_Xp(int value) { method_set_Xp[this].Invoke(value); }
	void GiftPackage::set_GiftContext(int value) { method_set_GiftContext[this].Invoke(value); }
	void GiftPackage::set_GiftRarity(int value) { method_set_GiftRarity[this].Invoke(value); }
	void GiftPackage::set_RawMessage(const char* value) { method_set_RawMessage[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_Signature(const char* value) { method_set_Signature[this].Invoke(Luma::IL2CPP::Structures::Il2CppString::New(value)); }
	void GiftPackage::set_IsSignatureValid(bool value) { method_set_IsSignatureValid[this].Invoke(value); }
	void GiftPackage::set_Platform(int value) { method_set_Platform[this].Invoke(value); }



	void GiftPackage::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecNet"), OBFUSCATE("GiftPackage"));
		
		method_set_Id = klass.GetMethod(OBFUSCATE("set_Id"), 1);
		method_set_PlayerId = klass.GetMethod(OBFUSCATE("set_PlayerId"), 1);
		method_set_FromPlayerId = klass.GetMethod(OBFUSCATE("set_FromPlayerId"), 1);
		method_set_ConsumableItemDesc = klass.GetMethod(OBFUSCATE("set_ConsumableItemDesc"), 1);
		method_set_AvatarItemType = klass.GetMethod(OBFUSCATE("set_AvatarItemType"), 1);
		method_set_AvatarItemDescOrHairDyeDesc = klass.GetMethod(OBFUSCATE("set_AvatarItemDescOrHairDyeDesc"), 1);
		method_set_CustomAvatarItemId = klass.GetMethod(OBFUSCATE("set_CustomAvatarItemId"), 1);
		method_set_EquipmentPrefabName = klass.GetMethod(OBFUSCATE("set_EquipmentPrefabName"), 1);
		method_set_EquipmentModificationGuid = klass.GetMethod(OBFUSCATE("set_EquipmentModificationGuid"), 1);
		method_set_CurrencyType = klass.GetMethod(OBFUSCATE("set_CurrencyType"), 1);
		method_set_Currency = klass.GetMethod(OBFUSCATE("set_Currency"), 1);
		method_set_Xp = klass.GetMethod(OBFUSCATE("set_Xp"), 1);
		method_set_GiftContext = klass.GetMethod(OBFUSCATE("set_GiftContext"), 1);
		method_set_GiftRarity = klass.GetMethod(OBFUSCATE("set_GiftRarity"), 1);
		method_set_RawMessage = klass.GetMethod(OBFUSCATE("set_RawMessage"), 1);
		method_set_Signature = klass.GetMethod(OBFUSCATE("set_Signature"), 1);
		method_set_IsSignatureValid = klass.GetMethod(OBFUSCATE("set_IsSignatureValid"), 1);
		method_set_Platform = klass.GetMethod(OBFUSCATE("set_Platform"), 1);
	}

	Luma::IL2CPP::Class GiftPackage::klass{};

	Luma::IL2CPP::Method<void> GiftPackage::method_set_Id{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_PlayerId{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_FromPlayerId{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_ConsumableItemDesc{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_AvatarItemType{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_AvatarItemDescOrHairDyeDesc{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_CustomAvatarItemId{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_EquipmentPrefabName{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_EquipmentModificationGuid{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_CurrencyType{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_Currency{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_Xp{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_GiftContext{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_GiftRarity{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_RawMessage{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_Signature{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_IsSignatureValid{};
	Luma::IL2CPP::Method<void> GiftPackage::method_set_Platform{};
}