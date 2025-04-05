#pragma once

#include "core/types.hpp"
#include "core/uuid.hpp"
#include "math/math.hpp"

#include <glm/glm.hpp>
#include <fstream>
#include <filesystem>
#include <yaml-cpp/yaml.h>

namespace YAML
{
template<>
struct convert<UUID>
{
    static Node encode(const UUID uuid)
    {
        Node node;
        node.push_back(static_cast<u64>(uuid));
        return node;
    }

    static bool decode(const Node &node, UUID uuid)
    {
        uuid = node.as<u64>();
        return true;
    }
};

template<>
struct convert<Rect>
{
    static Node encode(const Rect &rect)
    {
        Node node;
        node.push_back(rect.get_min().x);
        node.push_back(rect.get_min().y);
        node.push_back(rect.get_max().x);
        node.push_back(rect.get_max().y);
        return node;
    }

    static bool decode(const Node &node, Rect &rect)
    {
        if (!node.IsSequence() || node.size() != 4)
            return false;
        
        rect.set_min({node[0].as<f32>(), node[1].as<f32>()});
        rect.set_max({node[2].as<f32>(), node[3].as<f32>()});
        return true;
    }
};

template <>
struct convert<glm::vec2>
{
	static Node encode(const glm::vec2 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		return node;
	}

	static bool decode(const Node &node, glm::vec2 &rhs)
	{
		if (!node.IsSequence() || node.size() != 2)
			return false;

		rhs.x = node[0].as<float>();
		rhs.y = node[1].as<float>();
		return true;
	}
};

template <>
struct convert<glm::vec3>
{
	static Node encode(const glm::vec3 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		node.push_back(rhs.z);
		return node;
	}

	static bool decode(const Node &node, glm::vec3 &rhs)
	{
		if (!node.IsSequence() || node.size() != 3)
			return false;

		rhs.x = node[0].as<float>();
		rhs.y = node[1].as<float>();
		rhs.z = node[2].as<float>();
		return true;
	}
};

template <>
struct convert<glm::vec4>
{
	static Node encode(const glm::vec4 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		node.push_back(rhs.z);
		node.push_back(rhs.w);
		return node;
	}

	static bool decode(const Node &node, glm::vec4 &rhs)
	{
		if (!node.IsSequence() || node.size() != 4)
			return false;

		rhs.x = node[0].as<float>();
		rhs.y = node[1].as<float>();
		rhs.z = node[2].as<float>();
		rhs.w = node[3].as<float>();
		return true;
	}
};

template <>
struct convert<glm::ivec2>
{
	static Node encode(const glm::ivec2 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		return node;
	}

	static bool decode(const Node &node, glm::ivec2 &rhs)
	{
		if (!node.IsSequence() || node.size() != 2)
			return false;

		rhs.x = node[0].as<int>();
		rhs.y = node[1].as<int>();
		return true;
	}
};

template <>
struct convert<glm::ivec3>
{
	static Node encode(const glm::ivec3 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		node.push_back(rhs.z);
		return node;
	}

	static bool decode(const Node &node, glm::ivec3 &rhs)
	{
		if (!node.IsSequence() || node.size() != 3)
			return false;

		rhs.x = node[0].as<int>();
		rhs.y = node[1].as<int>();
		rhs.z = node[2].as<int>();
		return true;
	}
};

template <>
struct convert<glm::ivec4>
{
	static Node encode(const glm::ivec4 &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		node.push_back(rhs.z);
		node.push_back(rhs.w);
		return node;
	}

	static bool decode(const Node &node, glm::ivec4 &rhs)
	{
		if (!node.IsSequence() || node.size() != 4)
			return false;

		rhs.x = node[0].as<int>();
		rhs.y = node[1].as<int>();
		rhs.z = node[2].as<int>();
		rhs.w = node[3].as<int>();
		return true;
	}
};

template <>
struct convert<glm::quat>
{
	static Node encode(const glm::quat &rhs)
	{
		Node node;
		node.push_back(rhs.x);
		node.push_back(rhs.y);
		node.push_back(rhs.z);
		node.push_back(rhs.w);
		return node;
	}

	static bool decode(const Node &node, glm::quat &rhs)
	{
		if (!node.IsSequence() || node.size() != 4)
			return false;

		rhs.x = node[0].as<float>();
		rhs.y = node[1].as<float>();
		rhs.z = node[2].as<float>();
		rhs.w = node[3].as<float>();
		return true;
	}
};
}

static YAML::Emitter &operator<<(YAML::Emitter &out, const Rect &rect)
{
	out << YAML::Flow;
	out << YAML::BeginSeq << rect.get_min().x << rect.get_min().y << rect.get_max().x << rect.get_max().y << YAML::EndSeq;
	return out;
}

static YAML::Emitter &operator<<(YAML::Emitter &out, const glm::vec2 &v)
{
	out << YAML::Flow;
	out << YAML::BeginSeq << v.x << v.y << YAML::EndSeq;
	return out;
}

static YAML::Emitter &operator<<(YAML::Emitter &out, const glm::vec3 &v)
{
	out << YAML::Flow;
	out << YAML::BeginSeq << v.x << v.y << v.z << YAML::EndSeq;
	return out;
}

static YAML::Emitter &operator<<(YAML::Emitter &out, const glm::vec4 &v)
{
	out << YAML::Flow;
	out << YAML::BeginSeq << v.x << v.y << v.z << v.w << YAML::EndSeq;
	return out;
}

static YAML::Emitter &operator<<(YAML::Emitter &out, const glm::quat &q)
{
	out << YAML::Flow;
	out << YAML::BeginSeq << q.x << q.y << q.z << q.w << YAML::EndSeq;
	return out;
}

class IGNIS_API Serializer
{
public:
    Serializer() = default;
	~Serializer();

    Serializer(const std::filesystem::path &filepath);

    void begin_map();
    void begin_map(const std::string &name);
    void end_map();

    void begin_sequence();
    void begin_sequence(const std::string &name);
    void end_sequence();

	void add_key_value_string(const std::string &name, const std::string &value);
	void add_key_value_u64(const std::string &name, u64 value);
	void add_key_value_vec3(const std::string &name, const glm::vec3 &value);
	void add_key_value_vec4(const std::string &name, const glm::vec4 &value);
	void add_key_value_quat(const std::string &name, const glm::quat &value);
	void add_key_value_float(const std::string &name, const f32 &value);
	void add_key_value_int(const std::string &name, const i32 &value);

    template<typename T>
    void add_key_value(const char *key_name, T value)
    {
        get_emiiter() << YAML::Key << key_name << YAML::Value << value;
    }

    void serialize();
    static YAML::Node deserialize(const std::filesystem::path &filepath);

	YAML::Emitter &get_emiiter() const;

    const std::filesystem::path &get_filepath() const;

private:
	class Impl;
	Impl *m_impl;
};