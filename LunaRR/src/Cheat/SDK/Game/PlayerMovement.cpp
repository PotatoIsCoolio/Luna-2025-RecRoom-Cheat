/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "PlayerMovement.h"
#include "obf.h"

namespace SDK::Game {
	void PlayerMovement::AddGravityDisabled(void* token) { method_AddGravityDisabled[this].Invoke(token); }
	void PlayerMovement::RemoveGravityDisabled(void* token) { method_RemoveGravityDisabled[this].Invoke(token); }
	void PlayerMovement::AddMaxWalkSpeed(float maxSpeed, void* token, int priority) { method_AddMaxWalkSpeed[this].Invoke(maxSpeed, token, priority); }
	void PlayerMovement::RemoveMaxWalkSpeed(void* token) { method_RemoveMaxWalkSpeed[this].Invoke(token); }
	void PlayerMovement::AddMaxJumpHeight(float maxHeight, void* token, int priority) { method_AddMaxJumpHeight[this].Invoke(maxHeight, token, priority); }
	void PlayerMovement::RemoveMaxJumpHeight(void* token) { method_RemoveMaxJumpHeight[this].Invoke(token); }
	bool PlayerMovement::get_IsFlyingEnabled() { return method_get_IsFlyingEnabled[this].Invoke().Get(); }
	void PlayerMovement::AddFlyEnabled(bool enabled, void* token, int priority) { method_AddFlyEnabled[this].Invoke(enabled, token, priority); }
	void PlayerMovement::RemoveFlyEnabled(void* token) { method_RemoveFlyEnabled[this].Invoke(token); }
	void PlayerMovement::AddTeleportRestriction(void* token) { method_AddTeleportRestriction[this].Invoke(token); }
	void PlayerMovement::RemoveTeleportRestriction(void* token) { method_RemoveTeleportRestriction[this].Invoke(token); }
	void PlayerMovement::AddTeleportCooldown(float cooldown, void* token, int priority) { method_AddTeleportCooldown[this].Invoke(cooldown, token, priority); }
	void PlayerMovement::RemoveTeleportCooldown(void* token) { method_RemoveTeleportCooldown[this].Invoke(token); }
	void PlayerMovement::AddTeleportMaxHorizontalDistance(float maxHorizontalDistance, void* token, int priority) { method_AddTeleportMaxHorizontalDistance[this].Invoke(maxHorizontalDistance, token, priority); }
	void PlayerMovement::RemoveTeleportMaxHorizontalDistance(void* token) { method_RemoveTeleportMaxHorizontalDistance[this].Invoke(token); }
	void PlayerMovement::AddTeleportMaxHorizontalDistanceScalar(float scalar, void* token, int priority) { method_AddTeleportMaxHorizontalDistanceScalar[this].Invoke(scalar, token, priority); }
	void PlayerMovement::RemoveTeleportMaxHorizontalDistanceScalar(void* token) { method_RemoveTeleportMaxHorizontalDistanceScalar[this].Invoke(token); }
	void PlayerMovement::AddTeleportMaxDropHeight(float maxDropHeight, void* token, int priority) { method_AddTeleportMaxDropHeight[this].Invoke(maxDropHeight, token, priority); }
	void PlayerMovement::RemoveTeleportMaxDropHeight(void* token) { method_RemoveTeleportMaxDropHeight[this].Invoke(token); }
	void PlayerMovement::AddTeleportMaxHorizontalSurfaceAngle(float maxHorizontalSurfaceAngle, void* token, int priority) { method_AddTeleportMaxHorizontalSurfaceAngle[this].Invoke(maxHorizontalSurfaceAngle, token, priority); }
	void PlayerMovement::RemoveTeleportMaxHorizontalSurfaceAngle(void* token) { method_RemoveTeleportMaxHorizontalSurfaceAngle[this].Invoke(token); }

	void PlayerMovement::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecRoom.Core.Locomotion"), OBFUSCATE("PlayerMovement"));

		method_AddGravityDisabled = klass.GetMethod(OBFUSCATE("AddGravityDisabled"), 1);
		method_RemoveGravityDisabled = klass.GetMethod(OBFUSCATE("RemoveGravityDisabled"), 1);
		method_AddMaxWalkSpeed = klass.GetMethod(OBFUSCATE("AddMaxWalkSpeed"), 3);
		method_RemoveMaxWalkSpeed = klass.GetMethod(OBFUSCATE("RemoveMaxWalkSpeed"), 1);
		method_AddMaxJumpHeight = klass.GetMethod(OBFUSCATE("AddMaxJumpHeight"), 3);
		method_RemoveMaxJumpHeight = klass.GetMethod(OBFUSCATE("RemoveMaxJumpHeight"), 1);
		method_get_IsFlyingEnabled = klass.GetMethod(OBFUSCATE("get_IsFlyingEnabled"));
		method_AddFlyEnabled = klass.GetMethod(OBFUSCATE("AddFlyEnabled"), 3);
		method_RemoveFlyEnabled = klass.GetMethod(OBFUSCATE("RemoveFlyEnabled"), 1);
		method_AddTeleportRestriction = klass.GetMethod(OBFUSCATE("AddTeleportRestriction"), 1);
		method_RemoveTeleportRestriction = klass.GetMethod(OBFUSCATE("RemoveTeleportRestriction"), 1);
		method_AddTeleportCooldown = klass.GetMethod(OBFUSCATE("AddTeleportCooldown"), 3);
		method_RemoveTeleportCooldown = klass.GetMethod(OBFUSCATE("RemoveTeleportCooldown"), 1);
		method_AddTeleportMaxHorizontalDistance = klass.GetMethod(OBFUSCATE("AddTeleportMaxHorizontalDistance"), 3);
		method_RemoveTeleportMaxHorizontalDistance = klass.GetMethod(OBFUSCATE("RemoveTeleportMaxHorizontalDistance"), 1);
		method_AddTeleportMaxHorizontalDistanceScalar = klass.GetMethod(OBFUSCATE("AddTeleportMaxHorizontalDistanceScalar"), 3);
		method_RemoveTeleportMaxHorizontalDistanceScalar = klass.GetMethod(OBFUSCATE("RemoveTeleportMaxHorizontalDistanceScalar"), 1);
		method_AddTeleportMaxDropHeight = klass.GetMethod(OBFUSCATE("AddTeleportMaxDropHeight"), 3);
		method_RemoveTeleportMaxDropHeight = klass.GetMethod(OBFUSCATE("RemoveTeleportMaxDropHeight"), 1);
		method_AddTeleportMaxHorizontalSurfaceAngle = klass.GetMethod(OBFUSCATE("AddTeleportMaxHorizontalSurfaceAngle"), 3);
		method_RemoveTeleportMaxHorizontalSurfaceAngle = klass.GetMethod(OBFUSCATE("RemoveTeleportMaxHorizontalSurfaceAngle"), 1);
	}

	Luma::IL2CPP::Class PlayerMovement::klass{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddGravityDisabled{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveGravityDisabled{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddMaxWalkSpeed{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveMaxWalkSpeed{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddMaxJumpHeight{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveMaxJumpHeight{};
	Luma::IL2CPP::Method<bool> PlayerMovement::method_get_IsFlyingEnabled{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddFlyEnabled{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveFlyEnabled{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportRestriction{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportRestriction{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportCooldown{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportCooldown{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportMaxHorizontalDistance{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportMaxHorizontalDistance{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportMaxHorizontalDistanceScalar{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportMaxHorizontalDistanceScalar{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportMaxDropHeight{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportMaxDropHeight{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_AddTeleportMaxHorizontalSurfaceAngle{};
	Luma::IL2CPP::Method<void> PlayerMovement::method_RemoveTeleportMaxHorizontalSurfaceAngle{};
}