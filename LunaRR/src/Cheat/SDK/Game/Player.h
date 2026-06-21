/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Luma.h>
#include "Empty/PlayerHead.h"
#include "Empty/PlayerBody.h"
#include "Empty/PlayerHand.h"
#include "Empty/Tool.h"

namespace SDK::Game {
	struct AvatarSkeleton;
	struct PlayerMovement;

	struct Player : RRNetworkBehavior {
	public:
		static Player* get_LocalPlayer();
		int get_PlayerIndex();
		float get_RespawnDuration();
		float get_DespawnDuration();
		AvatarSkeleton* get_AvatarSkeleton();
		bool get_UsesFullBodyAvatar();
		PlayerMovement* get_PlayerMovement();
		PlayerHead* get_Head();
		PlayerBody* get_Body();
		PlayerHand* get_LeftHand();
		PlayerHand* get_RightHand();
		Luma::Mono::Array<Tool*>* get_AllToolsHeld();
		std::string get_PlayerName();
		void* get_NetworkedPlayer();
		int get_PlayerAccountId();
		void SetHeadScale(float newScaleFactor);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<Player*> method_get_LocalPlayer;
		static Luma::IL2CPP::Method<int> method_get_PlayerIndex;
		static Luma::IL2CPP::Method<float> method_get_RespawnDuration;
		static Luma::IL2CPP::Method<float> method_get_DespawnDuration;
		static Luma::IL2CPP::Method<AvatarSkeleton*> method_get_AvatarSkeleton;
		static Luma::IL2CPP::Method<bool> method_get_UsesFullBodyAvatar;
		static Luma::IL2CPP::Method<PlayerMovement*> method_get_PlayerMovement;
		static Luma::IL2CPP::Method<PlayerHead*> method_get_Head;
		static Luma::IL2CPP::Method<PlayerBody*> method_get_Body;
		static Luma::IL2CPP::Method<PlayerHand*> method_get_LeftHand;
		static Luma::IL2CPP::Method<PlayerHand*> method_get_RightHand;
		static Luma::IL2CPP::Method<Luma::Mono::Array<Tool*>*> method_get_AllToolsHeld;
		static Luma::IL2CPP::Method<Luma::Mono::String*> method_get_PlayerName;
		static Luma::IL2CPP::Method<void*> method_get_NetworkedPlayer;
		static Luma::IL2CPP::Method<int> method_get_PlayerAccountId;
		static Luma::IL2CPP::Method<void> method_SetHeadScale;
	};
}