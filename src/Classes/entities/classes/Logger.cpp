#include "../headers/Logger.h"
#include "../headers/PouyaTime.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>


namespace PouyaLogger {

	void Logger::Log(const std::string& message, LogLevel level) const 
	{
		if (level < currentLogLevel) {
			return;
		}

		std::cout << std::endl;
		switch (level) {
		case Information: std::cout << "[INFO] "; break;
		case Warn: std::cout << "[WARN] ";break;
		case Err: std::cout << "[ERROR] ";break;
		}

		std::cout << PouyaTime::TimeHelper::GetCurrentTimeWithPrecision() << " : " << message << std::endl;
	}

	void Logger::Info(const std::string& message) const {
		Log(message, Information);
	}

	void Logger::Warning(const std::string& message) const {
		Log(message, Warn);
	}

	void Logger::Error(const std::string& message) const {
		Log(message, Err);
	}
}