/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "../Unity/GameObject.h"

namespace SDK::Game {
	struct RRNetworking {
	public:
		//public static GameObject IDJQWSIAXYJ(String a, Vector3 b, Quaternion c, Vector3 d, ViewId e, CreationInstantiationParameters f) { }
		static Unity::GameObject* Instantiate(const char* prefabName, Luma::Unity::Vector3 position, Luma::Unity::Quaternion rotation, Luma::Unity::Vector3 scale, bool destroyOnLeave);
		static bool SetMasterClient(void* networkedPlayer);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<Unity::GameObject*> method_Instantiate;
		static Luma::IL2CPP::Method<bool> method_SetMasterClient;
	};
}