#include "ignis.hpp"

IgnisEditor *IgnisEditor::s_instance = nullptr;;


IgnisEditor::IgnisEditor()
	: Application("Ignis")
{
	s_instance = this;

	Renderer::create(RendererAPI::OPENGL);

	m_window = Window(m_name, 1280, 840);
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

	Renderer::init();

	init();
}

void IgnisEditor::init()
{
	// load textures
	m_icons["close"] = Texture::create("Resources/Icons/close_24dp.png");
	m_icons["add"] = Texture::create("Resources/Icons/add_24dp.png");
	m_icons["minimize"] = Texture::create("Resources/Icons/minimize_24dp.png");
	m_icons["expand_content"] = Texture::create("Resources/Icons/expand_content_24dp.png");
	m_icons["collapse_content"] = Texture::create("Resources/Icons/collapse_content_24dp.png");
	m_icons["visibility"] = Texture::create("Resources/Icons/visibility_24dp.png");
	m_icons["visibility_off"] = Texture::create("Resources/Icons/visibility_off_24dp.png");
	m_icons["visibility_lock"] = Texture::create("Resources/Icons/visibility_lock_24dp.png");

	// create panels
	m_scene_hierarchy_panel = CreateRef<SceneHierarchyPanel>();
	m_scene_hierarchy_panel->set_scene(m_scene.get());

	m_inspector_panel = CreateRef<InspectorPanel>();
	m_inspector_panel->set_data(m_scene_hierarchy_panel.get(), INSPECTOR_STATE_SCENE);

	m_content_browser_panel = CreateRef<ContentBrowserPanel>();
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
			constexpr f32 TITLE_BAR_HEIGHT = 50.0f;

			m_imgui_layer.begin_render();
			{
				//main dockspace
				ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse
                    | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus |
                    ImGuiWindowFlags_NoNavFocus;

                const ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::Begin("main_dockspace", nullptr, window_flags);

				ImDrawList *draw_list = ImGui::GetWindowDrawList();
				draw_list->AddText(viewport->Pos, 0xFFFFFFFF, "Hello World");
				ImVec2 min_pos = viewport->Pos;
				ImVec2 max_pos = ImVec2(viewport->Pos.x + viewport->Size.x, viewport->Pos.y + TITLE_BAR_HEIGHT);

                // title bar background
                draw_list->AddRectFilled(min_pos, max_pos, IM_COL32(40, 40, 40, 255));

				// Window title text
				ImVec2 text_pos = ImVec2(min_pos.x + 10, min_pos.y + 7);
                const char* titlebar_text = "Ignis Editor";
                draw_list->AddText(text_pos, IM_COL32(255, 255, 255, 255), titlebar_text);
                ImVec2 titlebar_text_size = ImGui::CalcTextSize(titlebar_text);

                // ==================================
                // ============ Menu bar ============

				bool menu_hovered = false;
				const char* menu_items[] = { "File", "Edit", "View", "Help" };
				f32 menu_spacing = 10.0f;
				f32 menu_padding = 4.0f;
				u32 menu_background_color = 0xFF333333;
                ImVec2 menu_size = {50.0f, 25.0f};

                ImVec2 menu_pos = {text_pos.x + titlebar_text_size.x + menu_spacing, min_pos.y + 2.0f};
				ImGui::SetCursorScreenPos(menu_pos);
				if (ImGui::Button("File", menu_size))
					ImGui::OpenPopup("menu_file_popup");

				menu_pos.x += menu_size.x + menu_padding;
				ImGui::SetCursorScreenPos(menu_pos);
				if (ImGui::Button("Edit", menu_size))
					ImGui::OpenPopup("menu_file_popup");

				// menu bar popup
				if (ImGui::IsPopupOpen("menu_file_popup"))
				{
					if (ImGui::BeginMenu("File"))
					{
						if (ImGui::MenuItem("Open Scene"))
						{
							
						}

						ImGui::EndMenu();
					}
				}

                // ==================================
                // =========== ! Menu bar ============

				// buttons position
				f32 button_size = 24.0f;
				f32 button_spacing = 8.0f;
				ImVec2 close_btn_pos = ImVec2(max_pos.x - button_size - button_spacing, min_pos.y + 5);
				ImVec2 max_btn_pos = ImVec2(close_btn_pos.x - button_size - button_spacing, min_pos.y + 5);
				ImVec2 min_btn_pos = ImVec2(max_btn_pos.x - button_size - button_spacing, min_pos.y + 5);

				ImGui::SetCursorScreenPos(min_btn_pos);
				if (ImGui::ImageButton("_", m_icons["minimize"]->get_id(), {button_size, button_size}, {0.0f, 0.0f}, {1.0f, 1.0f}, {0.3f, 0.3f, 0.3f, 1.0f}))
				{
					SDL_MinimizeWindow(m_window.get_native_window());
				}

				ImGui::SetCursorScreenPos(max_btn_pos);
				SDL_WindowFlags sdl_window_flags = SDL_GetWindowFlags(m_window.get_native_window());
				bool window_maximized = sdl_window_flags & SDL_WINDOW_MAXIMIZED;
				if (ImGui::ImageButton("□", window_maximized ? m_icons["collapse_content"]->get_id() : m_icons["expand_content"]->get_id(), {button_size, button_size}, {0.0f, 0.0f}, {1.0f, 1.0f}, {0.9f, 0.4f, 0.0f, 1.0f}))
				{
					SDL_WindowFlags flags = SDL_GetWindowFlags(m_window.get_native_window());
					window_maximized ? SDL_RestoreWindow(m_window.get_native_window()) : SDL_MaximizeWindow(m_window.get_native_window());
				}

				ImGui::SetCursorScreenPos(close_btn_pos);
				if (ImGui::ImageButton("X", m_icons["close"]->get_id(), {button_size, button_size}, {0.0f, 0.0f}, {1.0f, 1.0f}, {0.9f, 0.0f, 0.0f, 1.0f}))
				{
					m_window.close_window();
				}

				// drag to move window
                static bool is_dragging = false;
				static ImVec2 drag_start_pos;
				static SDL_Point window_start_pos;

				ImGui::SetCursorScreenPos(min_pos);
				ImGui::InvisibleButton("TitleBarDrag", ImVec2(viewport->Size.x - 3 * (button_size + button_spacing), TITLE_BAR_HEIGHT));
			
				if (ImGui::IsItemActive() && !is_dragging && !menu_hovered)
				{
					is_dragging = true;
					drag_start_pos = ImGui::GetMousePos();
					i32 win_x, win_y;
					m_window.get_position(&win_x, &win_y);
					window_start_pos = { win_x, win_y };
                }

				if (is_dragging)
				{
					if (ImGui::IsMouseDown(ImGuiMouseButton_Left))
					{
                        ImVec2 mouse_pos = ImGui::GetMousePos();
                        ImVec2 mouse_delta = ImVec2(mouse_pos.x - drag_start_pos.x, mouse_pos.y - drag_start_pos.y);
                        m_window.set_position(window_start_pos.x + static_cast<i32>(mouse_delta.x),
                                              window_start_pos.y + static_cast<i32>(mouse_delta.y));
					}
                    else
                    {
                        is_dragging = false;
                    }
                }

				// dockspace
				ImGui::SetCursorScreenPos({viewport->Pos.x, viewport->Pos.y + TITLE_BAR_HEIGHT});
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
	if (is_viewport_hovered || !ImGui::GetIO().WantCaptureKeyboard)
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

	m_scene_hierarchy_panel->render();
	m_inspector_panel->render();
	m_content_browser_panel->render();
}

void IgnisEditor::resize() {
	if (m_viewport_size.x != m_viewport_framebuffer.get_width() || m_viewport_size.y != m_viewport_framebuffer.get_height())
	{
		m_viewport_framebuffer.resize(m_viewport_size.x, m_viewport_size.y);
		m_camera.resize({m_viewport_size.x, m_viewport_size.y});
	}
}

const Ref<Texture> &IgnisEditor::get_icons(const std::string &name)
{
	if (m_icons.contains(name))
		return m_icons[name];

	LOG_ASSERT(false, "Could not find icons : {}", name);
	return nullptr;
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

IgnisEditor *IgnisEditor::get()
{
	return s_instance;
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
