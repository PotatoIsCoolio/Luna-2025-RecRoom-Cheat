/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Object.h"
#include "obf.h"

namespace SDK::Unity {
	std::string Object::get_name() { return method_get_name[this].Invoke().Get()->get_String(); }
	void Object::Destroy() { method_Destroy.Invoke(this); }

	void Object::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("UnityEngine"), OBFUSCATE("Object"));

		method_get_name = klass.GetMethod(OBFUSCATE("get_name"));
		method_Destroy = klass.GetMethod(OBFUSCATE("Destroy"), 1);
	}

	Luma::IL2CPP::Class Object::klass{};
	Luma::IL2CPP::Method<Luma::Mono::String*> Object::method_get_name{};
	Luma::IL2CPP::Method<void> Object::method_Destroy{};
}