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
		std::cout << oss.str();
	}

	// Version with endline control
	template<typename... Args>
	void LogLine(Args&&... args) {
		Log(std::forward<Args>(args)..., "\n");
	}
}