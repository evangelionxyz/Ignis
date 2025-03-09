#include "serializer.hpp"

Serializer::Serializer(const std::filesystem::path &filepath)
    : m_filepath(filepath)
{
}

void Serializer::begin_map()
{
    m_emitter << YAML::BeginMap;
}

void Serializer::begin_map(const std::string &name)
{
    m_emitter << YAML::Key << name << YAML::Value << YAML::BeginMap;
}

void Serializer::end_map()
{
    m_emitter << YAML::EndMap;
}

void Serializer::begin_sequence()
{
    m_emitter << YAML::BeginSeq;
}

void Serializer::begin_sequence(const std::string &name)
{
    m_emitter << YAML::Key << name << YAML::BeginSeq;
}

void Serializer::end_sequence()
{
    m_emitter << YAML::EndSeq;
}

void Serializer::serialize()
{
    std::ofstream output_file(m_filepath);
    output_file << m_emitter.c_str();
    output_file.close();
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
    return m_filepath;
}