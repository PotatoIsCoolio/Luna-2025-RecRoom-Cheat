/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "Component.h"

namespace SDK::Unity {
	struct Transform : Component {
	public:
		Luma::Unity::Vector3 get_position();
		void set_position(Luma::Unity::Vector3 value);

		Luma::Unity::Vector3 get_localPosition();
		void set_localPosition(Luma::Unity::Vector3 value);

		Luma::Unity::Vector3 get_eulerAngles();
		void set_eulerAngles(Luma::Unity::Vector3 value);

		Luma::Unity::Vector3 get_localEulerAngles();
		void set_localEulerAngles(Luma::Unity::Vector3 value);

		Luma::Unity::Vector3 get_forward();
		void set_forward(Luma::Unity::Vector3 value);

		Luma::Unity::Quaternion get_rotation();
		void set_rotation(Luma::Unity::Quaternion value);

		Luma::Unity::Quaternion get_localRotation();
		void set_localRotation(Luma::Unity::Quaternion value);

		Luma::Unity::Vector3 get_localScale();
		void set_localScale(Luma::Unity::Vector3 value);

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_position;
		static Luma::IL2CPP::Method<void> method_set_position;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_localPosition;
		static Luma::IL2CPP::Method<void> method_set_localPosition;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_eulerAngles;
		static Luma::IL2CPP::Method<void> method_set_eulerAngles;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_localEulerAngles;
		static Luma::IL2CPP::Method<void> method_set_localEulerAngles;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_forward;
		static Luma::IL2CPP::Method<void> method_set_forward;

		static Luma::IL2CPP::Method<Luma::Unity::Quaternion> method_get_rotation;
		static Luma::IL2CPP::Method<void> method_set_rotation;

		static Luma::IL2CPP::Method<Luma::Unity::Quaternion> method_get_localRotation;
		static Luma::IL2CPP::Method<void> method_set_localRotation;

		static Luma::IL2CPP::Method<Luma::Unity::Vector3> method_get_localScale;
		static Luma::IL2CPP::Method<void> method_set_localScale;
	};
}