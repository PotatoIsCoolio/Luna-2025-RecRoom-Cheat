/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Component.h"
#include "obf.h"

namespace SDK::Unity {
	Transform* Component::get_transform() { return method_get_transform[this].Invoke().Get(); }
	GameObject* Component::get_gameObject() { return method_get_gameObject[this].Invoke().Get(); }

	void Component::Setup() {
		klass = Luma::IL2CPP::Class(OBFUSCATE("UnityEngine"), OBFUSCATE("Component"));

		method_get_transform = klass.GetMethod(OBFUSCATE("get_transform"));
		method_get_gameObject = klass.GetMethod(OBFUSCATE("get_gameObject"));
		method_GetComponent = klass.GetMethod(OBFUSCATE("GetComponent"), 1);
		method_GetComponentInChildren = klass.GetMethod(OBFUSCATE("GetComponentInChildren"), 1);
		method_GetComponentsInChildren = klass.GetMethod(OBFUSCATE("GetComponentsInChildren"), 1);
		method_GetComponentInParent = klass.GetMethod(OBFUSCATE("GetComponentInParent"), 1);
		method_GetComponentsInParent = klass.GetMethod(OBFUSCATE("GetComponentsInParent"), 1);
		method_GetComponents = klass.GetMethod(OBFUSCATE("GetComponents"), 1);
	}

	Luma::IL2CPP::Class Component::klass{};
	Luma::IL2CPP::Method<Transform*> Component::method_get_transform{};
	Luma::IL2CPP::Method<GameObject*> Component::method_get_gameObject{};

	Luma::IL2CPP::Method<void*> Component::method_GetComponent{};
	Luma::IL2CPP::Method<void*> Component::method_GetComponentInChildren{};
	Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> Component::method_GetComponentsInChildren{};
	Luma::IL2CPP::Method<void*> Component::method_GetComponentInParent{};
	Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> Component::method_GetComponentsInParent{};
	Luma::IL2CPP::Method<Luma::Mono::Array<void*>*> Component::method_GetComponents{};
}