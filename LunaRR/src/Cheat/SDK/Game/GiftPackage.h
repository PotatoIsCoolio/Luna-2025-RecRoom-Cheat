/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "../System/Nullable.h"

namespace SDK::Game {
	struct GiftPackage {
	public:
		static GiftPackage* ctor();
		void set_Id(System::Nullable* value);
		void set_PlayerId(int value);
		void set_FromPlayerId(System::Nullable* value);
		void set_ConsumableItemDesc(const char* value);
		void set_AvatarItemType(System::Nullable* value);
		void set_AvatarItemDescOrHairDyeDesc(const char* value);
		void set_CustomAvatarItemId(System::Nullable* value);
		void set_EquipmentPrefabName(const char* value);
		void set_EquipmentModificationGuid(const char* value);
		void set_CurrencyType(int currencyType);
		void set_Currency(int value);
		void set_Xp(int value);
		void set_GiftContext(int value);
		void set_GiftRarity(int value);
		void set_RawMessage(const char* value);
		void set_Signature(const char* value);
		void set_IsSignatureValid(bool value);
		void set_Platform(int value);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		
		static Luma::IL2CPP::Method<void> method_set_Id;
		static Luma::IL2CPP::Method<void> method_set_PlayerId;
		static Luma::IL2CPP::Method<void> method_set_FromPlayerId;
		static Luma::IL2CPP::Method<void> method_set_ConsumableItemDesc;
		static Luma::IL2CPP::Method<void> method_set_AvatarItemType;
		static Luma::IL2CPP::Method<void> method_set_AvatarItemDescOrHairDyeDesc;
		static Luma::IL2CPP::Method<void> method_set_CustomAvatarItemId;
		static Luma::IL2CPP::Method<void> method_set_EquipmentPrefabName;
		static Luma::IL2CPP::Method<void> method_set_EquipmentModificationGuid;
		static Luma::IL2CPP::Method<void> method_set_CurrencyType;
		static Luma::IL2CPP::Method<void> method_set_Currency;
		static Luma::IL2CPP::Method<void> method_set_Xp;
		static Luma::IL2CPP::Method<void> method_set_GiftContext;
		static Luma::IL2CPP::Method<void> method_set_GiftRarity;
		static Luma::IL2CPP::Method<void> method_set_RawMessage;
		static Luma::IL2CPP::Method<void> method_set_Signature;
		static Luma::IL2CPP::Method<void> method_set_IsSignatureValid;
		static Luma::IL2CPP::Method<void> method_set_Platform;
	};
}