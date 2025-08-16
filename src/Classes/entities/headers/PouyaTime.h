#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <string>

namespace PouyaTime {
	class TimeHelper {
	public:
		static std::string GetCurrentTime() {
			static std::mutex timeMutex;  // Static mutex for thread safety

			// Thread-safe locking
			std::scoped_lock<std::mutex> lock(timeMutex);

			// Get current time
			auto now = std::chrono::system_clock::now();
			std::time_t now_time = std::chrono::system_clock::to_time_t(now);

			// Safe time conversion
			struct tm tm;
			localtime_s(&tm, &now_time);  // Windows-safe version

			// Format the time into a string stream
			std::ostringstream oss;
			oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S:") << "] ";

			return oss.str();
		};



		static std::string GetCurrentTimeWithPrecision() {
			static std::mutex timeMutex;
			std::lock_guard<std::mutex> lock(timeMutex);

			// Get the current time with high precision
			auto now = std::chrono::system_clock::now();
			auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
			auto fraction = now - seconds;

			// Convert to time_t for the date/time components
			std::time_t now_time = std::chrono::system_clock::to_time_t(now);

			// Safe time conversion (Windows)
			struct tm tm;
#if defined(_WIN32)
			localtime_s(&tm, &now_time);
#else
			localtime_r(&now_time, &tm);  // POSIX
#endif

			// Extract milliseconds and nanoseconds
			auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction).count() % 1000;
			auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(fraction).count() % 1000000;

			// Format the output string
			std::ostringstream oss;
			oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S")
				<< "." << std::setfill('0') << std::setw(3) << milliseconds
				<< ":" << std::setw(6) << nanoseconds
				<< "]";

			return oss.str();
		}
	};
}
