#pragma once
#include <core/object.hpp>

class Scene : public Object {
public:
    Scene() = default;
    Scene(const std::string &name);

    void start_transition(const Ref<Scene> &next_scene);

    void destroy() override;

    static Ref<Scene> create(const std::string &name);

private:
    std::string m_name;
    Ref<Scene> m_next_scene;
};
