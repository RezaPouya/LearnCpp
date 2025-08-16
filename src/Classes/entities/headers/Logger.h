#pragma once
#include <iostream>
#include <string>
#include <mutex>  // For thread safety
#pragma once
#include <iostream>
#include <string>
#include <mutex>

namespace PouyaLogger {
    enum LogLevel : unsigned char {
        Information = 0,
        Warn = 1,  // Changed from 'Warn' to match usage
        Err = 2     // Changed from 'Err' to match usage
    };

    class Logger {
    private:
        LogLevel currentLogLevel;
        std::mutex logMutex;  // Added mutex for thread safety

        void Log(const std::string& message, LogLevel level) const;

    public:
        Logger() = delete; // this does not let someone to call default constructor
        //Logger() { currentLogLevel = Warn;}  

        explicit Logger(const LogLevel& logLevel) : currentLogLevel(logLevel){}


        void SetLogLevel(LogLevel level) {
            currentLogLevel = level;
        }

        void Info(const std::string& message) const ;
        void Warning(const std::string& message) const ;
        void Error(const std::string& message) const ;
    };
}