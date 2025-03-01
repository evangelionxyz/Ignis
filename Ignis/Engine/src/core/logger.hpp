#pragma once

#include "types.hpp"
#include "base.hpp"

#include <filesystem>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

class Logger {
public:
    static void init();
    static void shutdown();
    static Ref<spdlog::async_logger> &get_logger() { return s_logger; }

private:
    static Ref<spdlog::async_logger> s_logger;
    static Ref<spdlog::sinks::stdout_color_sink_mt> s_console_sink;
};

namespace fmt {

template<>
struct formatter<std::filesystem::path>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext &ctx)
    {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(const std::filesystem::path &filepath, FormatContext &ctx) const
    {
        return fmt::format_to(ctx.out(), "{}", filepath.generic_string());
    }
};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

#ifdef PLATFORM_WINDOWS
#define LOG_ERROR(...)     Logger::get_logger()->error(__VA_ARGS__)
#define LOG_WARN(...)      Logger::get_logger()->warn(__VA_ARGS__)
#define LOG_INFO(...)      Logger::get_logger()->info(__VA_ARGS__)
#define LOG_TRACE(...)     Logger::get_logger()->trace(__VA_ARGS__)
#define LOG_CRITICAL(...)  Logger::get_logger()->critical(__VA_ARGS__)
#else
#define LOG_ERROR(...)
#define LOG_WARN(...)
#define LOG_INFO(...)
#define LOG_TRACE(...)
#define LOG_CRITICAL(...)
#endif

#ifdef DEBUG_BUILD
// Assert with condition and additional arguments
#define LOG_ASSERT(check, ...) \
do { \
    if(!(check)) { \
        LOG_ERROR(__VA_ARGS__); \
        DEBUGBREAK(); \
    } \
} while(0)

// Assert with only condition
#define LOG_ASSERT_SIMPLE(check) \
do { \
    if(!(check)) { \
        LOG_ERROR("Assertion '{0}' failed at {1}:{2}", #check, __FILE__, __LINE__); \
        DEBUGBREAK(); \
    } \
} while(0)
#else
#define LOG_ASSERT(...)
#define LOG_ASSERT_SIMPLE(check)
#endif