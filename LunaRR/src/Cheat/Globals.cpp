/*
ALL OWNERSHIP GOES TO @Pillowguy._. & PotatoIsCool
If you paid for this src you have been scammed.
https://github.com/PotatoIsCoolio
https://github.com/pillowman123
*/
#include "Globals.h"
#include "obf.h"

namespace Globals {

    namespace Exclusive {
        bool loopGrantMaster, assetSpawnWindow, giftSpawnWindow;

        // Asset Spawn Configuration
        bool spawnAssetExecute;
        int prefabAmount = 1;
        bool overrideScale, overrideVector, overrideQuaternion, noRender;
        Luma::Unity::Vector3 overridenVector, prefabScale;
        Luma::Unity::Quaternion overridenQuaternion;

        // Gift Spawn Configuration
        bool spawnGiftExecute;
        const char* giftRarityNames[5] = { OBFUSCATE("1 Star"), OBFUSCATE("2 Stars"), OBFUSCATE("3 Stars"), OBFUSCATE("4 Stars"), OBFUSCATE("5 Stars") };
        const char* giftConfigNames[4] = { OBFUSCATE("Currency"), OBFUSCATE("Consumable"), OBFUSCATE("Skin"), OBFUSCATE("Avatar (CURRENTLY BROKEN)") };
        int selectedGiftRarity, selectedGiftConfig;

        // Currency Configuration
        int currencyAmount = 999999999;

        // Consumable Config
        std::string consumableItemDesc;

        // Skin Config
        std::string equipmentPrefabName, equipmentModificationGuid;

        // Avatar Config
        std::string avatarItemDescription;
    }


    // Main Tab
    namespace Movement {
        bool loopFlyToggle, loopOverrideMovementSpeed, loopOverrideJumpHeight;
        float movementSpeed, jumpHeight;
    }

    namespace Misc {
        bool playerList;
        float headScale;
    }

    namespace Visual {
        bool enableEsp, lineEsp, skeletonEsp, boxEsp2D, boxEspFilled, boxEsp3D;
        // line config
        float lineThickness = 1.f;
        const char* linePositionNames[3] = { OBFUSCATE("Top"), OBFUSCATE("Center"), OBFUSCATE("Bottom") };
        std::vector<ImVec2> linePositions;
        int selectedLinePosition;
        float lineColor[4] = { 0.23f, 1.f, 1.f, 1.f };
        // skeleton config
        float skeletonColor[4] = { 0.23f, 1.f, 1.f, 1.f };
        // box config
        float boxThickness = 1.f;
        bool boxOutlines;
        float boxColor[4] = { 0.23f, 1.f, 1.f, 1.f };
    }

    namespace Aimbot {
        bool enableAimbot, renderFovCircle, loopFire, bulletSpeedModifier;
        float fovCircleRadius = 60.0f, strength, bulletSpeed;
        float fovCircleColor[4] = { 0.23f, 1.f, 1.f, 1.f };
        const char* bodyPartNames[2] = { OBFUSCATE("Head"), OBFUSCATE("Body") };
        const char* aimKeyNames[2] = { OBFUSCATE("Right Click"), OBFUSCATE("Side Mouse") };
        int selectedBodyPart, selectedAimKey;
    }

    namespace Pointers {
        SDK::Game::Player* localPlayer{};
    }
}