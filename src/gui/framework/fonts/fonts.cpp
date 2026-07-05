#include "fonts.hpp"
#include "imgui.h"

extern "C" unsigned char micross[876080];

namespace fonts
{
    static constexpr float kBodySize = 13.f;
    static constexpr float kTitleSize = 15.f;

    static ImFont* s_titleFont = nullptr;

    void Init()
    {
        ImGuiIO& io = ImGui::GetIO();

        ImFontConfig cfg;
        cfg.OversampleH = 2;
        cfg.OversampleV = 2;
        cfg.PixelSnapH = true;

        ImFont* body = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", kBodySize, &cfg);
        if (body == nullptr)
        {
            body = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", kBodySize, &cfg);
        }
        if (body == nullptr)
        {
            ImFontConfig fallback;
            fallback.FontDataOwnedByAtlas = false;
            fallback.OversampleH = 2;
            fallback.OversampleV = 2;
            fallback.PixelSnapH = true;
            io.Fonts->AddFontFromMemoryTTF(micross, (int)sizeof(micross), 16.f, &fallback);
        }

        s_titleFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahomabd.ttf", kTitleSize, &cfg);
        if (s_titleFont == nullptr)
        {
            s_titleFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeuib.ttf", kTitleSize, &cfg);
        }
        if (s_titleFont == nullptr)
        {
            s_titleFont = body;
        }
    }

    ImFont* Title()
    {
        return s_titleFont;
    }

    float TitleSize()
    {
        return kTitleSize;
    }
}
