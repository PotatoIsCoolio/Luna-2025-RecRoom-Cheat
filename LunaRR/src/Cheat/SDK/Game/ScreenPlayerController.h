/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Luma.h>

namespace SDK::Game {
	struct CameraSystem;

	struct ScreenPlayerController {
	public:
		CameraSystem* get_CameraSystem();

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<CameraSystem*> method_get_CameraSystem;
	};
}