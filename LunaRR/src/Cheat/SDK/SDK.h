/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
// Every class used in sdk is inherited by the following: 
#include <SDK/Game/Empty/RRNetworkBehavior.h> // Adds MonoBehaviour -> Behaviour -> Component

// Game
#include <SDK/Game/Player.h>
#include <SDK/Game/PlayerMovement.h>
#include <SDK/Game/PlayerGameRoleManager.h>
#include <SDK/Game/LocalPlayerController.h>
#include <SDK/Game/ScreenPlayerController.h>
#include <SDK/Game/CameraSystem.h>
#include <SDK/Game/RangedWeapon.h>
#include <SDK/Game/RRNetworking.h>
#include <SDK/Game/GiftManager.h>
#include <SDK/Game/GiftPackage.h>

// Unity
#include <SDK/Unity/Component.h> // Adds Object
#include <SDK/Unity/Transform.h>
#include <SDK/Unity/Camera.h>

// System
#include <SDK/System/Type.h>
#include <SDK/System/Nullable.h>

namespace SDK { extern void Initialize(); }