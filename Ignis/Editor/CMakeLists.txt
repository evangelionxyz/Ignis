set(IGNIS_EDITOR_SOURCE
  src/ignis.cpp 
  src/ignis.hpp
)
add_executable (IgnisEditor ${IGNIS_EDITOR_SOURCE})

include_directories(IgnisEditor ${INCLUDE_DIRS})

target_link_libraries(IgnisEditor Ignis SDL3::SDL3 glm glad imgui)

target_compile_definitions(IgnisEditor PRIVATE
        $<$<CONFIG:Debug>:DEBUG_BUILD>
        $<$<CONFIG:Release>:RELEASE_BUILD>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET IgnisEditor PROPERTY CXX_STANDARD 20)
endif()
