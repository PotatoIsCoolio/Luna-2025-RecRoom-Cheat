/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Type.h"
#include "obf.h"


namespace SDK::System {

	Type* Type::GetType(const char* typeName) { return method_GetType.Invoke(Luma::IL2CPP::Structures::Il2CppString::New(typeName)).Get(); }

	void Type::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("System"), OBFUSCATE("Type"));
		method_GetType = klass.GetMethod(OBFUSCATE("GetType"), 1);
	}

	Luma::IL2CPP::Class Type::klass{};
	Luma::IL2CPP::Method<Type*> Type::method_GetType{};
}