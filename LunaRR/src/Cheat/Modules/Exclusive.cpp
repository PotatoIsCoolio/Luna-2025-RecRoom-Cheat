/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Exclusive.h"

/*namespace Cheat::Modules::Exclusive {
	extern void AssetSpawn();
	extern bool LoopMaster();
	extern void Update();
}*/

void Cheat::Modules::Exclusive::AssetSpawn(SDK::Game::Player* player) {
	if (!player) return;
	
	auto headTransform = player->get_Head()->get_transform();
	if (!headTransform) return;

	// give user master client before instantiating to be safe
	GrantMaster(player);

	// default instantiate vars
	Luma::Unity::Vector3 prefabPosition = (headTransform->get_position() + headTransform->get_forward());
	Luma::Unity::Quaternion prefabRotation = Luma::Unity::Quaternion::Identity();
	Luma::Unity::Vector3 prefabScale = Luma::Unity::Vector3(1.f);

	// dynamic customized vars
	const char* prefabName = Globals::Lists::prefabList[Globals::Lists::selectedPrefab].c_str();
	Luma::Unity::Vector3 position = (Globals::Exclusive::overrideVector) ? Globals::Exclusive::overridenVector : prefabPosition;
	Luma::Unity::Quaternion rotation = (Globals::Exclusive::overrideQuaternion) ? Globals::Exclusive::overridenQuaternion : prefabRotation;
	Luma::Unity::Vector3 scale = (Globals::Exclusive::overrideScale) ? Globals::Exclusive::prefabScale : prefabScale;

	for (int i = 0; i < Globals::Exclusive::prefabAmount; i++) {
		auto prefab = SDK::Game::RRNetworking::Instantiate(prefabName, position, rotation, scale, false);
		if (Globals::Exclusive::noRender) prefab->Destroy();
	}
}

bool Cheat::Modules::Exclusive::GrantMaster(SDK::Game::Player* player) {
	if (!player) return false;
	auto networkedPlayer = player->get_NetworkedPlayer();
	if (!networkedPlayer) return false;

	return SDK::Game::RRNetworking::SetMasterClient(networkedPlayer);
}

void Cheat::Modules::Exclusive::Update(SDK::Game::Player* player) {
	if (Globals::Exclusive::loopGrantMaster)
		GrantMaster(player);


	if (Globals::Exclusive::spawnAssetExecute) {
		AssetSpawn(player);
		Globals::Exclusive::spawnAssetExecute = false;
	}
}

