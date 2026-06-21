/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Nullable.h"

namespace SDK::System {

	void Nullable::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("System"), OBFUSCATE("Nullable`1"));
	}

	Luma::IL2CPP::Class Nullable::klass;
}