#include "visuals.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    bool  visFullbright = false;
    bool  visNightMode = false;
    bool  visNoFog = true;
    bool  visNoSky = false;
    bool  visWireframe = false;
    float visAmbient = 0.50f;
    float visSaturation = 1.f;
    float visBrightness = 1.f;
    int   visRenderMode = 0;

    bool  visChams = true;
    int   visChamsStyle = 0;
    bool  visChamsVisible = true;
    float visChamsVisibleColor[4] = { 0.20f, 0.55f, 0.90f, 1.f };
    bool  visChamsHidden = true;
    float visChamsHiddenColor[4] = { 0.90f, 0.30f, 0.30f, 1.f };
    bool  visChamsHiddenRainbow = false;
    float visChamsHiddenSpeed = 1.f;
    int   visChamsMaterial = 0;

    bool  visGlow = false;
    bool  visGlowColor = true;
    float visGlowColorRgba[4] = { 0.30f, 0.80f, 1.f, 1.f };
    float visGlowIntensity = 1.4f;
    int   visGlowStyle = 0;

    bool  visBloom = false;
    bool  visDof = false;
    bool  visVignette = false;
    bool  visMotionBlur = false;
    int   visEffectFov = 90;
}

namespace pages
{
    void RenderVisuals() noexcept
    {
        static const char* const renderItems[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const materialItems[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const glowStyleItems[] = { "option 1", "option 2", "option 3" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::Checkbox("checkbox 1", &vars::visFullbright);
            ksd::Checkbox("checkbox 2", &vars::visNightMode);
            ksd::Checkbox("checkbox 3", &vars::visNoFog);
            ksd::Checkbox("checkbox 4", &vars::visNoSky);
            ksd::Checkbox("checkbox 5", &vars::visWireframe);

            ksd::SeparatorText("separator");
            ksd::SliderFloat("float slider 1", &vars::visAmbient, 0.f, 1.f, "%.2f");
            ksd::SliderFloat("float slider 2", &vars::visSaturation, 0.f, 2.f);
            ksd::SliderFloat("float slider 3", &vars::visBrightness, 0.f, 2.f);
            ksd::Combo("combo", &vars::visRenderMode, renderItems, 4);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 0))
        {
            ksd::Checkbox("checkbox", &vars::visChams);
            ksd::Separator();
            ksd::Label("radio group");
            ksd::RadioButton("radio 1", &vars::visChamsStyle, 0);
            ksd::RadioButton("radio 2", &vars::visChamsStyle, 1);
            ksd::RadioButton("radio 3", &vars::visChamsStyle, 2);
            ksd::Separator();
            ksd::CheckboxColor("checkbox + color 1", &vars::visChamsVisible, "vis_chams_vis", vars::visChamsVisibleColor);
            ksd::CheckboxColor("checkbox + color 2", &vars::visChamsHidden, "vis_chams_hid", vars::visChamsHiddenColor, &vars::visChamsHiddenRainbow, &vars::visChamsHiddenSpeed);
            ksd::Combo("combo", &vars::visChamsMaterial, materialItems, 4);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 1))
        {
            ksd::Checkbox("checkbox", &vars::visGlow);
            ksd::CheckboxColor("checkbox + color", &vars::visGlowColor, "vis_glow_col", vars::visGlowColorRgba);
            ksd::SliderFloat("float slider", &vars::visGlowIntensity, 0.f, 5.f);
            ksd::Combo("combo", &vars::visGlowStyle, glowStyleItems, 3);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section D", 1))
        {
            ksd::Checkbox("checkbox 1", &vars::visBloom);
            ksd::Checkbox("checkbox 2", &vars::visDof);
            ksd::Checkbox("checkbox 3", &vars::visVignette);
            ksd::Checkbox("checkbox 4", &vars::visMotionBlur);
            ksd::SliderInt("int slider", &vars::visEffectFov, 70, 130);
        }
        ksd::EndGroup();
    }
}
