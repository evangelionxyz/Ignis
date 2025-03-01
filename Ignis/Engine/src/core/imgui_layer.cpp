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

    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigViewportsNoDecoration = false;
    io.ConfigWindowsMoveFromTitleBarOnly = true;

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
