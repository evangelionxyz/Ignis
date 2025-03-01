#include "ignis.hpp"

#include "imgui.h"

IgnisEditor::IgnisEditor()
	: Application("Ignis")
{
	Renderer::init(RendererAPI::OPENGL);

	m_window = Window(m_name, 1280, 720);
	m_window.set_event_callback(BIND_CLASS_EVENT_FN(IgnisEditor::on_event));

	m_imgui_layer = ImGuiLayer(&m_window);

	const u32 vertex_shader = GLShader::create_shader("Resources/Shaders/default.vert.glsl", SHADER_TYPE_VERTEX);
	const u32 fragment_shader = GLShader::create_shader("Resources/Shaders/default.frag.glsl", SHADER_TYPE_FRAGMENT);

	m_shader.create_program();
	m_shader.compile(vertex_shader);
	m_shader.compile(fragment_shader);
	m_shader.link();

	// framebuffer
	FramebufferSpec spec;
	spec.width = 1280;
	spec.height = 720;
	m_viewport_framebuffer = GLFramebuffer(spec);

	m_camera = Camera(CAMERA_TYPE_2D, spec.width, spec.height, {0.0f, 0.0f, 1.0f});
	m_camera.resize({spec.width, spec.height});

	glCreateVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
}

void IgnisEditor::run()
{
	f32 last_frame_time = 0.0f;
	
	while (m_window.is_running())
	{
		m_window.poll_events();


		const f32 current_time = static_cast<f32>(SDL_GetTicks());
		const f32 delta_time = (current_time - last_frame_time) / 1000.0f;
		last_frame_time = current_time;
		m_camera.on_update(delta_time);

		on_update(delta_time);
		{
			m_imgui_layer.begin_render();
			{
				//main dockspace
				ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse
										 | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus
										 | ImGuiWindowFlags_NoNavFocus;
				const ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::Begin("main_dockspace", nullptr, flags);
				ImGui::DockSpace(ImGui::GetID("main_dockspace"), ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

				{
					// scene dockspace
					ImGuiWindowFlags dockspace_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar;
					ImGui::Begin("Scene", nullptr, dockspace_flags);
					ImGui::DockSpace(ImGui::GetID("scene_dockspace"), ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
					ImGui::End(); // end scene dockspace
				}

				ImGui::End(); // end dockspace
			}

			on_gui_render(delta_time);

			m_imgui_layer.end_render();
		}
		m_window.swap_buffers();
	}
}

void IgnisEditor::on_event(Event &event)
{
	m_camera.on_event(event);
}

void IgnisEditor::draw_viewport() {
	ImGui::Begin("Viewport", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar);
	const ImVec2 viewport_size = ImGui::GetWindowSize();
	m_viewport_size = {static_cast<i32>(viewport_size.x), static_cast<i32>(viewport_size.y)};
	const ImTextureID viewport_id = m_viewport_framebuffer.get_id();
	ImGui::Image(viewport_id, viewport_size, ImVec2(0, 1), ImVec2(1, 0));
	ImGui::End();

	ImGui::Begin("Inspector", nullptr, 0);
	ImGui::Text("Hello World");
	ImGui::End();
}

void IgnisEditor::on_update(f32 delta_time)
{
	resize();

	m_viewport_framebuffer.bind();
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader.use();
	m_shader.set_uniform_mat4("u_view_projection", m_camera.get_view_projection());
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	GLFramebuffer::unbind();
}

void IgnisEditor::on_gui_render(f32 delta_time)
{
	ImGui::ShowDemoWindow();
	draw_viewport();
}

void IgnisEditor::resize() {
	if (m_viewport_size.x != m_viewport_framebuffer.get_width() || m_viewport_size.y != m_viewport_framebuffer.get_height())
	{
		m_viewport_framebuffer.resize(m_viewport_size.x, m_viewport_size.y);
		m_camera.resize({m_viewport_size.x, m_viewport_size.y});
	}
}

void IgnisEditor::destroy()
{
	m_window.destroy();
	m_shader.destroy();

	m_viewport_framebuffer.destroy();
	m_imgui_layer.destroy();

	Renderer::shutdown();
}

int main()
{
	Logger::init();
	IgnisEditor editor;
	editor.run();
	editor.destroy();
	Logger::shutdown();
	return 0;
}
