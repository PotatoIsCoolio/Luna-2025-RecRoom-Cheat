/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Luma.h>

namespace SDK::Unity {
	struct Object {
	public:
		std::string get_name();
		void Destroy();
		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<Luma::Mono::String*> method_get_name;
		static Luma::IL2CPP::Method<void> method_Destroy;
	};
}