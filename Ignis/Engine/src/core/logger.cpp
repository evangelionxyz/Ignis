#include "logger.hpp"
#include <spdlog/spdlog.h>

class LoggerImpl
{
public:
    Ref<spdlog::async_logger> logger;
    Ref<spdlog::sinks::stdout_color_sink_mt> console_sink;
};

static LoggerImpl *logger_impl = nullptr; 

void Logger::init() {
    logger_impl = new LoggerImpl();

    spdlog::init_thread_pool(8192, 1);

    logger_impl->console_sink = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    logger_impl->console_sink->set_pattern("%^[%T] %n: %v%$");

    logger_impl->logger = CreateRef<spdlog::async_logger>(
        "[ignis]",
        logger_impl->console_sink,
        spdlog::thread_pool(),
        spdlog::async_overflow_policy::block
    );

    //s_console_sink->set_level(spdlog::level::trace);
}

void Logger::shutdown() {
    logger_impl->logger.reset();
    logger_impl->console_sink.reset();

    spdlog::shutdown();
}

spdlog::async_logger *Logger::get_logger()
{
    return logger_impl->logger.get();
}