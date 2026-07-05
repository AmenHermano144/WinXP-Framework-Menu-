#include "world.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    bool  wldCustomSky = false;
    int   kbWldSky = ImGuiKey_None;
    bool  wldSkyTint = true;
    float wldSkyColor[4] = { 0.36f, 0.58f, 0.92f, 1.f };
    int   wldTimeOfDay = 1;
    float wldSunSize = 1.4f;
    bool  wldStars = false;
    float wldCloudDensity = 0.5f;

    bool  wldCustomFog = false;
    bool  wldFogTint = true;
    float wldFogColor[4] = { 0.62f, 0.66f, 0.70f, 1.f };
    bool  wldFogRainbow = false;
    float wldFogSpeed = 1.f;
    float wldFogDensity = 0.35f;
    int   wldGravity = 800;
    bool  wldWeather[5] = { true, false, false, false, false };
    bool  wldRemoveProps = false;
    bool  wldRemoveWater = false;

    float wldAmbient = 1.f;
    bool  wldShadows = true;
    bool  wldLightTint = false;
    float wldLightColor[4] = { 1.f, 0.95f, 0.85f, 1.f };
    int   wldLightMode = 0;

    bool  wldThirdPerson = false;
    int   wldFov = 90;
    float wldCameraDistance = 2.f;
    float wldCameraSmooth = 0.5f;
}

namespace pages
{
    void RenderWorld() noexcept
    {
        static const char* const timeItems[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const weatherItems[] = { "item 1", "item 2", "item 3", "item 4", "item 5" };
        static const char* const lightModes[] = { "option 1", "option 2", "option 3" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::CheckboxKeybind("checkbox + key", &vars::wldCustomSky, "wld_sky_kb", &vars::kbWldSky);
            ksd::CheckboxColor("checkbox + color", &vars::wldSkyTint, "wld_sky_col", vars::wldSkyColor);
            ksd::Combo("combo", &vars::wldTimeOfDay, timeItems, 4);
            ksd::SliderFloat("float slider 1", &vars::wldSunSize, 0.f, 5.f);
            ksd::SeparatorText("separator");
            ksd::Checkbox("checkbox", &vars::wldStars);
            ksd::SliderFloat("float slider 2", &vars::wldCloudDensity, 0.f, 1.f, "%.2f");
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 1))
        {
            ksd::Checkbox("checkbox 1", &vars::wldCustomFog);
            ksd::CheckboxColor("checkbox + color", &vars::wldFogTint, "wld_fog_col", vars::wldFogColor, &vars::wldFogRainbow, &vars::wldFogSpeed);
            ksd::SliderFloat("float slider", &vars::wldFogDensity, 0.f, 1.f, "%.2f");
            ksd::SpinInt("spin int", &vars::wldGravity, 0, 2000);
            ksd::MultiCombo("multi-select", vars::wldWeather, weatherItems, 5);
            ksd::Separator();
            ksd::Checkbox("checkbox 2", &vars::wldRemoveProps);
            ksd::Checkbox("checkbox 3", &vars::wldRemoveWater);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 0))
        {
            ksd::SliderFloat("float slider", &vars::wldAmbient, 0.f, 2.f, "%.2f");
            ksd::Checkbox("checkbox", &vars::wldShadows);
            ksd::CheckboxColor("checkbox + color", &vars::wldLightTint, "wld_light_col", vars::wldLightColor);
            ksd::Combo("combo", &vars::wldLightMode, lightModes, 3);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section D", 1))
        {
            ksd::Checkbox("checkbox", &vars::wldThirdPerson);
            ksd::SliderInt("int slider", &vars::wldFov, 70, 130);
            ksd::SliderFloat("float slider 1", &vars::wldCameraDistance, 0.f, 10.f, "%.2f");
            ksd::SliderFloat("float slider 2", &vars::wldCameraSmooth, 0.f, 1.f, "%.2f");
        }
        ksd::EndGroup();
    }
}
