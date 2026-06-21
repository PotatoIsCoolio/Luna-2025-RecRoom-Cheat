/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "LocalPlayerController.h"
#include "obf.h"

namespace SDK::Game {

	ScreenPlayerController* LocalPlayerController::get_ScreenPlayerControllerInstance() { return method_get_ScreenPlayerControllerInstance.Invoke().Get(); }

	void LocalPlayerController::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("RecRoom"), OBFUSCATE("LocalPlayerController"));
		method_get_ScreenPlayerControllerInstance = klass.GetMethod(OBFUSCATE("get_ScreenPlayerControllerInstance"));
	}

	Luma::IL2CPP::Class LocalPlayerController::klass{};
	Luma::IL2CPP::Method<ScreenPlayerController*> LocalPlayerController::method_get_ScreenPlayerControllerInstance{};
}