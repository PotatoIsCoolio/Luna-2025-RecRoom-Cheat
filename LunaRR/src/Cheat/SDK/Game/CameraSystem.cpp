/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "CameraSystem.h"

namespace SDK::Game {
	// this field never changes, so don't worry about it.
	Luma::Unity::Quaternion CameraSystem::GetRotation() { return *(Luma::Unity::Quaternion*)((uint64_t)this + 0x98); }
	void CameraSystem::SetRotation(Luma::Unity::Quaternion value) { *(Luma::Unity::Quaternion*)((uint64_t)this + 0x98) = value; }
}