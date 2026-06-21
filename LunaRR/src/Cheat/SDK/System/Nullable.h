/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <Luma.h>

namespace SDK::System {
	struct Nullable {
	public:
		template <typename T>
		static Nullable* ctor(T data) {
			return klass.NewInstanceRuntimeInvoke<Nullable*>(1, (void*)&data);
		}

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
	};
}