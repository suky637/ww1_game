#ifndef CORE_LOGGING_H
#define CORE_LOGGING_H

#include <cstdio>

#include "fmt/core.h"


enum class LogLevel {
    Disable,
    Error,
    Warning,
    Trace
};
extern LogLevel gLogLevel;

extern FILE *gLogFile;


using LogCallbackFunc = void(*)(void *userptr, char level, const char *message, int length) noexcept;

void al_set_log_callback(LogCallbackFunc callback, void *userptr);


#ifdef __MINGW32__
[[gnu::format(__MINGW_PRINTF_FORMAT,2,3)]]
#else
[[gnu::format(printf,2,3)]]
#endif
void al_print(LogLevel level, const char *fmt, ...) noexcept;

#define TRACE(...) al_print(LogLevel::Trace, __VA_ARGS__)

#define WARN(...) al_print(LogLevel::Warning, __VA_ARGS__)

#define ERR(...) al_print(LogLevel::Error, __VA_ARGS__)


void al_printfmt_impl(LogLevel level, const std::string &msg);

template<typename ...Args>
void al_printfmt(LogLevel level, fmt::format_string<Args...> fmt, Args&& ...args) noexcept
try {
    al_printfmt_impl(level, fmt::format(std::move(fmt), std::forward<Args>(args)...));
} catch(...) { }

#define TRACEFMT(...) al_printfmt(LogLevel::Trace, __VA_ARGS__)

#define WARNFMT(...) al_printfmt(LogLevel::Warning, __VA_ARGS__)

#define ERRFMT(...) al_printfmt(LogLevel::Error, __VA_ARGS__)

#endif /* CORE_LOGGING_H */
