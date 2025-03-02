set(IGNIS_ENGINE_SOURCE
  src/core/application.hpp
  src/core/uuid.cpp
  src/core/uuid.hpp
  src/core/utils.hpp
  src/core/window.cpp
  src/core/window.hpp
  src/core/buffer.hpp
  src/core/imgui_layer.cpp
  src/core/input/input.cpp
  src/core/input/input.hpp
  src/core/imgui_layer.hpp
  src/renderer/camera.cpp
  src/renderer/camera.hpp
  src/renderer/gl/gl_buffer.hpp
  src/renderer/gl/gl_shader.cpp
  src/renderer/gl/gl_shader.hpp
  src/renderer/gl/gl_framebuffer.cpp
  src/renderer/gl/gl_framebuffer.hpp
  src/renderer/gl/gl_vertex_array.cpp
  src/renderer/gl/gl_vertex_array.hpp
  src/renderer/gl/gl_vertex_buffer.cpp
  src/renderer/gl/gl_vertex_buffer.hpp
  src/renderer/gl/gl_index_buffer.cpp
  src/renderer/gl/gl_index_buffer.hpp
  src/renderer/gl/gl_texture.cpp
  src/renderer/gl/gl_texture.hpp
  src/renderer/texture.hpp
  src/renderer/texture.cpp
  src/renderer/framebuffer.hpp
  src/renderer/framebuffer.cpp
  src/core/logger.hpp
  src/core/logger.cpp
  src/math/math.hpp
  src/math/math.cpp
  src/renderer/renderer.hpp
  src/renderer/renderer.cpp
  src/scene/entt.hpp
  src/scene/scene.cpp
  src/scene/scene.hpp
  src/scene/scene_manager.cpp
  src/scene/scene_manager.hpp
  src/scene/components.cpp
  src/scene/components.hpp
  src/ignis_engine.hpp
  src/assets/asset_manager.cpp
  src/assets/asset_manager.hpp
  src/assets/asset.cpp
  src/assets/asset.hpp
        src/renderer/gl/gl_wrapper.hpp
)

include_directories(IgnisEditor ${INCLUDE_DIRS})

add_library(Ignis STATIC ${IGNIS_ENGINE_SOURCE})
set_target_properties(Ignis PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(Ignis PRIVATE SDL3::SDL3 glm glad imgui)

add_custom_command(
    TARGET Ignis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Ignis/Resources ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources
)

target_compile_definitions(Ignis PRIVATE
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<CONFIG:Release>:RELEASE_BUILD>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ignis PROPERTY CXX_STANDARD 20)
endif()
