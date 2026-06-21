/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "ScreenPlayerController.h"
#include "obf.h"

namespace SDK::Game {

	CameraSystem* ScreenPlayerController::get_CameraSystem() { return method_get_CameraSystem[this].Invoke().Get(); }

	void ScreenPlayerController::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecRoom"), OBFUSCATE("ScreenPlayerController"));
		method_get_CameraSystem = klass.GetMethod(OBFUSCATE("get_CameraSystem"));
	}

	Luma::IL2CPP::Class ScreenPlayerController::klass{};
	Luma::IL2CPP::Method<CameraSystem*> ScreenPlayerController::method_get_CameraSystem{};
}