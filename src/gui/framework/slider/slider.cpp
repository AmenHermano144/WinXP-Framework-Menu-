#include "slider.hpp"
#include "../shell/shell.hpp"
#include "../styling.hpp"
#include "imgui.h"

#include <cstdio>

namespace ksd
{
    static const void* s_active = nullptr;

    static void DottedRect(ImDrawList* dl, const ImVec2& a, const ImVec2& b, ImU32 col)
    {
        for (float x = a.x; x < b.x; x += 2.f)
        {
            dl->AddRectFilled(ImVec2(x, a.y), ImVec2(x + 1.f, a.y + 1.f), col);
            dl->AddRectFilled(ImVec2(x, b.y - 1.f), ImVec2(x + 1.f, b.y), col);
        }
        for (float y = a.y; y < b.y; y += 2.f)
        {
            dl->AddRectFilled(ImVec2(a.x, y), ImVec2(a.x + 1.f, y + 1.f), col);
            dl->AddRectFilled(ImVec2(b.x - 1.f, y), ImVec2(b.x, y + 1.f), col);
        }
    }

    void DrawTrackbar(ImDrawList* dl, const ImVec2& origin, float w, float t, bool focused)
    {
        const float left = origin.x;
        const float right = origin.x + w;
        const float trackY = origin.y;

        if (focused)
        {
            DottedRect(dl, ImVec2(left - 2.f, trackY - 2.f),
                ImVec2(right + 2.f, trackY + style::SliderTrackH), style::Text);
        }

        // XP recessed groove: thin filled bar with rounded ends.
        const float grooveY = trackY + 8.f;
        const ImVec2 gMin(left, grooveY);
        const ImVec2 gMax(right, grooveY + 4.f);
        dl->AddRectFilled(gMin, gMax, IM_COL32(214, 223, 235, 255));
        dl->AddRect(gMin, gMax, style::InputBorder, 0.f, 0, 1.f);

        // XP-style thumb: rounded rectangle with vertical Luna gradient.
        const float cx = left + style::ThumbW * 0.5f + t * (w - style::ThumbW);
        const float halfW = 7.f;
        const float thumbT = trackY + 2.f;
        const float thumbB = trackY + style::ThumbBodyH + 2.f;
        const ImVec2 tMin(cx - halfW, thumbT);
        const ImVec2 tMax(cx + halfW, thumbB);
        const float midY = (thumbT + thumbB) * 0.5f;

        dl->AddRectFilledMultiColor(ImVec2(tMin.x + 1.f, tMin.y + 1.f), ImVec2(tMax.x - 1.f, midY),
            IM_COL32(255, 255, 255, 255), IM_COL32(255, 255, 255, 255),
            IM_COL32(230, 240, 252, 255), IM_COL32(230, 240, 252, 255));
        dl->AddRectFilledMultiColor(ImVec2(tMin.x + 1.f, midY), ImVec2(tMax.x - 1.f, tMax.y - 1.f),
            IM_COL32(210, 226, 246, 255), IM_COL32(210, 226, 246, 255),
            IM_COL32(160, 190, 232, 255), IM_COL32(160, 190, 232, 255));
        dl->AddRect(tMin, tMax, style::BtnBorder, 0.f, 0, 1.f);
        dl->AddLine(ImVec2(cx, thumbT + 3.f), ImVec2(cx, thumbB - 3.f), IM_COL32(80, 100, 145, 200), 1.f);
    }

    static float DrawSlider(const char* label, float value, float vmin, float vmax, const char* fmt, const void* id)
    {
        ImDrawList* dl = ImGui::GetWindowDrawList();
        const ImVec2 pos = ksd::CursorPos();
        const float w = ksd::ContentWidth();
        const float lineH = ImGui::GetTextLineHeight();

        char buf[32];
        std::snprintf(buf, sizeof(buf), fmt, value);
        const ImVec2 vts = ImGui::CalcTextSize(buf);

        dl->AddText(pos, style::Text, label);
        dl->AddText(ImVec2(pos.x + w - vts.x, pos.y), style::Text, buf);

        const float trackY = pos.y + lineH + 3.f;
        const float left = pos.x;
        const float right = pos.x + w;
        const ImVec2 trackMin(left, trackY);
        const ImVec2 trackMax(right, trackY + style::SliderTrackH);

        const float span = (vmax - vmin);
        float t = (span != 0.f) ? (value - vmin) / span : 0.f;
        if (t < 0.f) { t = 0.f; }
        if (t > 1.f) { t = 1.f; }

        const bool hovered = ImGui::IsMouseHoveringRect(trackMin, trackMax) && ksd::PopUpsAreClosed();
        if (s_active == id)
        {
            if (!ImGui::IsMouseDown(ImGuiMouseButton_Left))
            {
                s_active = nullptr;
            }
        }
        else if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
        {
            s_active = id;
        }

        if (s_active == id)
        {
            const float mx = ImGui::GetMousePos().x;
            float nt = (mx - (left + style::ThumbW * 0.5f)) / (w - style::ThumbW);
            if (nt < 0.f) { nt = 0.f; }
            if (nt > 1.f) { nt = 1.f; }
            t = nt;
            value = vmin + t * span;
        }

        DrawTrackbar(dl, ImVec2(left, trackY), w, t, hovered || s_active == id);

        ksd::AddItem(ImVec2(w, lineH + 3.f + style::SliderTrackH));
        return value;
    }

    bool SliderInt(const char* label, int* v, int vmin, int vmax)
    {
        const float nv = DrawSlider(label, (float)*v, (float)vmin, (float)vmax, "%.0f", v);
        const int iv = (int)(nv + (nv >= 0.f ? 0.5f : -0.5f));
        const bool changed = iv != *v;
        *v = iv;
        return changed;
    }

    bool SliderFloat(const char* label, float* v, float vmin, float vmax, const char* fmt)
    {
        const float nv = DrawSlider(label, *v, vmin, vmax, fmt, v);
        const bool changed = nv != *v;
        *v = nv;
        return changed;
    }
}
