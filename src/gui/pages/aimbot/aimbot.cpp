#include "aimbot.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    bool  aimEnabled = false;
    int   kbAimX = ImGuiKey_F;
    bool  aimSilent = false;
    bool  aimNoRecoil = true;
    bool  aimVisCheck = true;
    int   aimFov = 90;
    float aimSmoothing = 5.f;
    float aimRcsAmount = 65.f;
    int   aimTargetBone = 0;
    int   aimTargetMode = 3;
    int   aimKeyType = 0;

    bool  aimHitboxes[7] = { true, false, true, false, false, false, false };
    bool  aimAutoScale = true;
    int   aimMultipoint = 4;

    bool  espEnabled = true;
    bool  espBoxes = true;
    float espBoxColor[4] = { 0.86f, 0.20f, 0.20f, 1.f };
    bool  espNames = true;
    float espNameColor[4] = { 1.f, 1.f, 1.f, 1.f };
    bool  espHealth = true;
    float espHealthColor[4] = { 0.10f, 0.80f, 0.16f, 1.f };
    bool  espHealthRainbow = false;
    float espHealthSpeed = 1.f;
    bool  espArmor = false;
    float espArmorColor[4] = { 0.30f, 0.55f, 0.95f, 1.f };
    bool  espDistance = true;
    bool  espSkeleton = false;
    float espSkeletonColor[4] = { 1.f, 1.f, 1.f, 1.f };
    bool  espSnaplines = false;
    float espSnapColor[4] = { 0.95f, 0.90f, 0.30f, 1.f };
    int   espMaxDist = 392;
    int   espBoxStyle = 0;

    bool  aimPrediction = true;
    bool  aimFovCircle = true;
    bool  aimFovCircleShow = true;
    float aimFovCircleColor[4] = { 0.95f, 0.95f, 0.95f, 0.40f };
    int   aimPingSpike = 0;
}

namespace pages
{
    void RenderAimbot() noexcept
    {
        static const char* const boneItems[] = { "option 1", "option 2", "option 3", "option 4", "option 5" };
        static const char* const targetItems[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const keyTypeItems[] = { "option 1", "option 2", "option 3" };
        static const char* const hitboxItems[] = { "item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7" };
        static const char* const boxStyleItems[] = { "option 1", "option 2", "option 3", "option 4" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::CheckboxKeybind("checkbox + key", &vars::aimEnabled, "aim_enable_kb", &vars::kbAimX);
            ksd::Checkbox("checkbox 1", &vars::aimSilent);
            ksd::Checkbox("checkbox 2", &vars::aimNoRecoil);
            ksd::Checkbox("checkbox 3", &vars::aimVisCheck);
            ksd::Tooltip("sample tooltip");

            ksd::SeparatorText("separator");
            ksd::SliderInt("int slider 1", &vars::aimFov, 0, 180);
            ksd::SliderFloat("float slider 1", &vars::aimSmoothing, 0.f, 20.f);
            ksd::SliderFloat("float slider 2", &vars::aimRcsAmount, 0.f, 100.f, "%.0f%%");
            ksd::Combo("combo 1", &vars::aimTargetBone, boneItems, 5);
            ksd::Combo("combo 2", &vars::aimTargetMode, targetItems, 4);
            ksd::Combo("combo 3", &vars::aimKeyType, keyTypeItems, 3);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 0))
        {
            ksd::MultiCombo("multi-select", vars::aimHitboxes, hitboxItems, 7);
            ksd::Checkbox("checkbox", &vars::aimAutoScale);
            ksd::Tooltip("sample tooltip");
            ksd::SliderInt("int slider", &vars::aimMultipoint, 1, 8);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 1))
        {
            ksd::Checkbox("checkbox 1", &vars::espEnabled);
            ksd::CheckboxColor("checkbox + color 1", &vars::espBoxes, "esp_boxes", vars::espBoxColor);
            ksd::CheckboxColor("checkbox + color 2", &vars::espNames, "esp_name", vars::espNameColor);
            ksd::CheckboxColor("checkbox + color 3", &vars::espHealth, "esp_health", vars::espHealthColor, &vars::espHealthRainbow, &vars::espHealthSpeed);
            ksd::CheckboxColor("checkbox + color 4", &vars::espArmor, "esp_armor", vars::espArmorColor);
            ksd::Checkbox("checkbox 2", &vars::espDistance);
            ksd::CheckboxColor("checkbox + color 5", &vars::espSkeleton, "esp_skel", vars::espSkeletonColor);
            ksd::CheckboxColor("checkbox + color 6", &vars::espSnaplines, "esp_snap", vars::espSnapColor);
            ksd::SliderInt("int slider", &vars::espMaxDist, 0, 1000);
            ksd::Combo("combo", &vars::espBoxStyle, boxStyleItems, 4);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section D", 1))
        {
            if (ksd::TreeNode("tree node"))
            {
                ksd::Checkbox("checkbox 1", &vars::aimPrediction);
                ksd::Tooltip("sample tooltip");
                ksd::Checkbox("checkbox 2", &vars::aimFovCircle);
                ksd::CheckboxColor("checkbox + color", &vars::aimFovCircleShow, "aim_fov_col", vars::aimFovCircleColor);
                ksd::SliderInt("int slider", &vars::aimPingSpike, 0, 350);
                ksd::TreePop();
            }
        }
        ksd::EndGroup();
    }
}
