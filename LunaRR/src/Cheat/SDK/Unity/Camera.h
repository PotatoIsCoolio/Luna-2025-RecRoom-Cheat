/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <imgui.h>
#include "Empty/Behaviour.h"

namespace SDK::Unity {
	struct Camera : Behaviour {
	public:
		static Camera* get_current();
		Luma::Unity::Vector3 WorldToScreenPoint(Luma::Unity::Vector3 position);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<Camera*> method_get_current;
		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_WorldToScreenPoint;
	};
}