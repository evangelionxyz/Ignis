#include "logger.hpp"
#include <spdlog/spdlog.h>

void Logger::init() {
    spdlog::init_thread_pool(8192, 1);

    s_console_sink = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    s_console_sink->set_pattern("%^[%T] %n: %v%$");

    s_logger = CreateRef<spdlog::async_logger>(
        "[ignis]",
        s_console_sink,
        spdlog::thread_pool(),
        spdlog::async_overflow_policy::block
    );

    //s_console_sink->set_level(spdlog::level::trace);
}

void Logger::shutdown() {
    spdlog::shutdown();
}

Ref<spdlog::async_logger> Logger::s_logger;
Ref<spdlog::sinks::stdout_color_sink_mt> Logger::s_console_sink;