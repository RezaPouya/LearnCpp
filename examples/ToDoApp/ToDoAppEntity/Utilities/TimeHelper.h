#pragma once
#include "../pch.h"

namespace MyUtilities {
    class TimeHelper {
    private:
        static inline std::mutex timeMutex;

    public:
        // Calendar and timezone support
        static std::string GetCurrentTimeWithTimezone() {
            std::scoped_lock lock(timeMutex);
            auto now = std::chrono::system_clock::now();
            return std::format("{:%Y-%m-%d %H:%M:%S %Z}", now);
        }

        // Fixed: Use explicit format string types
        template <typename... Args>
        static std::string GetCustomFormat(std::format_string<Args...> fmt, Args&&... args) {
            std::scoped_lock lock(timeMutex);
            return std::format(fmt, std::forward<Args>(args)...);
        }

        // TimePoint formatter - simplified
        static std::string FormatTimePoint(const std::chrono::system_clock::time_point& tp) {
            std::scoped_lock lock(timeMutex);
            return std::format("{:%Y-%m-%d %H:%M:%S}", tp);
        }

        // Precision formatting with proper compile-time format
        static std::string FormatWithPrecision(const std::chrono::system_clock::time_point& tp) {
            std::scoped_lock lock(timeMutex);
            
            // Separate the time point into seconds and milliseconds
            auto since_epoch = tp.time_since_epoch();
            auto seconds = std::chrono::duration_cast<std::chrono::seconds>(since_epoch);
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch - seconds);
            
            // Format using compile-time known format string
            return std::format("{:%Y-%m-%d %H:%M:%S}.{:03}",
                std::chrono::system_clock::time_point(seconds),
                milliseconds.count());
        }

        // Compile-time known format variations
        static std::string GetIsoFormat() {
            std::scoped_lock lock(timeMutex);
            auto now = std::chrono::system_clock::now();
            return std::format("{:%FT%TZ}", now);
        }

        static std::string GetShortDate() {
            std::scoped_lock lock(timeMutex);
            auto now = std::chrono::system_clock::now();
            return std::format("{:%Y-%m-%d}", now);
        }

        // Alternative: Runtime format string (use with caution)
        static std::string GetRuntimeFormat(std::string_view fmt) {
            std::scoped_lock lock(timeMutex);
            auto now = std::chrono::system_clock::now();
            return std::vformat(fmt, std::make_format_args(now));
        }
    };
}