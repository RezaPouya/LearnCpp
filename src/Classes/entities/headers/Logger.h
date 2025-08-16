#pragma once
#include <iostream>
#include <string>
#include <mutex>  // For thread safety

namespace PouyaLogger {
    enum LogLevel : unsigned char
    {
        Information = 0,
        Warn = 1,
        Err = 2
    };

    class Logger {
    private:
        LogLevel currentLogLevel;

        // Helper function for actual logging
        void Log(const std::string& message, LogLevel level);

    public:
        Logger() {
            currentLogLevel = Warning
        };

        void SetLogLevel(LogLevel level) {
            currentLogLevel = level;
        }

        // Public logging methods
        void Info(const char* message);
        void Warning(const char* message);
        void Error(const char* message);
    };
}