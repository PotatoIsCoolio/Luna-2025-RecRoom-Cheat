/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <SDK/Unity/Empty/MonoBehaviour.h>

namespace SDK::Game {
	struct ScreenPlayerController;

	struct LocalPlayerController : Unity::MonoBehaviour {
	public:
		static ScreenPlayerController* get_ScreenPlayerControllerInstance();

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<ScreenPlayerController*> method_get_ScreenPlayerControllerInstance;
	};
}