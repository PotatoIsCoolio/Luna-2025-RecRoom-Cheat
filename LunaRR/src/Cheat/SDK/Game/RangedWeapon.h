/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "Empty/RRNetworkBehavior.h"

namespace SDK::Game {
	struct RangedWeapon : RRNetworkBehavior {
	public:
		void Fire(float chargeAmount);
		void Fire(Luma::Unity::Vector3 velocity, float chargeAmount);
		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<void> method_Fire;
		static Luma::IL2CPP::Method<void> method_FireTwoParam;
	};
}