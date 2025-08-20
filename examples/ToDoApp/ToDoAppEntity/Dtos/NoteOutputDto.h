#include <string>
#include <chrono>
#include "../entities/headers/NoteCategory.h"
#include "../Utilities/EnumHelpers.h"

struct NoteOutputDto {
	int Id;
	std::string Category;
	std::string Title;
	std::string Content;
	std::chrono::time_point<std::chrono::system_clock> CreatedAt;
	std::chrono::time_point<std::chrono::system_clock> LastUpdatedAt;

public:
	NoteOutputDto(int id,
		const NoteCategory& category,
		const std::string& title,
		const std::string& content,
		const std::chrono::time_point<std::chrono::system_clock>& createdAt,
		const std::chrono::time_point<std::chrono::system_clock>& lastUpdatedAt)
		: Id(id), Category(EnumHelper::GetCategoryString(category)), Title(title), Content(content),
		CreatedAt(createdAt), LastUpdatedAt(lastUpdatedAt){ }
};