#pragma once
#include "core/types.hpp"
#include <imgui.h>

#include "scene/entt.hpp"

enum InspectorState
{
    INSPECTOR_STATE_SCENE
};

class InspectorPanel
{
public:
    InspectorPanel();

    void render(f32 delta_time);
    void set_data(void *data, InspectorState state);

private:
    void draw_scene_inspector(f32 delta_time);

    InspectorState m_state = INSPECTOR_STATE_SCENE;
    void *m_data = nullptr;
};