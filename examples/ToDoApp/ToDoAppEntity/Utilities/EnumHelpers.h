#pragma once
#include <string>
#include "../entities/headers/NoteCategory.h"

struct EnumHelper {
	static std::string GetCategoryString(const NoteCategory& category ) {
		switch (category) {
		using enum NoteCategory;
		case Personal: return "Personal";
		case Work: return "Work";
		case Learning: return "Learning";
		default: return "Unknown";
		}
	}
};