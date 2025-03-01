#include "ignis.hpp"

IgnisEditor::IgnisEditor()
	: Application("Ignis")
{
	m_window = Window(m_name, 1280, 720);
	m_window.set_event_callback(BIND_CLASS_EVENT_FN(IgnisEditor::on_event));

	uint32_t vertex_shader = Shader::create_shader("Resources/Shaders/default.vert.glsl", SHADER_TYPE_VERTEX);
	uint32_t fragment_shader = Shader::create_shader("Resources/Shaders/default.frag.glsl", SHADER_TYPE_FRAGMENT);

	m_shader.create_program();
	m_shader.compile(vertex_shader);
	m_shader.compile(fragment_shader);
	m_shader.link();
}

void IgnisEditor::run()
{
	f32 last_frame_time = 0.0f;
	
	while (m_window.is_running())
	{
		m_window.poll_events();

		f32 current_time = static_cast<f32>(SDL_GetTicks());
		f32 delta_time = (current_time - last_frame_time) / 1000.0f;
		last_frame_time = current_time;

		on_update(delta_time);

		m_window.swap_buffers();
	}
}

void IgnisEditor::on_event(Event &event)
{
}

void IgnisEditor::on_update(f32 delta_time)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	m_shader.use();
	m_shader.set_uniform_vec3("u_color", glm::vec3(1.0f, 0.0f, 1.0f));
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void IgnisEditor::destroy()
{
	m_window.destroy();
	m_shader.destroy();
}

int main()
{
	IgnisEditor editor;
	editor.run();
	editor.destroy();

	return 0;
}
