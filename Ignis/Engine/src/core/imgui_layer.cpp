#include "imgui_layer.hpp"

#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_sdl3.h>
#include <imgui_internal.h>

#include "window.hpp"

ImGuiLayer::ImGuiLayer(Window *window)
    : m_window(window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiStyle& style = ImGui::GetStyle();
      ImVec4* colors = style.Colors;

      // Base Colors
      ImVec4 bg_color = ImVec4(0.10f, 0.105f, 0.11f, 1.00f);
      ImVec4 light_color = ImVec4(0.15f, 0.16f, 0.17f, 1.00f);
      ImVec4 panel_color = ImVec4(0.17f, 0.18f, 0.19f, 1.00f);
      ImVec4 panel_hovered_color = ImVec4(0.20f, 0.22f, 0.24f, 1.00f);
      ImVec4 panel_active_color = ImVec4(0.23f, 0.26f, 0.29f, 1.00f);
      ImVec4 text_color = ImVec4(0.86f, 0.87f, 0.88f, 1.00f);
      ImVec4 text_disabled_color = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
      ImVec4 border_color = ImVec4(0.14f, 0.16f, 0.18f, 1.00f);

      // Text
      colors[ImGuiCol_Text] = text_color;
      colors[ImGuiCol_TextDisabled] = text_disabled_color;

      // Windows
      colors[ImGuiCol_WindowBg] = bg_color;
      colors[ImGuiCol_ChildBg] = bg_color;
      colors[ImGuiCol_PopupBg] = bg_color;
      colors[ImGuiCol_Border] = border_color;
      colors[ImGuiCol_BorderShadow] = border_color;

      // Headers
      colors[ImGuiCol_Header] = panel_color;
      colors[ImGuiCol_HeaderHovered] = panel_hovered_color;
      colors[ImGuiCol_HeaderActive] = panel_active_color;

      // Buttons
      colors[ImGuiCol_Button] = panel_color;
      colors[ImGuiCol_ButtonHovered] = panel_hovered_color;
      colors[ImGuiCol_ButtonActive] = panel_active_color;

      // Frame BG
      colors[ImGuiCol_FrameBg] = light_color;
      colors[ImGuiCol_FrameBgHovered] = panel_hovered_color;
      colors[ImGuiCol_FrameBgActive] = panel_active_color;

      // Tabs
      colors[ImGuiCol_Tab] = panel_color;
      colors[ImGuiCol_TabHovered] = panel_hovered_color;
      colors[ImGuiCol_TabActive] = panel_active_color;
      colors[ImGuiCol_TabUnfocused] = panel_color;
      colors[ImGuiCol_TabUnfocusedActive] = panel_hovered_color;

      // Title
      colors[ImGuiCol_TitleBg] = bg_color;
      colors[ImGuiCol_TitleBgActive] = bg_color;
      colors[ImGuiCol_TitleBgCollapsed] = bg_color;

      // Scrollbar
      colors[ImGuiCol_ScrollbarBg] = bg_color;
      colors[ImGuiCol_ScrollbarGrab] = panel_color;
      colors[ImGuiCol_ScrollbarGrabHovered] = panel_hovered_color;
      colors[ImGuiCol_ScrollbarGrabActive] = panel_active_color;

      // Checkmark
      colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);

      // Slider
      colors[ImGuiCol_SliderGrab] = panel_hovered_color;
      colors[ImGuiCol_SliderGrabActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.0f);

      // Resize Grip
      colors[ImGuiCol_ResizeGrip] = panel_color;
      colors[ImGuiCol_ResizeGripHovered] = panel_hovered_color;
      colors[ImGuiCol_ResizeGripActive] = panel_active_color;

      // Separator
      colors[ImGuiCol_Separator] = border_color;
      colors[ImGuiCol_SeparatorHovered] = panel_hovered_color;
      colors[ImGuiCol_SeparatorActive] = panel_active_color;

      // Plot
      colors[ImGuiCol_PlotLines] = text_color;
      colors[ImGuiCol_PlotLinesHovered] = panel_active_color;
      colors[ImGuiCol_PlotHistogram] = text_color;
      colors[ImGuiCol_PlotHistogramHovered] = panel_active_color;

      // Text Selected BG
      colors[ImGuiCol_TextSelectedBg] = panel_active_color;

      // Modal Window Dim Bg
      colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.10f, 0.105f, 0.11f, 0.5f);

      // Tables
      colors[ImGuiCol_TableHeaderBg] = panel_color;
      colors[ImGuiCol_TableBorderStrong] = border_color;
      colors[ImGuiCol_TableBorderLight] = border_color;
      colors[ImGuiCol_TableRowBg] = bg_color;
      colors[ImGuiCol_TableRowBgAlt] = light_color;

      // Styles
      style.FrameBorderSize = 1.0f;
      style.FrameRounding = 2.0f;
      style.WindowBorderSize = 1.0f;
      style.PopupBorderSize = 1.0f;
      style.ScrollbarSize = 12.0f;
      style.ScrollbarRounding = 2.0f;
      style.GrabMinSize = 12.0f;
      style.GrabRounding = 2.0f;
      style.TabBorderSize = 1.0f;
      style.TabRounding = 2.0f;

      // Reduced Padding and Spacing
      style.WindowPadding = ImVec2(3.0f, 3.0f);
      style.FramePadding = ImVec2(5.0f, 5.0f);
      style.ItemSpacing = ImVec2(8.0f, 4.0f);
      style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);


    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigViewportsNoDecoration = false;
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    f32 fontSize = 16.0f;
    io.FontDefault = io.Fonts->AddFontFromFileTTF("Resources/Fonts/segoeui.ttf", fontSize);

    ImGui_ImplSDL3_InitForOpenGL(m_window->get_native_window(), m_window->get_gl_context());
    ImGui_ImplOpenGL3_Init("#version 450");

    m_window->set_gui_event_callback([](const SDL_Event *event) {
       ImGui_ImplSDL3_ProcessEvent(event);
    });
}

void ImGuiLayer::begin_render()
{
    ImGui_ImplOpenGL3_NewFrame();

    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::end_render()
{
    ImGuiIO &io = ImGui::GetIO();

    i32 fb_width, fb_height;
    m_window->get_framebuffer_size(&fb_width, &fb_height);
    io.DisplaySize = ImVec2(static_cast<float>(fb_width), static_cast<float>(fb_height));

    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        SDL_Window *backup_current_window = SDL_GL_GetCurrentWindow();
        const SDL_GLContext backup_context = SDL_GL_GetCurrentContext();

        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();

        SDL_GL_MakeCurrent(backup_current_window, backup_context);
    }
}

void ImGuiLayer::destroy()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}
