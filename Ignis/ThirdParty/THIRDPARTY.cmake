# IMGUI
set(IMGUI_SOURCE
        ${THIRDPARTY_DIR}/IMGUI/imgui.cpp
        ${THIRDPARTY_DIR}/IMGUI/imgui.h
        ${THIRDPARTY_DIR}/IMGUI/imgui_demo.cpp
        ${THIRDPARTY_DIR}/IMGUI/imgui_draw.cpp
        ${THIRDPARTY_DIR}/IMGUI/imgui_tables.cpp
        ${THIRDPARTY_DIR}/IMGUI/imgui_widgets.cpp
        ${THIRDPARTY_DIR}/IMGUI/backends/imgui_impl_sdl3.cpp
        ${THIRDPARTY_DIR}/IMGUI/backends/imgui_impl_sdlgpu3.cpp
        ${THIRDPARTY_DIR}/IMGUI/backends/imgui_impl_sdlrenderer3.cpp
        ${THIRDPARTY_DIR}/IMGUI/backends/imgui_impl_vulkan.cpp
        ${THIRDPARTY_DIR}/IMGUI/backends/imgui_impl_opengl3.cpp
)

include_directories(imgui
        ${THIRDPARTY_DIR}/IMGUI
        ${THIRDPARTY_DIR}/SDL3/include
        ${VULKAN_INCLUDE_DIR}
)
add_library(imgui ${IMGUI_SOURCE})
target_link_libraries(imgui SDL3::SDL3)

# GLAD
add_library(glad STATIC ${THIRDPARTY_DIR}/GLAD/src/glad.c)
include_directories(glad ${THIRDPARTY_DIR}/GLAD/include)