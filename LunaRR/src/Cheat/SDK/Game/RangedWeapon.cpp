/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "RangedWeapon.h"
#include "obf.h"

namespace SDK::Game {
	void RangedWeapon::Fire(float chargeAmount) { method_Fire[this].Invoke(chargeAmount); }
	void RangedWeapon::Fire(Luma::Unity::Vector3 velocity, float chargeAmount) { method_FireTwoParam[this].Invoke(velocity, chargeAmount); }

	void RangedWeapon::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecRoom.Core.Combat"), OBFUSCATE("RangedWeapon"));
		method_Fire = klass.GetMethod(OBFUSCATE("Fire"), 1);
		method_FireTwoParam = klass.GetMethod(OBFUSCATE("Fire"), 2);
	}

	Luma::IL2CPP::Class RangedWeapon::klass{};
	Luma::IL2CPP::Method<void> RangedWeapon::method_Fire{};
	Luma::IL2CPP::Method<void> RangedWeapon::method_FireTwoParam{};
}