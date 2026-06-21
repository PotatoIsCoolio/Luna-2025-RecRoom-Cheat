/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "Empty/RRNetworkBehavior.h"

namespace SDK::Game {
	struct PlayerMovement : RRNetworkBehavior {
	public:
		void AddGravityDisabled(void* token);
		void RemoveGravityDisabled(void* token);
		void AddMaxWalkSpeed(float maxSpeed, void* token, int priority);
		void RemoveMaxWalkSpeed(void* token);
		void AddMaxJumpHeight(float maxHeight, void* token, int priority);
		void RemoveMaxJumpHeight(void* token);
		bool get_IsFlyingEnabled();
		void AddFlyEnabled(bool enabled, void* token, int priority);
		void RemoveFlyEnabled(void* token);
		void AddTeleportRestriction(void* token);
		void RemoveTeleportRestriction(void* token);
		void AddTeleportCooldown(float cooldown, void* token, int priority);
		void RemoveTeleportCooldown(void* token);
		void AddTeleportMaxHorizontalDistance(float maxHorizontalDistance, void* token, int priority);
		void RemoveTeleportMaxHorizontalDistance(void* token);
		void AddTeleportMaxHorizontalDistanceScalar(float scalar, void* token, int priority);
		void RemoveTeleportMaxHorizontalDistanceScalar(void* token);
		void AddTeleportMaxDropHeight(float maxDropHeight, void* token, int priority);
		void RemoveTeleportMaxDropHeight(void* token);
		void AddTeleportMaxHorizontalSurfaceAngle(float maxHorizontalSurfaceAngle, void* token, int priority);
		void RemoveTeleportMaxHorizontalSurfaceAngle(void* token);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<void> method_AddGravityDisabled;
		static Luma::IL2CPP::Method<void> method_RemoveGravityDisabled;
		static Luma::IL2CPP::Method<void> method_AddMaxWalkSpeed;
		static Luma::IL2CPP::Method<void> method_RemoveMaxWalkSpeed;
		static Luma::IL2CPP::Method<void> method_AddMaxJumpHeight;
		static Luma::IL2CPP::Method<void> method_RemoveMaxJumpHeight;
		static Luma::IL2CPP::Method<bool> method_get_IsFlyingEnabled;
		static Luma::IL2CPP::Method<void> method_AddFlyEnabled;
		static Luma::IL2CPP::Method<void> method_RemoveFlyEnabled;
		static Luma::IL2CPP::Method<void> method_AddTeleportRestriction;
		static Luma::IL2CPP::Method<void> method_RemoveTeleportRestriction;
		static Luma::IL2CPP::Method<void> method_AddTeleportCooldown;
		static Luma::IL2CPP::Method<void> method_RemoveTeleportCooldown;
		static Luma::IL2CPP::Method<void> method_AddTeleportMaxHorizontalDistance;
		static Luma::IL2CPP::Method<void> method_RemoveTeleportMaxHorizontalDistance;
		static Luma::IL2CPP::Method<void> method_AddTeleportMaxHorizontalDistanceScalar;
        static Luma::IL2CPP::Method<void> method_RemoveTeleportMaxHorizontalDistanceScalar;
        static Luma::IL2CPP::Method<void> method_AddTeleportMaxDropHeight;        
        static Luma::IL2CPP::Method<void> method_RemoveTeleportMaxDropHeight;
        static Luma::IL2CPP::Method<void> method_AddTeleportMaxHorizontalSurfaceAngle;
        static Luma::IL2CPP::Method<void> method_RemoveTeleportMaxHorizontalSurfaceAngle;
	};
}