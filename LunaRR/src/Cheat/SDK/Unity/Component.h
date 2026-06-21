/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include "Object.h"
#include "../System/Type.h"

namespace SDK::Unity {
	struct Transform;
	struct GameObject;
	
	struct Component : Object {
	public:
		Transform* get_transform();
		GameObject* get_gameObject();

		template <typename T> T GetComponent(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (T)method_GetComponent[this].Invoke(type).Get();
		}

		template <typename T> T GetComponentInChildren(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (T)method_GetComponentInChildren[this].Invoke(type).Get();
		}

		template <typename T> Luma::Mono::Array<T>* GetComponentsInChildren(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (Luma::Mono::Array<T>*)method_GetComponentsInChildren[this].Invoke(type).Get();
		}

		template <typename T> T GetComponentInParent(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (T)method_GetComponentInParent[this].Invoke(type).Get();
		}

		template <typename T> Luma::Mono::Array<T>* GetComponentsInParent(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (Luma::Mono::Array<T>*)method_GetComponentsInParent[this].Invoke(type).Get();
		}

		template <typename T> Luma::Mono::Array<T>* GetComponents(const char* typeName) {
			auto type = System::Type::GetType(typeName);
			return (Luma::Mono::Array<T>*)method_GetComponents[this].Invoke(type).Get();
		}

		static void Setup();
	private:
		static Luma::IL2CPP::Class klass;
		static Luma::IL2CPP::Method<Transform*> method_get_transform;
		static Luma::IL2CPP::Method<GameObject*> method_get_gameObject;
		static Luma::IL2CPP::Method<void*> method_GetComponent;
		static Luma::IL2CPP::Method<void*> method_GetComponentInChildren;
		static Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> method_GetComponentsInChildren;
		static Luma::IL2CPP::Method<void*> method_GetComponentInParent;
		static Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> method_GetComponentsInParent;
		static Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> method_GetComponents;
	};
}