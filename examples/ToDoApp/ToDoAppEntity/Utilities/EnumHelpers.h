#include "../pch.h"
#include "../entities/headers/Enums.h"

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


	static std::string GetCategoryString(const OrderBy& en) {
		switch (en) {
			using enum OrderBy;
		case Id: return "Id";
		case Create: return "Create";
		case Completed: return "Completed";
		default: return "Unknown";
		}
	}


	static std::string GetCategoryString(const OrderByDirection& en) {
		switch (en) {
			using enum OrderByDirection;
		case Ascending: return "Ascending";
		case Descending: return "Descending";
		default: return "Unknown";
		}
	}
};