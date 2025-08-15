#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "TypeDefinition.h"

namespace Logger {
    // Implementation (moved to header for templates)
    namespace detail {
        inline void LogInternal(std::ostream&) {}

        template<typename T, typename... Args>
        void LogInternal(std::ostream& os, T&& first, Args&&... rest) {
            os << std::forward<T>(first);
            LogInternal(os, std::forward<Args>(rest)...);
        }
    }

    // Main logging function
    template<typename... Args>
    void Log(Args&&... args) {
        std::ostringstream oss;
        detail::LogInternal(oss, std::forward<Args>(args)...);
        std::cout << oss.str() ;
    }

    //// Version with custom separator
    //template<typename... Args>
    //void LogWithSeparator(const char* separator, Args&&... args) {
    //    std::ostringstream oss;
    //    bool first = true;
    //    auto print = [&](const auto& arg) {
    //        if (!first) oss << separator;
    //        oss << arg;
    //        first = false;
    //        };
    //    (print(args), ...);
    //    std::cout << oss.str() ;
    //}
}