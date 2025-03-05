#pragma once
#include <core/application.hpp>
#include <core/base.hpp>
#include <core/window.hpp>

#include <core/input/event.hpp>
#include <core/input/key_event.hpp>
#include <core/input/app_event.hpp>
#include <core/input/mouse_event.hpp>
#include <core/input/input.hpp>
#include <core/logger.hpp>
#include <renderer/gl/gl_shader.hpp>
#include <renderer/gl/gl_framebuffer.hpp>
#include <renderer/gl/gl_vertex_array.hpp>
#include <renderer/gl/gl_buffer.hpp>
#include <renderer/gl/gl_index_buffer.hpp>
#include <renderer/gl/gl_vertex_buffer.hpp>
#include <renderer/gl/gl_texture.hpp>
#include <renderer/camera.hpp>
#include <renderer/renderer.hpp>
#include <core/imgui_layer.hpp>
#include <core/imgui_layer.hpp>
#include <scene/scene.hpp>
#include <scene/components.hpp>
#include <math/math.hpp>

#include <SDL3/SDL_gpu.h>
#include <glad/glad.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>