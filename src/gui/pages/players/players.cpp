#include "players.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    int   plrSelected = 0;
    bool  plrFriend = false;
    bool  plrIgnoreAim = false;
    bool  plrForceVisible = false;
    bool  plrWhitelist = false;
    bool  plrTags[5] = { false, false, true, false, false };

    bool  plrDrawChams = true;
    float plrChamsColor[4] = { 0.78f, 0.30f, 0.86f, 1.f };
    bool  plrGlow = false;
    float plrGlowColor[4] = { 0.20f, 0.55f, 0.90f, 1.f };
    bool  plrGlowRainbow = false;
    float plrGlowSpeed = 1.f;
    bool  plrName = true;
    float plrNameColor[4] = { 1.f, 1.f, 1.f, 1.f };
    float plrPriority = 5.f;
    int   plrHitbox = 0;

    int   plrAimPriority = 1;
    int   plrMaxDistance = 600;
    int   plrBacktrackTicks = 12;
    bool  plrAutoMark = false;
    bool  plrShowOffscreen = true;
    int   plrSortMode = 0;

    bool  plrLogJoins = true;
    bool  plrLogLeaves = false;
    bool  plrLogChat = false;
    bool  plrAnnounceFriends = true;
    int   plrLogScrollback = 200;
    char  plrNoteBuf[64] = "sample text";

    bool  plrPanicHide = false;
    int   plrCacheSize = 32;
    float plrSessionShare = 0.42f;
}

namespace pages
{
    void RenderPlayers() noexcept
    {
        static const char* const listItems[] = { "row 1", "row 2", "row 3", "row 4",
            "row 5", "row 6", "row 7", "row 8" };
        static const char* const multiItems[] = { "item 1", "item 2", "item 3", "item 4", "item 5" };
        static const char* const comboA[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const comboB[] = { "option 1", "option 2", "option 3", "option 4" };
        static const char* const comboC[] = { "option 1", "option 2", "option 3", "option 4" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::ListBox("plr_list", &vars::plrSelected, listItems, 8, 5);
            ksd::Tooltip("sample tooltip");
            ksd::Separator();
            ksd::Checkbox("checkbox 1", &vars::plrFriend);
            ksd::Checkbox("checkbox 2", &vars::plrIgnoreAim);
            ksd::Checkbox("checkbox 3", &vars::plrForceVisible);
            ksd::Checkbox("checkbox 4", &vars::plrWhitelist);
            ksd::MultiCombo("multi-select", vars::plrTags, multiItems, 5);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 0))
        {
            ksd::Combo("combo 1", &vars::plrAimPriority, comboA, 4);
            ksd::SliderInt("int slider 1", &vars::plrMaxDistance, 0, 2000);
            ksd::SliderInt("int slider 2", &vars::plrBacktrackTicks, 0, 16);
            ksd::Checkbox("checkbox 1", &vars::plrAutoMark);
            ksd::Checkbox("checkbox 2", &vars::plrShowOffscreen);
            ksd::Combo("combo 2", &vars::plrSortMode, comboB, 4);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 1))
        {
            ksd::Checkbox("checkbox", &vars::plrDrawChams);
            ksd::CheckboxColor("checkbox + color 1", &vars::plrDrawChams, "plr_chams_col", vars::plrChamsColor);
            ksd::CheckboxColor("checkbox + color 2", &vars::plrGlow, "plr_glow_col", vars::plrGlowColor, &vars::plrGlowRainbow, &vars::plrGlowSpeed);
            ksd::CheckboxColor("checkbox + color 3", &vars::plrName, "plr_name_col", vars::plrNameColor);
            ksd::Separator();
            ksd::SliderFloat("float slider", &vars::plrPriority, 0.f, 10.f);
            ksd::Combo("combo", &vars::plrHitbox, comboC, 4);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section D", 1))
        {
            ksd::Checkbox("checkbox 1", &vars::plrLogJoins);
            ksd::Checkbox("checkbox 2", &vars::plrLogLeaves);
            ksd::Checkbox("checkbox 3", &vars::plrLogChat);
            ksd::Checkbox("checkbox 4", &vars::plrAnnounceFriends);
            ksd::SpinInt("spin int", &vars::plrLogScrollback, 50, 1000, 50);
            ksd::InputText("plr_note", vars::plrNoteBuf, 64);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section E", 1))
        {
            ksd::SeparatorText("separator");
            ksd::Label("progress bar");
            ksd::ProgressBar(vars::plrSessionShare);
            ksd::SpinInt("spin int", &vars::plrCacheSize, 8, 128, 8);
            ksd::Checkbox("checkbox", &vars::plrPanicHide);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section F", 1))
        {
            ksd::Button("button 1");
            ksd::Button("button 2");
            ksd::Button("button 3", ksd::ContentWidth());
        }
        ksd::EndGroup();
    }
}
