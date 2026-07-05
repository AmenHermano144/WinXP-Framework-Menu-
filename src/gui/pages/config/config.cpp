#include "config.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    bool  xhairEnable = false;
    float xhairColor[4] = { 1.f, 1.f, 1.f, 1.f };
    float xhairOutline[4] = { 0.f, 0.f, 0.f, 1.f };
    float xhairSize = 4.f;
    float xhairGap = 2.f;
    float xhairThickness = 1.f;
    float xhairOutlineThickness = 1.f;
    int   xhairStyle = 0;
    bool  xhairCenterDot = true;
    bool  xhairShowEnemy = false;

    bool  ovWatermark = true;
    bool  ovShowFps = true;
    bool  ovShowPing = false;
    bool  ovKeybindList = false;
    bool  ovHitmarker = false;
    float ovHmColor[4] = { 1.f, 1.f, 1.f, 1.f };
    int   ovHmSound = 0;
    float ovHmSize = 5.f;

    bool  cfgAccentOn = true;
    float cfgAccent[4] = { 0.f, 0.f, 0.5f, 1.f };
    bool  cfgAccentRainbow = false;
    float cfgAccentSpeed = 1.f;
    int   cfgTheme = 0;
    float cfgMenuScale = 1.f;
    float cfgBackgroundAlpha = 0.9f;

    char  cfgProfile[32] = "sample text";
    int   cfgQuality = 1;
    int   cfgThreads = 4;
    bool  cfgVerboseLogging = false;
    bool  cfgSafeMode = true;
    bool  cfgAutoSave = true;
}

namespace pages
{
    void RenderConfig() noexcept
    {
        static const char* const comboA[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const comboB[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const comboC[] = { "option 1", "option 2", "option 3", "option 4", "option 5" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            const ImVec2 row = ksd::CursorPos();
            ksd::Checkbox("checkbox 1", &vars::xhairEnable);
            ksd::ColorButton("xhair_fill", vars::xhairColor,
                ImVec2(ksd::PanelRightX() - style::SwatchW * 2.f - 2.f, row.y), ImVec2(style::SwatchW, style::SwatchH));
            ksd::ColorButton("xhair_outline", vars::xhairOutline,
                ImVec2(ksd::PanelRightX() - style::SwatchW, row.y), ImVec2(style::SwatchW, style::SwatchH));

            ksd::SliderFloat("float slider 1", &vars::xhairSize, 0.f, 10.f);
            ksd::SliderFloat("float slider 2", &vars::xhairGap, 0.f, 10.f);
            ksd::SliderFloat("float slider 3", &vars::xhairThickness, 0.f, 10.f);
            ksd::SliderFloat("float slider 4", &vars::xhairOutlineThickness, 0.f, 10.f);

            ksd::Combo("combo", &vars::xhairStyle, comboA, 4);
            ksd::Checkbox("checkbox 2", &vars::xhairCenterDot);
            ksd::Checkbox("checkbox 3", &vars::xhairShowEnemy);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 1))
        {
            ksd::Checkbox("checkbox 1", &vars::ovWatermark);
            ksd::Checkbox("checkbox 2", &vars::ovShowFps);
            ksd::Checkbox("checkbox 3", &vars::ovShowPing);
            ksd::Checkbox("checkbox 4", &vars::ovKeybindList);

            const ImVec2 row = ksd::CursorPos();
            ksd::Checkbox("checkbox 5", &vars::ovHitmarker);
            ksd::ColorButton("ov_hm", vars::ovHmColor,
                ImVec2(ksd::PanelRightX() - style::SwatchW, row.y), ImVec2(style::SwatchW, style::SwatchH));

            ksd::Combo("combo", &vars::ovHmSound, comboB, 4);
            ksd::SliderFloat("float slider", &vars::ovHmSize, 0.f, 10.f);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 1))
        {
            ksd::CheckboxColor("checkbox + color", &vars::cfgAccentOn, "cfg_accent", vars::cfgAccent,
                &vars::cfgAccentRainbow, &vars::cfgAccentSpeed);

            ksd::Label("combo label");
            ksd::Combo("combo", &vars::cfgTheme, comboC, 5);
            ksd::SliderFloat("float slider 1", &vars::cfgMenuScale, 0.5f, 2.0f);
            ksd::SliderFloat("float slider 2", &vars::cfgBackgroundAlpha, 0.f, 1.f);
        }
        ksd::EndGroup();

        ksd::SetAccent(vars::cfgAccent, vars::cfgAccentOn);

        if (ksd::BeginGroup("Section D", 0))
        {
            ksd::SeparatorText("separator 1");
            ksd::InputText("cfg_name", vars::cfgProfile, (int)sizeof(vars::cfgProfile));

            ksd::SeparatorText("separator 2");
            ksd::RadioButton("radio 1", &vars::cfgQuality, 0);
            ksd::RadioButton("radio 2", &vars::cfgQuality, 1);
            ksd::RadioButton("radio 3", &vars::cfgQuality, 2);

            ksd::SpinInt("spin int", &vars::cfgThreads, 1, 16);

            if (ksd::TreeNode("tree node"))
            {
                ksd::Checkbox("checkbox 1", &vars::cfgVerboseLogging);
                ksd::Checkbox("checkbox 2", &vars::cfgSafeMode);
                ksd::Checkbox("checkbox 3", &vars::cfgAutoSave);
                ksd::TreePop();
            }

            ksd::Label("progress bar");
            ksd::ProgressBar(0.65f);

            const float w = ksd::ContentWidth();
            ksd::Button("button 1", w);
            ksd::Button("button 2", w);
            if (ksd::Button("button 3", w))
            {
                ksd::OpenMessageBox("cfg_reset", "Confirm", "Sample confirmation dialog?");
            }

            ksd::Hyperlink("hyperlink");
        }
        ksd::EndGroup();

        if (ksd::MessageBoxResult("cfg_reset") == 1)
        {
            vars::xhairSize = 4.f;
            vars::xhairGap = 2.f;
        }
    }
}
