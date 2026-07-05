#include "button.hpp"
#include "../shell/shell.hpp"
#include "../styling.hpp"
#include "imgui.h"

namespace ksd
{
    static bool DrawButton(const char* label, float width)
    {
        ImDrawList* dl = ImGui::GetWindowDrawList();
        const ImVec2 pos = ksd::CursorPos();
        const ImVec2 ts = ImGui::CalcTextSize(label);

        float w = width;
        if (w <= 0.f)
        {
            w = ts.x + 18.f;
        }
        const ImVec2 a = pos;
        const ImVec2 b(pos.x + w, pos.y + style::ButtonH);

        const bool hovered = ImGui::IsMouseHoveringRect(a, b) && ksd::PopUpsAreClosed();
        const bool held = hovered && ImGui::IsMouseDown(ImGuiMouseButton_Left);

        if (held)
        {
            style::Pressed(dl, a, b);
        }
        else
        {
            style::Raised(dl, a, b);
        }
        if (hovered && !held)
        {
            dl->AddRect(a, b, style::BtnHoverGlow, 0.f, 0, 1.f);
            dl->AddRect(ImVec2(a.x - 1.f, a.y - 1.f), ImVec2(b.x + 1.f, b.y + 1.f), IM_COL32(255, 176, 46, 80), 0.f, 0, 1.f);
        }

        dl->AddText(ImVec2((a.x + b.x - ts.x) * 0.5f, (a.y + b.y - ts.y) * 0.5f), style::Text, label);

        ksd::AddItem(ImVec2(w, style::ButtonH));
        return hovered && ImGui::IsMouseReleased(ImGuiMouseButton_Left);
    }

    bool Button(const char* label, float width)
    {
        return DrawButton(label, width);
    }
}
