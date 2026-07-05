#pragma once

#include "imgui.h"

namespace style
{
    // XP Luna Blue palette. Names kept for API compat with the Win95 widgets;
    // meanings shifted so the widgets inherit XP look through the same primitives.
    constexpr ImU32 Face         = IM_COL32(236, 233, 216, 255);  // ECE9D8 surface
    constexpr ImU32 Light        = IM_COL32(245, 244, 234, 255);
    constexpr ImU32 Highlight    = IM_COL32(255, 255, 255, 255);
    constexpr ImU32 Shadow       = IM_COL32(172, 168, 153, 255);  // ACA899 button-shadow
    constexpr ImU32 DarkShadow   = IM_COL32(113, 111, 100, 255);  // 716F64 window-frame

    constexpr ImU32 Field        = IM_COL32(255, 255, 255, 255);
    constexpr ImU32 Text         = IM_COL32(0, 0, 0, 255);
    constexpr ImU32 TextDisabled = IM_COL32(140, 140, 140, 255);

    // Luna title stops (used both by TitleBar helper and as base accent).
    constexpr ImU32 TitleLeft    = IM_COL32(0, 84, 227, 255);
    constexpr ImU32 TitleRight   = IM_COL32(30, 145, 255, 255);
    constexpr ImU32 TitleText    = IM_COL32(255, 255, 255, 255);
    constexpr ImU32 TitleTop     = IM_COL32(0, 84, 227, 255);
    constexpr ImU32 TitleMid     = IM_COL32(28, 122, 246, 255);
    constexpr ImU32 TitleBot     = IM_COL32(4, 32, 145, 255);
    constexpr ImU32 TitleGloss   = IM_COL32(126, 219, 255, 210);
    constexpr ImU32 TitleGlossFade = IM_COL32(126, 219, 255, 0);

    constexpr ImU32 Selection    = IM_COL32(49, 106, 197, 255);
    constexpr ImU32 SelText      = IM_COL32(255, 255, 255, 255);
    constexpr ImU32 SliderFill   = IM_COL32(38, 161, 27, 255);

    // XP Luna glossy button gradient (top->bottom).
    constexpr ImU32 BtnBorder    = IM_COL32(0, 60, 116, 255);     // 003C74
    constexpr ImU32 BtnTop       = IM_COL32(255, 255, 255, 255);
    constexpr ImU32 BtnMidTop    = IM_COL32(238, 244, 251, 255);
    constexpr ImU32 BtnMidBot    = IM_COL32(216, 227, 244, 255);
    constexpr ImU32 BtnBot       = IM_COL32(179, 202, 236, 255);
    constexpr ImU32 BtnPressedTop = IM_COL32(199, 214, 235, 255);
    constexpr ImU32 BtnPressedBot = IM_COL32(230, 236, 244, 255);
    constexpr ImU32 BtnHoverGlow = IM_COL32(255, 176, 46, 210);   // XP orange hover ring

    // Field / input / listbox border.
    constexpr ImU32 InputBorder  = IM_COL32(127, 157, 185, 255);  // 7F9DB9
    constexpr ImU32 GroupBorder  = IM_COL32(148, 191, 255, 255);  // dialog etch

    // Window outer frame (blue XP ring).
    constexpr ImU32 FrameOuter   = IM_COL32(0, 56, 212, 255);
    constexpr ImU32 FrameInner   = IM_COL32(15, 116, 228, 255);

    // Progress bar chunks.
    constexpr ImU32 ProgressBg   = IM_COL32(230, 232, 235, 255);
    constexpr ImU32 ProgressGreen= IM_COL32(38, 161, 27, 255);

    // Close button red (XP).
    constexpr ImU32 CloseRedTop  = IM_COL32(232, 100, 77, 255);
    constexpr ImU32 CloseRedMid  = IM_COL32(215, 60, 34, 255);
    constexpr ImU32 CloseRedBot  = IM_COL32(160, 34, 12, 255);
    constexpr ImU32 CloseRedBorder = IM_COL32(120, 30, 20, 255);
    constexpr ImU32 CloseGloss     = IM_COL32(255, 224, 208, 220);

    // XP title bar buttons for min/max — pale glossy blue.
    constexpr ImU32 TitleBtnTop    = IM_COL32(180, 220, 255, 255);
    constexpr ImU32 TitleBtnMid    = IM_COL32(90, 155, 240, 255);
    constexpr ImU32 TitleBtnBot    = IM_COL32(35, 96, 200, 255);
    constexpr ImU32 TitleBtnBorder = IM_COL32(11, 44, 138, 255);
    constexpr ImU32 TitleBtnGloss  = IM_COL32(255, 255, 255, 220);
    constexpr ImU32 TitleBtnGlyph  = IM_COL32(20, 42, 100, 255);

    // Chrome dimensions (bumped for XP look).
    constexpr float FrameBorder  = 4.f;
    constexpr float TitleBarH    = 26.f;
    constexpr float TitleBtnW    = 22.f;
    constexpr float TitleBtnH    = 20.f;
    constexpr float MenuBarH     = 21.f;
    constexpr float ToolbarH     = 28.f;
    constexpr float TabBarH      = 22.f;
    constexpr float TabPadX      = 10.f;
    constexpr float StatusBarH   = 22.f;
    constexpr float GripSize     = 16.f;
    constexpr float ScrollbarW     = 17.f;
    constexpr float ScrollArrowBtn = 17.f;
    constexpr float ScrollMinThumb = 20.f;

    constexpr float ContentPad   = 6.f;
    constexpr float ColumnGutter = 6.f;
    constexpr float GroupGap     = 7.f;
    constexpr float GroupTopPad  = 16.f;
    constexpr float GroupInnerX  = 10.f;
    constexpr float GroupBottomPad = 10.f;

    constexpr float RowSpacing   = 5.f;
    constexpr float CheckboxSize = 13.f;
    constexpr float RowHeight    = 15.f;
    constexpr float SwatchW      = 26.f;
    constexpr float SwatchH      = 14.f;
    constexpr float KeybindW     = 36.f;
    constexpr float KeybindH     = 16.f;
    constexpr float SliderTrackH  = 24.f;
    constexpr float ThumbW        = 11.f;
    constexpr float ThumbBodyH    = 18.f;
    constexpr float ThumbPointH   = 0.f;
    constexpr float TickH         = 3.f;
    constexpr float ComboH        = 22.f;
    constexpr float ButtonH       = 23.f;

    inline void FillFace(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        dl->AddRectFilled(a, b, Face);
    }

    inline void GradientV(ImDrawList* dl, const ImVec2& a, const ImVec2& b, ImU32 top, ImU32 bot)
    {
        dl->AddRectFilledMultiColor(a, b, top, top, bot, bot);
    }

    inline void GradientH(ImDrawList* dl, const ImVec2& a, const ImVec2& b, ImU32 left, ImU32 right)
    {
        dl->AddRectFilledMultiColor(a, b, left, right, right, left);
    }

    // XP button in normal state: three-stop vertical gradient + 1px dark blue border.
    inline void Raised(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        const ImVec2 inner(a.x + 1.f, a.y + 1.f);
        const ImVec2 outer(b.x - 1.f, b.y - 1.f);
        const float h = outer.y - inner.y;
        const float mid1 = inner.y + h * 0.45f;
        const float mid2 = inner.y + h * 0.55f;
        dl->AddRectFilledMultiColor(inner, ImVec2(outer.x, mid1), BtnTop, BtnTop, BtnMidTop, BtnMidTop);
        dl->AddRectFilled(ImVec2(inner.x, mid1), ImVec2(outer.x, mid2), BtnMidBot);
        dl->AddRectFilledMultiColor(ImVec2(inner.x, mid2), outer, BtnMidBot, BtnMidBot, BtnBot, BtnBot);
        dl->AddRect(a, b, BtnBorder, 0.f, 0, 1.f);
    }

    // Pressed variant: subtle inverted gradient, same border.
    inline void Pressed(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        const ImVec2 inner(a.x + 1.f, a.y + 1.f);
        const ImVec2 outer(b.x - 1.f, b.y - 1.f);
        dl->AddRectFilledMultiColor(inner, outer, BtnPressedTop, BtnPressedTop, BtnPressedBot, BtnPressedBot);
        dl->AddRect(a, b, BtnBorder, 0.f, 0, 1.f);
    }

    // Text-field / listbox / combo inset border: single thin blue-gray line.
    inline void Sunken(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        dl->AddRect(a, b, InputBorder, 0.f, 0, 1.f);
    }

    // Groupbox etched border: single light blue-gray line.
    inline void Etched(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        dl->AddRect(a, b, GroupBorder, 0.f, 0, 1.f);
    }

    // Kept for legacy call sites; used for hand-drawn 1px edges (tabs, separators).
    inline void Edge(ImDrawList* dl, const ImVec2& a, const ImVec2& b, ImU32 topLeft, ImU32 bottomRight)
    {
        dl->AddRectFilled(ImVec2(a.x, a.y), ImVec2(b.x, a.y + 1.f), topLeft);
        dl->AddRectFilled(ImVec2(a.x, a.y), ImVec2(a.x + 1.f, b.y), topLeft);
        dl->AddRectFilled(ImVec2(a.x, b.y - 1.f), ImVec2(b.x, b.y), bottomRight);
        dl->AddRectFilled(ImVec2(b.x - 1.f, a.y), ImVec2(b.x, b.y), bottomRight);
    }

    // Luna title bar: vertical gradient with a top gloss strip and a mid highlight band.
    inline void TitleBar(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        const float h = b.y - a.y;
        const float band = a.y + h * 0.55f;
        dl->AddRectFilledMultiColor(a, ImVec2(b.x, band), TitleTop, TitleTop, TitleMid, TitleMid);
        dl->AddRectFilledMultiColor(ImVec2(a.x, band), b, TitleMid, TitleMid, TitleBot, TitleBot);
        // top gloss highlight (about 3px, fades out)
        const float gh = 3.f;
        dl->AddRectFilledMultiColor(a, ImVec2(b.x, a.y + gh), TitleGloss, TitleGloss, TitleGlossFade, TitleGlossFade);
    }

    // Scrollbar track and page regions: soft blue-tinged gradient instead of Win95 stipple.
    // Kept the two-color signature so shell/listbox/combo call sites don't need to change.
    inline void Stipple(ImDrawList* dl, const ImVec2& a, const ImVec2& b, ImU32 base, ImU32)
    {
        const ImU32 top = base;
        const ImU32 bot = IM_COL32(210, 218, 230, 255);
        dl->AddRectFilledMultiColor(a, b, top, top, bot, bot);
    }

    // XP window outer frame: two blue rings around the whole shell.
    inline void FrameRing(ImDrawList* dl, const ImVec2& a, const ImVec2& b)
    {
        dl->AddRect(a, b, FrameOuter, 0.f, 0, 1.f);
        dl->AddRect(ImVec2(a.x + 1.f, a.y + 1.f), ImVec2(b.x - 1.f, b.y - 1.f), FrameInner, 0.f, 0, 1.f);
        dl->AddRect(ImVec2(a.x + 2.f, a.y + 2.f), ImVec2(b.x - 2.f, b.y - 2.f), FrameInner, 0.f, 0, 1.f);
    }

    // XP min/max button: pale blue Luna gradient with top gloss + rounded look.
    inline void TitleBtnBlue(ImDrawList* dl, const ImVec2& a, const ImVec2& b, bool held)
    {
        const ImVec2 inner(a.x + 1.f, a.y + 1.f);
        const ImVec2 outer(b.x - 1.f, b.y - 1.f);
        const float h = outer.y - inner.y;
        const float mid = inner.y + h * 0.5f;
        const ImU32 top    = held ? TitleBtnMid : TitleBtnTop;
        const ImU32 midCol = held ? TitleBtnBot : TitleBtnMid;
        const ImU32 bot    = held ? IM_COL32(20, 60, 150, 255) : TitleBtnBot;
        dl->AddRectFilledMultiColor(inner, ImVec2(outer.x, mid), top, top, midCol, midCol);
        dl->AddRectFilledMultiColor(ImVec2(inner.x, mid), outer, midCol, midCol, bot, bot);
        // top gloss strip fading out
        const float glossH = h * 0.45f;
        dl->AddRectFilledMultiColor(inner, ImVec2(outer.x, inner.y + glossH),
            TitleBtnGloss, TitleBtnGloss,
            IM_COL32(255, 255, 255, 0), IM_COL32(255, 255, 255, 0));
        // rounded-ish border: dark blue outline + soft corner pixels knocked out
        dl->AddRect(a, b, TitleBtnBorder, 3.f, 0, 1.f);
    }

    // XP close button: red Luna gradient with top gloss.
    inline void CloseBtn(ImDrawList* dl, const ImVec2& a, const ImVec2& b, bool held)
    {
        const ImVec2 inner(a.x + 1.f, a.y + 1.f);
        const ImVec2 outer(b.x - 1.f, b.y - 1.f);
        const float h = outer.y - inner.y;
        const float mid = inner.y + h * 0.5f;
        const ImU32 top    = held ? CloseRedMid : CloseRedTop;
        const ImU32 midCol = held ? CloseRedBot : CloseRedMid;
        const ImU32 bot    = held ? IM_COL32(120, 20, 6, 255) : CloseRedBot;
        dl->AddRectFilledMultiColor(inner, ImVec2(outer.x, mid), top, top, midCol, midCol);
        dl->AddRectFilledMultiColor(ImVec2(inner.x, mid), outer, midCol, midCol, bot, bot);
        // top gloss strip fading out
        const float glossH = h * 0.45f;
        dl->AddRectFilledMultiColor(inner, ImVec2(outer.x, inner.y + glossH),
            CloseGloss, CloseGloss,
            IM_COL32(255, 224, 208, 0), IM_COL32(255, 224, 208, 0));
        dl->AddRect(a, b, CloseRedBorder, 3.f, 0, 1.f);
    }
}
