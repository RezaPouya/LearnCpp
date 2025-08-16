#include "../headers/Logger.h"
#include "../headers/PouyaTime.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>


namespace PouyaLogger {

	void Logger::Log(const std::string& message, LogLevel level)
	{
		if (level < currentLogLevel) {
			return;
		}

		std::cout << std::endl;
		switch (level) {
		case Information:
			std::cout << "[INFO] ";
			break;
		case Warn:
			std::cout << "[WARN] ";
			break;
		case Err:
			std::cout << "[ERROR] ";
			break;
		}

		std::cout << PouyaTime::TimeHelper::GetCurrentTimeWithPrecision() << " : " << message << std::endl;
	}

	void Logger::Info(const char* message) {
		Log(message, Information);
	}

	void Logger::Warning(const char* message) {
		Log(message, Warn);
	}

	void Logger::Error(const char* message) {
		Log(message, Err);
	}


	std::string GetCurrentTime() 
	{
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
		oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

		return oss.str();
	}
}