/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Camera.h"
#include "obf.h"

namespace SDK::Unity {
	Camera* Camera::get_current() { return method_get_current.Invoke().Get(); }

	Luma::Unity::Vector3 Camera::WorldToScreenPoint(Luma::Unity::Vector3 position) {
		auto screenPos = method_WorldToScreenPoint[this].Invoke(position).Get();
		return Luma::Unity::Vector3(screenPos.x, ImGui::GetIO().DisplaySize.y - screenPos.y, screenPos.z);
	}

	void Camera::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"));
		method_get_current = klass.GetMethod(OBFUSCATE("get_current"));
		method_WorldToScreenPoint = klass.GetMethod(OBFUSCATE("WorldToScreenPoint"), 1);
	}

	Luma::IL2CPP::Class Camera::klass{};
	Luma::IL2CPP::Method<Camera*> Camera::method_get_current{};
	Luma::IL2CPP::Method<Luma::Unity::Vector3> Camera::method_WorldToScreenPoint{};
}