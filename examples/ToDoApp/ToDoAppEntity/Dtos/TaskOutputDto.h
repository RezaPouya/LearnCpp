#include "../pch.h"

#include "../entities/headers/Enums.h"
#include "../Utilities/EnumHelpers.h"

struct TaskOutputDto {
	int Id;
	bool IsDone = false;
	std::string Category;
	std::string Title;
	std::string Content;
	std::chrono::time_point<std::chrono::system_clock> CreatedAt;
	std::chrono::time_point<std::chrono::system_clock> LastUpdatedAt;
	std::optional<std::chrono::time_point<std::chrono::system_clock>> DoneAt;
	std::string Status = getStatusString(IsDone);

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


	TaskOutputDto(const Task& task)
		: Id(task.GetId()),
		IsDone(task.GetIsDone()), 
		Category(EnumHelper::GetCategoryString(task.GetCategory())),
		Title(task.GetTitle()), 
		Content(task.GetContent()), 
		CreatedAt(task.GetCreatedAt()), 
		LastUpdatedAt(task.GetLastUpdatedAt()),
		DoneAt(task.GetDoneAt()) {
	}

private:
	std::string getStatusString(bool isDone) const {
		return  isDone ? "Completed" : "Pending";
	}
};