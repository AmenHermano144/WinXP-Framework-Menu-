#include "skins.hpp"
#include "../pages.hpp"
#include "../../framework/framework.hpp"

namespace vars
{
    int   sknWeapon = 0;
    int   sknSkin = 1;
    float sknWear = 0.06f;
    int   sknSeed = 387;
    bool  sknStattrak = true;
    int   sknStattrakKills = 1337;
    char  sknNameTag[64] = "sample text";

    int   sknKnifeModel = 0;
    int   sknGloveModel = 0;
    bool  sknCustomPaint = false;
    bool  sknPaintEnabled = true;
    float sknPaintColor[4] = { 0.85f, 0.22f, 0.30f, 1.f };
    bool  sknPaintRainbow = false;
    float sknPaintSpeed = 1.f;
}

namespace pages
{
    void RenderSkins() noexcept
    {
        static const char* const listItemsA[] = { "row 1", "row 2", "row 3", "row 4", "row 5", "row 6", "row 7", "row 8" };
        static const char* const comboA[] = { "option 1", "option 2", "option 3", "option 4", "option 5", "option 6" };
        static const char* const comboB[] = { "option 1", "option 2", "option 3", "option 4", "option 5" };
        static const char* const comboC[] = { "option 1", "option 2", "option 3", "option 4" };

        ksd::SetColumns(2);

        if (ksd::BeginGroup("Section A", 0))
        {
            ksd::ListBox("skn_list", &vars::sknWeapon, listItemsA, 8);
            ksd::Tooltip("sample tooltip");
            ksd::Separator();
            ksd::Combo("combo", &vars::sknSkin, comboA, 6);
            ksd::SliderFloat("float slider", &vars::sknWear, 0.f, 1.f, "%.2f");
            ksd::SpinInt("spin int 1", &vars::sknSeed, 0, 1000);
            ksd::Checkbox("checkbox", &vars::sknStattrak);
            ksd::SpinInt("spin int 2", &vars::sknStattrakKills, 0, 9999);
            ksd::Label("text input");
            ksd::InputText("skn_name", vars::sknNameTag, (int)sizeof(vars::sknNameTag));
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section B", 1))
        {
            ksd::Combo("combo 1", &vars::sknKnifeModel, comboB, 5);
            ksd::Combo("combo 2", &vars::sknGloveModel, comboC, 4);
            ksd::Separator();
            ksd::Checkbox("checkbox", &vars::sknCustomPaint);
            ksd::CheckboxColor("checkbox + color", &vars::sknPaintEnabled, "skn_paint", vars::sknPaintColor, &vars::sknPaintRainbow, &vars::sknPaintSpeed);
        }
        ksd::EndGroup();

        if (ksd::BeginGroup("Section C", 1))
        {
            const float buttonWidth = ksd::ContentWidth();
            ksd::Button("button 1", buttonWidth);
            ksd::Button("button 2", buttonWidth);
            ksd::Button("button 3", buttonWidth);
        }
        ksd::EndGroup();
    }
}
