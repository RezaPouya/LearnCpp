#pragma once
#include <string>
#include "../entities/headers/TaskCategory.h"

struct EnumHelper {
	static std::string GetCategoryString(const TaskCategory& category ) {
		switch (category) {
		using enum TaskCategory;
		case Personal: return "Personal";
		case Work: return "Work";
		case Learning: return "Learning";
		default: return "Unknown";
		}
	}
};