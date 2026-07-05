#include "misc.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    bool  miscBhop = false;
    int   mscKeyBhop = ImGuiKey_Space;
    bool  miscAutoStrafe = false;
    int   mscKeyAutoStrafe = ImGuiKey_None;
    bool  miscEdgeJump = false;
    int   mscKeyEdgeJump = ImGuiKey_None;
    bool  miscFastStop = true;
    bool  miscAutoJump = false;
    float miscAirSpeed = 1.f;
    float miscAirStrafe = 1.f;
    int   miscJumpMode = 0;

    bool  miscFly = false;
    int   mscKeyFly = ImGuiKey_F;
    bool  miscNoclip = false;
    int   mscKeyNoclip = ImGuiKey_N;
    bool  miscAntiAim = false;
    int   miscFakeLag = 0;
    float miscDesync = 0.f;
    bool  miscJitter = false;
    int   miscJitterRange = 30;
    int   miscRoll = 0;

    float miscAnimSpeed = 4.f;
    bool  miscWatermark = true;
    bool  miscShowFps = true;
    bool  miscBlur = true;
    int   miscTheme = 0;
    int   mscPanicKey = ImGuiKey_Delete;
    float miscSessionXp = 0.42f;
}

namespace pages
{
    void RenderMisc() noexcept
    {
        static const char* const comboA[] = { "option 1", "option 2", "option 3" };
        static const char* const comboB[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const comboC[] = { "option 1", "option 2", "option 3", "option 4" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::CheckboxKeybind("checkbox + key 1", &vars::miscBhop, "msc_bhop", &vars::mscKeyBhop);
            ksd::CheckboxKeybind("checkbox + key 2", &vars::miscAutoStrafe, "msc_strafe", &vars::mscKeyAutoStrafe);
            ksd::CheckboxKeybind("checkbox + key 3", &vars::miscEdgeJump, "msc_edge", &vars::mscKeyEdgeJump);
            ksd::Checkbox("checkbox 1", &vars::miscFastStop);
            ksd::Checkbox("checkbox 2", &vars::miscAutoJump);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 0))
        {
            ksd::SliderFloat("float slider 1", &vars::miscAirSpeed, 0.f, 5.f, "%.2f");
            ksd::SliderFloat("float slider 2", &vars::miscAirStrafe, 0.f, 5.f, "%.2f");
            ksd::Combo("combo", &vars::miscJumpMode, comboA, 3);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 0))
        {
            ksd::CheckboxKeybind("checkbox + key 1", &vars::miscFly, "msc_fly", &vars::mscKeyFly);
            ksd::CheckboxKeybind("checkbox + key 2", &vars::miscNoclip, "msc_noclip", &vars::mscKeyNoclip);
            ksd::Checkbox("checkbox", &vars::miscAntiAim);
            ksd::SliderInt("int slider 1", &vars::miscFakeLag, 0, 16);
            ksd::SliderFloat("float slider", &vars::miscDesync, 0.f, 60.f);

            if (ksd::TreeNode("tree node"))
            {
                ksd::Checkbox("checkbox", &vars::miscJitter);
                ksd::SliderInt("int slider", &vars::miscJitterRange, 0, 180);
                ksd::Combo("combo", &vars::miscRoll, comboB, 4);
                ksd::TreePop();
            }
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section D", 1))
        {
            ksd::SliderFloat("float slider", &vars::miscAnimSpeed, 0.f, 10.f);
            ksd::Checkbox("checkbox 1", &vars::miscWatermark);
            ksd::Checkbox("checkbox 2", &vars::miscShowFps);
            ksd::Checkbox("checkbox 3", &vars::miscBlur);
            ksd::Combo("combo", &vars::miscTheme, comboC, 4);

            ksd::Separator();

            const ImVec2 row = ksd::CursorPos();
            ksd::Label("keybind");
            ksd::Keybind("msc_panic", &vars::mscPanicKey, ImVec2(ksd::PanelRightX() - style::KeybindW, row.y), ImVec2(style::KeybindW, style::KeybindH));
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section E", 1))
        {
            ksd::SeparatorText("separator");
            ksd::Label("progress bar");
            ksd::ProgressBar(vars::miscSessionXp);

            ksd::Separator();

            ksd::Button("button 1", ksd::ContentWidth());
            if (ksd::Button("button 2", ksd::ContentWidth()))
            {
                vars::miscAnimSpeed = 4.f;
            }

            ksd::Separator();

            ksd::Label("Made by Zapcrash");
            if (ksd::Hyperlink("YouTube"))
            {
                ksd::OpenUrl("https://www.youtube.com");
            }
        }
        ksd::EndGroup();
    }
}
