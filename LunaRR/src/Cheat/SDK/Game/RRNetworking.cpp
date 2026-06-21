/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "RRNetworking.h"
#include "obf.h"

namespace SDK::Game {

	Unity::GameObject* RRNetworking::Instantiate(const char* prefabName, Luma::Unity::Vector3 position, Luma::Unity::Quaternion rotation, Luma::Unity::Vector3 scale, bool destroyOnLeave)
	{
		return method_Instantiate(Luma::IL2CPP::Structures::Il2CppString::New(prefabName), position, rotation, scale, nullptr, nullptr, destroyOnLeave);
	}

	bool RRNetworking::SetMasterClient(void* networkedPlayer)
	{
		return method_SetMasterClient.Invoke(networkedPlayer).Get();
	}

	void RRNetworking::Setup() {

		/*
		* Dll : RecRoom.Networking.Instantiation.Runtime
		* You can find Rec Rooms networking class through il2cpp/auto update despite obfuscated names quite easily
		* The module the class is contained in has few classes, and networking one has the most fields
		* It also has multiple functions that return GameObject which we'll use to find the class despite obfuscated name
		*/

		// cache this return type for later reference
		Luma::IL2CPP::Class Player = Luma::IL2CPP::Class(OBFUSCATE(""), OBFUSCATE("Player"));
		auto get_NetworkedPlayer = Player.GetMethod(OBFUSCATE("get_NetworkedPlayer"));
		auto networkedPlayerClass = get_NetworkedPlayer->GetReturnType()->GetClassOrElementClass();

		auto domain = Luma::IL2CPP::Structures::Il2CppDomain::Get();
		if (!domain) return;

		auto instantiationRuntime = domain->GetAssembly(OBFUSCATE("RecRoom.Networking.Instantiation.Runtime"));
		if (!instantiationRuntime->GetImage()) return;

		for (const auto& imageClass : instantiationRuntime->GetImage()->GetClasses()) {
			
			if (!imageClass) continue;
			auto methods = imageClass->GetMethods();
			
			for (int i = 0; i < methods.size(); ++i) {
				
				auto method = methods[i];
				if (!method) continue;
				
				if ((!klass.IsValid() && !method_Instantiate.IsValid()) 
				 && (method->GetParamCount() == 7)
				 && (imageClass->GetFieldCount() > 7)
				 && (strcmp(method->GetReturnType()->GetClassOrElementClass()->GetName(), OBFUSCATE("GameObject")) == 0))
				{
					klass = imageClass;
					method_Instantiate = method; // Instantiate function has seven arguments, simply exit the loop after finding one as such that returns GameObject.
				}
				if ((!method_SetMasterClient.IsValid()) 
				 && (method->GetParamCount() == 1) 
				 && (strcmp(method->GetReturnType()->GetClassOrElementClass()->GetName(), OBFUSCATE("Boolean")) == 0))
				{
					auto parameterReturnType = method->GetParam(0)->GetClassOrElementClass();
					if (strcmp(parameterReturnType->GetName(), networkedPlayerClass->GetName()) == 0)
					{
						method_SetMasterClient = method;
					}
				}
			}
		}
	}

	Luma::IL2CPP::Class RRNetworking::klass{};
	Luma::IL2CPP::Method<Unity::GameObject*> RRNetworking::method_Instantiate{};
	Luma::IL2CPP::Method<bool> RRNetworking::method_SetMasterClient{};
}