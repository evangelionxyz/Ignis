#include "serializer.hpp"

class Serializer::Impl
{
public:
    YAML::Emitter emitter;
    std::filesystem::path filepath;

    Serializer::Impl(const std::filesystem::path &path)
        : filepath(path)
    {
    }
};

Serializer::Serializer(const std::filesystem::path &filepath)
    : m_impl(new Serializer::Impl(filepath))
{
}

Serializer::~Serializer()
{
    if (m_impl)
        delete m_impl;
}

void Serializer::begin_map()
{
    m_impl->emitter << YAML::BeginMap;
}

void Serializer::begin_map(const std::string &name)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << YAML::BeginMap;
}

void Serializer::end_map()
{
    m_impl->emitter << YAML::EndMap;
}

void Serializer::begin_sequence()
{
    m_impl->emitter << YAML::BeginSeq;
}

void Serializer::begin_sequence(const std::string &name)
{
    m_impl->emitter << YAML::Key << name << YAML::BeginSeq;
}

void Serializer::end_sequence()
{
    m_impl->emitter << YAML::EndSeq;
}

void Serializer::serialize()
{
    std::ofstream output_file(m_impl->filepath);
    output_file << m_impl->emitter.c_str();
    output_file.close();
}

void Serializer::add_key_value_string(const std::string &name, const std::string &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_u64(const std::string &name, u64 value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_vec3(const std::string &name, const glm::vec3 &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_vec4(const std::string &name, const glm::vec4 &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_quat(const std::string &name, const glm::quat &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_float(const std::string &name, const f32 &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}

void Serializer::add_key_value_int(const std::string &name, const i32 &value)
{
    m_impl->emitter << YAML::Key << name << YAML::Value << value;
}


YAML::Node Serializer::deserialize(const std::filesystem::path &filepath)
{
    std::ifstream input_file(filepath);
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    input_file.close();

    return YAML::Load(buffer.str());
}

const std::filesystem::path &Serializer::get_filepath() const
{
    return m_impl->filepath;
}

YAML::Emitter &Serializer::get_emiiter() const
{
    return m_impl->emitter;
}
