/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "SDK.h"

void SDK::Initialize() {
	Game::Player::Setup();
	Game::PlayerMovement::Setup();
	Game::PlayerGameRoleManager::Setup();
	Game::LocalPlayerController::Setup();
	Game::ScreenPlayerController::Setup();
	Game::RangedWeapon::Setup();
	Game::RRNetworking::Setup();
	Game::GiftManager::Setup();
	Game::GiftPackage::Setup();
	
	Unity::Component::Setup();
	Unity::Transform::Setup();
	Unity::Object::Setup();
	Unity::Camera::Setup();

	System::Type::Setup();
	System::Nullable::Setup();
}