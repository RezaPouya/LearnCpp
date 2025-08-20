#include <string>
#include <chrono>
#include "../entities/headers/TaskCategory.h"
#include "../Utilities/EnumHelpers.h"

struct TaskOutputDto {
	int Id;
	bool IsDone = false;
	std::string Category;
	std::string Title;
	std::string Content;
	std::chrono::time_point<std::chrono::system_clock> CreatedAt;
	std::chrono::time_point<std::chrono::system_clock> LastUpdatedAt;
	std::chrono::time_point<std::chrono::system_clock> DoneAt;
	std::string Status;

public:
	TaskOutputDto(int id,
		bool isDone,
		const TaskCategory& category,
		const std::string& title,
		const std::string& content,
		const std::chrono::time_point<std::chrono::system_clock>& createdAt,
		const std::chrono::time_point<std::chrono::system_clock>& lastUpdatedAt,
		const std::chrono::time_point<std::chrono::system_clock>& doneAt)
		: Id(id), IsDone(isDone), Category(EnumHelper::GetCategoryString(category)),
		Title(title), Content(content), CreatedAt(createdAt), LastUpdatedAt(lastUpdatedAt),
		DoneAt(doneAt), Status(getStatusString(isDone)) {
	}

private:
	std::string getStatusString(bool isDone) const {
		return  isDone ? "Completed" : "Pending";
	}
};