set(IGNIS_ENGINE_SOURCE
  src/core/application.cpp
  src/core/application.hpp
  src/core/uuid.cpp
  src/core/uuid.hpp
  src/core/utils.hpp
  src/core/window.cpp
  src/core/window.hpp
  src/core/buffer.hpp
  src/core/imgui_layer.cpp
  src/core/imgui_layer.hpp
  src/core/input/app_event.cpp
  src/core/input/app_event.hpp
  src/core/input/key_event.cpp
  src/core/input/key_event.hpp
  src/core/input/mouse_event.cpp
  src/core/input/mouse_event.hpp
  src/core/input/input.cpp
  src/core/input/input.hpp
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
  src/renderer/gl/gl_renderer_2d.hpp
  src/renderer/texture.hpp
  src/renderer/texture.cpp
  src/renderer/framebuffer.hpp
  src/renderer/framebuffer.cpp
  src/core/logger.hpp
  src/core/logger.cpp
  src/math/math.cpp
  src/math/math.hpp
  src/project/project.cpp
  src/project/project.hpp
  src/renderer/renderer.hpp
  src/renderer/renderer.cpp
  src/scene/entt.hpp
  src/renderer/gl/gl_buffer.cpp
  src/renderer/gl/gl_wrapper.hpp
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
  src/serializer/serializer.cpp
  src/serializer/serializer.hpp
  src/serializer/project_serializer.cpp
  src/serializer/project_serializer.hpp
  src/serializer/scene_serializer.cpp
  src/serializer/scene_serializer.hpp
  src/scripting/script_instance.cpp
  src/scripting/script_instance.hpp
)

include_directories(IgnisEditor ${INCLUDE_DIRS})

add_library(Ignis SHARED ${IGNIS_ENGINE_SOURCE})
set_target_properties(Ignis PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(Ignis PRIVATE SDL3::SDL3 glm glad imgui yaml-cpp)

add_custom_command(
    TARGET Ignis POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Ignis/Resources ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources
    
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Ignis/TestProject ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TestProject
)

option(BUILD_SHARED_IGNIS "Build Ignis as a shared library" ON)

if (BUILD_SHARED_IGNIS)
    add_compile_definitions(SHARED_BUILD)
endif()

target_compile_definitions(Ignis PRIVATE
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<CONFIG:Release>:RELEASE_BUILD>
    SHARED_BUILD
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ignis PROPERTY CXX_STANDARD 20)
endif()
