/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#pragma once
#include <vector>
#include <imgui.h>
#include <SDK/SDK.h>

namespace Globals {
    namespace Exclusive {
        extern bool loopGrantMaster, assetSpawnWindow, giftSpawnWindow;
        
        // Asset Spawn Configuration
        extern bool spawnAssetExecute;
        extern int prefabAmount;
        extern bool overrideScale, overrideVector, overrideQuaternion, noRender;
        extern Luma::Unity::Vector3 overridenVector, prefabScale;
        extern Luma::Unity::Quaternion overridenQuaternion;

        // Gift Spawn Configuration
        extern bool spawnGiftExecute;
        extern const char* giftRarityNames[5];
        extern const char* giftConfigNames[4];
        extern int selectedGiftRarity, selectedGiftConfig;

        // Currency Configuration
        extern int currencyAmount;

        // Consumable Config
        extern std::string consumableItemDesc;

        // Skin Config
        extern std::string equipmentPrefabName, equipmentModificationGuid;

        // Avatar Config
        extern std::string avatarItemDescription;
    }

    // Movement Tab
    namespace Movement {
        extern bool loopFlyToggle, loopOverrideMovementSpeed, loopOverrideJumpHeight;
        extern float movementSpeed, jumpHeight;
    }

    namespace Misc {
        extern bool playerList;
        extern float headScale;
    }

    namespace Visual {
        extern bool enableEsp, lineEsp, skeletonEsp, boxEsp2D, boxEspFilled, boxEsp3D;
        // line config
        extern float lineThickness;
        extern const char* linePositionNames[3];
        extern std::vector<ImVec2> linePositions;
        extern int selectedLinePosition;
        extern float lineColor[4];
        // skeleton config
        extern float skeletonColor[4];
        // box config
        extern float boxThickness;
        extern bool boxOutlines;
        extern float boxColor[4];
    }

    namespace Aimbot {
        extern bool enableAimbot, renderFovCircle, loopFire, bulletSpeedModifier;
        extern float fovCircleRadius, strength, bulletSpeed;
        extern float fovCircleColor[4];
        extern const char* bodyPartNames[2];
        extern const char* aimKeyNames[2];
        extern int selectedBodyPart, selectedAimKey;
    }

    namespace Pointers {
        extern SDK::Game::Player* localPlayer;
    }
}