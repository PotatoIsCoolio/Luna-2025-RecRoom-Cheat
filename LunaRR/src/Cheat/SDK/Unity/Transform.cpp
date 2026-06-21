/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Transform.h"
#include "obf.h"

namespace SDK::Unity {
	
	Luma::Unity::Vector3 Transform::get_position() { return method_get_position[this].Invoke().Get(); }
	void Transform::set_position(Luma::Unity::Vector3 value) { method_set_position[this].Invoke(value); }

	Luma::Unity::Vector3 Transform::get_localPosition() { return method_get_localPosition[this].Invoke().Get(); }
	void Transform::set_localPosition(Luma::Unity::Vector3 value) { method_set_localPosition[this].Invoke(value); }

	Luma::Unity::Vector3 Transform::get_eulerAngles() { return method_get_eulerAngles[this].Invoke().Get(); }
	void Transform::set_eulerAngles(Luma::Unity::Vector3 value) { method_set_eulerAngles[this].Invoke(value); }

	Luma::Unity::Vector3 Transform::get_localEulerAngles() { return method_get_localEulerAngles[this].Invoke().Get(); }
	void Transform::set_localEulerAngles(Luma::Unity::Vector3 value) { method_set_localEulerAngles[this].Invoke(value); }

	Luma::Unity::Vector3 Transform::get_forward() { return method_get_forward[this].Invoke().Get(); }
	void Transform::set_forward(Luma::Unity::Vector3 value) { method_set_forward[this].Invoke(value); }

	Luma::Unity::Quaternion Transform::get_rotation() { return method_get_rotation[this].Invoke().Get(); }
	void Transform::set_rotation(Luma::Unity::Quaternion value) { method_set_rotation[this].Invoke(value); }

	Luma::Unity::Quaternion Transform::get_localRotation() { return method_get_localRotation[this].Invoke().Get(); }
	void Transform::set_localRotation(Luma::Unity::Quaternion value) { method_set_localRotation[this].Invoke(value); }

	Luma::Unity::Vector3 Transform::get_localScale() { return method_get_localScale[this].Invoke().Get(); }
	void Transform::set_localScale(Luma::Unity::Vector3 value) { method_set_localScale[this].Invoke(value); }

	void Transform::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"));

		method_get_position = klass.GetMethod(OBFUSCATE("get_position"));
		method_set_position = klass.GetMethod(OBFUSCATE("set_position"), 1);

		method_get_localPosition = klass.GetMethod(OBFUSCATE("get_localPosition"));
		method_set_localPosition = klass.GetMethod(OBFUSCATE("set_localPosition"), 1);

		method_get_eulerAngles = klass.GetMethod(OBFUSCATE("get_eulerAngles"));
		method_set_eulerAngles = klass.GetMethod(OBFUSCATE("set_eulerAngles"), 1);

		method_get_localEulerAngles = klass.GetMethod(OBFUSCATE("get_localEulerAngles"));
		method_set_localEulerAngles = klass.GetMethod(OBFUSCATE("set_localEulerAngles"), 1);

		method_get_forward = klass.GetMethod(OBFUSCATE("get_forward"));
		method_set_forward = klass.GetMethod(OBFUSCATE("set_forward"), 1);

		method_get_rotation = klass.GetMethod(OBFUSCATE("get_rotation"));
		method_set_rotation = klass.GetMethod(OBFUSCATE("set_rotation"), 1);

		method_get_localRotation = klass.GetMethod(OBFUSCATE("get_localRotation"));
		method_set_localRotation = klass.GetMethod(OBFUSCATE("set_localRotation"), 1);

		method_get_localScale = klass.GetMethod(OBFUSCATE("get_localScale"));
		method_set_localScale = klass.GetMethod(OBFUSCATE("set_localScale"), 1);
	}

	Luma::IL2CPP::Class Transform::klass{};
	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_position{};
	Luma::IL2CPP::Method<void> Transform::method_set_position{};

	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_localPosition{};
	Luma::IL2CPP::Method<void> Transform::method_set_localPosition{};

	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_eulerAngles{};
	Luma::IL2CPP::Method<void> Transform::method_set_eulerAngles{};

	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_localEulerAngles{};
	Luma::IL2CPP::Method<void> Transform::method_set_localEulerAngles{};

	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_forward{};
	Luma::IL2CPP::Method<void> Transform::method_set_forward{};

	Luma::IL2CPP::Method<Luma::Unity::Quaternion> Transform::method_get_rotation{};
	Luma::IL2CPP::Method<void> Transform::method_set_rotation{};

	Luma::IL2CPP::Method<Luma::Unity::Quaternion> Transform::method_get_localRotation{};
	Luma::IL2CPP::Method<void> Transform::method_set_localRotation{};

	Luma::IL2CPP::Method<Luma::Unity::Vector3> Transform::method_get_localScale{};
	Luma::IL2CPP::Method<void> Transform::method_set_localScale{};
}