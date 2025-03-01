set(IGNIS_ENGINE_SOURCE
  src/core/application.hpp
  src/core/utils.hpp
  src/core/window.cpp
  src/core/window.hpp
  src/core/imgui_layer.cpp
  src/core/imgui_layer.hpp
  src/renderer/camera.cpp
  src/renderer/camera.hpp
  src/renderer/shader.cpp
  src/renderer/shader.hpp
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

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ignis PROPERTY CXX_STANDARD 20)
endif()
