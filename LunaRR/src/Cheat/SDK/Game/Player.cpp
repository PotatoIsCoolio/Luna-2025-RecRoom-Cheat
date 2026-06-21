/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Player.h"
#include "obf.h"

namespace SDK::Game {
	Player* Player::get_LocalPlayer() { return method_get_LocalPlayer.Invoke().Get(); }
	int Player::get_PlayerIndex() { return method_get_PlayerIndex[this].Invoke().Get(); }
	float Player::get_RespawnDuration() { return method_get_RespawnDuration[this].Invoke().Get(); }
	float Player::get_DespawnDuration() { return method_get_DespawnDuration[this].Invoke().Get(); }
	AvatarSkeleton* Player::get_AvatarSkeleton() { return method_get_AvatarSkeleton[this].Invoke().Get(); }
	bool Player::get_UsesFullBodyAvatar() { return method_get_UsesFullBodyAvatar[this].Invoke().Get(); }
	PlayerMovement* Player::get_PlayerMovement() { return method_get_PlayerMovement[this].Invoke().Get(); }
	PlayerHead* Player::get_Head() { return method_get_Head[this].Invoke().Get(); }
	PlayerBody* Player::get_Body() { return method_get_Body[this].Invoke().Get(); }
	PlayerHand* Player::get_LeftHand() { return method_get_LeftHand[this].Invoke().Get(); }
	PlayerHand* Player::get_RightHand() { return method_get_RightHand[this].Invoke().Get(); }
	Luma::Mono::Array<Tool*>* Player::get_AllToolsHeld() { return method_get_AllToolsHeld[this].Invoke().Get(); }
	std::string Player::get_PlayerName() { return method_get_PlayerName[this].Invoke().Get()->get_String(); }
	void* Player::get_NetworkedPlayer() { return method_get_NetworkedPlayer[this].Invoke().Get(); }
	int Player::get_PlayerAccountId() { return method_get_PlayerAccountId[this].Invoke().Get(); }
	void Player::SetHeadScale(float newScaleFactor) { method_SetHeadScale[this].Invoke(newScaleFactor); }

	void Player::Setup() {
		klass = Luma::IL2CPP::Class("", OBFUSCATE("Player"));

		method_get_LocalPlayer = klass.GetMethod(OBFUSCATE("get_LocalPlayer"));
		method_get_PlayerIndex = klass.GetMethod(OBFUSCATE("get_PlayerIndex"));
		method_get_RespawnDuration = klass.GetMethod(OBFUSCATE("get_RespawnDuration"));
		method_get_DespawnDuration = klass.GetMethod(OBFUSCATE("get_DespawnDuration"));
		method_get_AvatarSkeleton = klass.GetMethod(OBFUSCATE("get_AvatarSkeleton"));
		method_get_PlayerMovement = klass.GetMethod(OBFUSCATE("get_PlayerMovement"));
		method_get_UsesFullBodyAvatar = klass.GetMethod(OBFUSCATE("get_UsesFullBodyAvatar"));
		method_get_Head = klass.GetMethod(OBFUSCATE("get_Head"));
		method_get_Body = klass.GetMethod(OBFUSCATE("get_Body"));
		method_get_LeftHand = klass.GetMethod(OBFUSCATE("get_LeftHand"));
		method_get_RightHand = klass.GetMethod(OBFUSCATE("get_RightHand"));
		method_get_AllToolsHeld = klass.GetMethod(OBFUSCATE("get_AllToolsHeld"));
		method_get_PlayerName = klass.GetMethod(OBFUSCATE("get_PlayerName"));
		method_get_NetworkedPlayer = klass.GetMethod(OBFUSCATE("get_NetworkedPlayer"));
		method_get_PlayerAccountId = klass.GetMethod(OBFUSCATE("get_PlayerAccountId"));
		method_SetHeadScale = klass.GetMethod(OBFUSCATE("SetHeadScale"), 1);
	}

	Luma::IL2CPP::Class Player::klass{};
	Luma::IL2CPP::Method<Player*> Player::method_get_LocalPlayer{};
	Luma::IL2CPP::Method<int> Player::method_get_PlayerIndex{};
	Luma::IL2CPP::Method<float> Player::method_get_RespawnDuration{};
	Luma::IL2CPP::Method<float> Player::method_get_DespawnDuration{};
	Luma::IL2CPP::Method<AvatarSkeleton*> Player::method_get_AvatarSkeleton{};
	Luma::IL2CPP::Method<bool> Player::method_get_UsesFullBodyAvatar{};
	Luma::IL2CPP::Method<PlayerMovement*> Player::method_get_PlayerMovement{};
	Luma::IL2CPP::Method<PlayerHead*> Player::method_get_Head{};
	Luma::IL2CPP::Method<PlayerBody*> Player::method_get_Body{};
	Luma::IL2CPP::Method<PlayerHand*> Player::method_get_LeftHand{};
	Luma::IL2CPP::Method<PlayerHand*> Player::method_get_RightHand{};
	Luma::IL2CPP::Method<Luma::Mono::Array<Tool*>*> Player::method_get_AllToolsHeld{};
	Luma::IL2CPP::Method<Luma::Mono::String*> Player::method_get_PlayerName{};
	Luma::IL2CPP::Method<void*> Player::method_get_NetworkedPlayer{};
	Luma::IL2CPP::Method<int> Player::method_get_PlayerAccountId{};
	Luma::IL2CPP::Method<void> Player::method_SetHeadScale{};
}