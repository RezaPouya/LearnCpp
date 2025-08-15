//#include "../headers/Logger.h"
//#include "../headers/TypeDefinition.h"
//
//namespace Logger {
//    // Base case for recursion - does nothing
//    void LogInternal(std::ostream&) {}
//
//    // Recursive case - processes each argument
//    template<typename T, typename... Args>
//    void LogInternal(std::ostream& os, T&& first, Args&&... rest) {
//        os << std::forward<T>(first);
//        LogInternal(os, std::forward<Args>(rest)...);
//    }
//
//    // Main logging function implementation
//    template<typename... Args>
//    void Log(Args&&... args, const char* endline) {
//        std::ostringstream oss;
//        LogInternal(oss, std::forward<Args>(args)...);
//        std::cout << oss.str() << endline;
//    }
//
//    // Separator version implementation
//    template<typename... Args>
//    void LogWithSeparator(const char* separator, Args&&... args, const char* endline) {
//        std::ostringstream oss;
//        bool first = true;
//        // Lambda to handle separation
//        auto print = [&](const auto& arg) {
//            if (!first) oss << separator;
//            oss << arg;
//            first = false;
//            };
//        // Print each argument with separator
//        (print(args), ...);
//        std::cout << oss.str() << endline;
//    }
//
//    // Explicit template instantiation for common types
//    template void Log<>(const char*, const char*);
//    template void Log<>(bigint, const char*);
//    template void Log<>(const char*, bigint, const char*);
//}