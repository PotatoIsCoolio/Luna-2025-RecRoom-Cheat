/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Luma.h>

namespace SDK::Game {
	struct CameraSystem {
		Luma::Unity::Quaternion GetRotation();
		void SetRotation(Luma::Unity::Quaternion value);
	};
}