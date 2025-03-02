#include "uuid.hpp"

#include <random>

static std::random_device s_random_device;
static std::mt19937_64 s_Engine(s_random_device());
static std::uniform_int_distribution<u64> s_uniform_distribution;

UUID::UUID()
    : m_uuid(s_uniform_distribution(s_Engine))
{
}

UUID::UUID(u64 uuid)
    : m_uuid(uuid)
{
}