#include "ignis.hpp"

#include "imgui.h"

IgnisEditor::IgnisEditor()
	: Application("Ignis")
{
	Renderer::create(RendererAPI::OPENGL);

	m_window = Window(m_name, 1280, 720);
	m_window.set_event_callback(BIND_CLASS_EVENT_FN(IgnisEditor::on_event));

	//Renderer::init();

	m_imgui_layer = ImGuiLayer(&m_window);

	const u32 vertex_shader = GLShader::create_shader("Resources/Shaders/default.vert.glsl", SHADER_TYPE_VERTEX);
	const u32 fragment_shader = GLShader::create_shader("Resources/Shaders/default.frag.glsl", SHADER_TYPE_FRAGMENT);

	m_shader.create_program();
	m_shader.compile(vertex_shader);
	m_shader.compile(fragment_shader);
	m_shader.link();

	// framebuffer
	FramebufferSpec spec;
	spec.attachments = {
		FramebufferTextureSpec(TEXTURE_FORMAT_RGBA8),
		FramebufferTextureSpec(TEXTURE_FORMAT_DEPTH24STENCIL8)
	};

	spec.width = 1280;
	spec.height = 720;
	m_viewport_framebuffer = GLFramebuffer(spec);

	m_camera = Camera(CAMERA_TYPE_2D, spec.width, spec.height, {0.0f, 0.0f, 1.0f});
	m_camera.resize({spec.width, spec.height});

	f32 vertices[] = {
		// Position    // TexCoords (flip Y)
		-0.5f, -0.5f, 0.0f, 1.0f,  // Bottom-left  (0,1)
		-0.5f,  0.5f, 0.0f, 0.0f,  // Top-left     (0,0)
		 0.5f,  0.5f, 1.0f, 0.0f,  // Top-right    (1,0)
		 0.5f, -0.5f, 1.0f, 1.0f   // Bottom-right (1,1)
	};


	u32 indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	m_vertex_array = GLVertexArray::create();
	m_vertex_buffer = GLVertexBuffer::create(vertices, sizeof(vertices));
	m_vertex_buffer->set_layout({
		{ShaderDataType_Float2, "position"},
		{ShaderDataType_Float2, "texture_coord"}
	});
	m_vertex_array->add_vertex_buffer(m_vertex_buffer);

	Ref<GLIndexBuffer> index_buffer = GLIndexBuffer::create(indices, sizeof(indices) / sizeof(u32));
	m_vertex_array->set_index_buffer(index_buffer);

	m_scene = Scene::create("new scene");
	const entt::entity entity_a = m_scene->create_entity("entity1");
	const entt::entity entity_b = m_scene->create_entity("entity2");

	Transform &tr_a = m_scene->entity_get_component<Transform>(entity_a);
	tr_a.world_translation = glm::vec3(1.0f, 0.0f, 0.0f);
	Transform &tr_b = m_scene->entity_get_component<Transform>(entity_b);
	tr_b.world_translation = glm::vec3(-1.0f, 0.0f, 0.0f);

	m_texture = Texture::create("Resources/Textures/brick.jpg");
	Sprite &sp_a = m_scene->entity_add_component<Sprite>(entity_a);
	sp_a.color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	sp_a.texture = m_texture;

	Sprite &sp_b = m_scene->entity_add_component<Sprite>(entity_b);
	sp_b.color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	sp_b.texture = m_texture;

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
	if (is_viewport_hovered)
		m_camera.on_event(event);
}

void IgnisEditor::draw_viewport() {
	ImGui::Begin("Viewport", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	is_viewport_hovered = ImGui::IsWindowHovered();
	is_viewport_active = ImGui::IsWindowFocused();

	const ImVec2 viewport_size = ImGui::GetWindowSize();
	m_viewport_size = {static_cast<i32>(viewport_size.x), static_cast<i32>(viewport_size.y)};
	const ImTextureID viewport_id = m_viewport_framebuffer.get_id();
	ImGui::Image(viewport_id, viewport_size, ImVec2(0, 1), ImVec2(1, 0));
	ImGui::End();

	ImGui::Begin("Inspector", nullptr, 0);
	ImGui::Text("Hello World");
	ImGui::ColorEdit4("clear color", glm::value_ptr(m_clear_color));

	ImTextureID texture_a = (uintptr_t)m_texture->get_id();
	ImGui::Image(texture_a, {512.0f, 256.0f}, ImVec2(0, 1), ImVec2(1, 0));

	ImGui::End();
}

void IgnisEditor::on_update(f32 delta_time)
{
	resize();

	m_viewport_framebuffer.bind();
	glClearColor(m_clear_color.x, m_clear_color.y, m_clear_color.z, m_clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader.use();
	m_shader.set_uniform_mat4("u_view_projection", m_camera.get_view_projection());
	m_scene->get_registry().view<Transform, Sprite>().each([&](auto entity, Transform &transform, Sprite &sprite)
   {
		m_shader.set_uniform_mat4("u_model_matrix", transform.get_world_transform());
		m_shader.set_uniform_vec4("u_color", sprite.color);

		sprite.texture->bind(0);
		m_shader.set_uniform_int("u_texture", sprite.texture->get_index());

		m_vertex_array->bind();
		m_vertex_buffer->bind();
		u32 count = m_vertex_array->get_index_buffer()->get_count();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
   });

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
	m_scene->destroy();

	m_vertex_array->destroy();
	m_vertex_array->destroy();

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
