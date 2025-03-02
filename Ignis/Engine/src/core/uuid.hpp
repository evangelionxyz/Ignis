#pragma once

#include "types.hpp"

#include <functional>
#include <string>

class UUID
{
public:
    UUID();
    UUID(u64 uuid);
    UUID(const UUID &uuid) = default;
    operator u64() const { return m_uuid; }
private:
    u64 m_uuid;
};

template<>
struct std::hash<UUID>
{
std::size_t operator() (const UUID& uuid) const noexcept
{
    return hash<u64>()(uuid);
}
};
