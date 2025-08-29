#include "../pch.h"
#include "TaskManager.h"

static bool IsAscending(const OrderByDirection& orderByDirection) {
	return orderByDirection == OrderByDirection::Ascending;
}

TaskManager& TaskManager::GetInstance() {
	static TaskManager instance;
	return instance;
}

int TaskManager::GetLastId() const {
	if (m_Tasks.empty()) {
		return 0; // Return 0 if no tasks exist
	}

	// Find the maximum ID in the vector
	auto it = std::max_element(m_Tasks.begin(), m_Tasks.end(),
		[](const Task& a, const Task& b) {
			return a.GetId() < b.GetId();
		});

	return it->GetId();
}

int TaskManager::GetNextAvailableId() const {
	return GetLastId() + 1;
}

const std::optional<TaskOutputDto> TaskManager::GetById(int id) const {

	auto task = std::find_if(m_Tasks.begin(), m_Tasks.end(),
		[id](const Task& task) {
			return task.GetId() == id;
		});

	if (task == m_Tasks.end()) {
		return std::nullopt;
	}

	return TaskOutputDto(*task);
}

const std::optional<Task> TaskManager::FindTaskById(int id) const {

	auto task = std::find_if(m_Tasks.begin(), m_Tasks.end(),
		[id](const Task& task) {
			return task.GetId() == id;
		});

	if (task == m_Tasks.end()) {
		return std::nullopt;
	}

	return *task;
}

const std::vector<TaskOutputDto> TaskManager::GetList(OrderBy orderBy,
	OrderByDirection orderByDirection) const {

	std::vector<TaskOutputDto> result;

	for (auto& t : m_Tasks) {
		result.push_back(TaskOutputDto(t));
	}

	std::sort(result.begin(), result.end(), [orderBy, orderByDirection](const TaskOutputDto& a,
		const TaskOutputDto& b) {
			switch (orderBy) {
			case OrderBy::Id: {
				return IsAscending(orderByDirection) ? a.Id < b.Id : a.Id > b.Id;
			}; //OrderBy::Id
			case OrderBy::Create: {
				return IsAscending(orderByDirection) ?
					a.CreatedAt < b.CreatedAt :
					a.CreatedAt > b.CreatedAt;
			}; //OrderBy::Create
			case OrderBy::Completed: {
				return IsAscending(orderByDirection) ?
					a.DoneAt.value() < b.DoneAt.value() :
					a.DoneAt.value() > b.DoneAt.value();
			}; //OrderBy::Id:
			default:  return a.Id < b.Id;
			}
		});

	return result;
}

Task* TaskManager::FindById(int id) {
	auto it = std::find_if(m_Tasks.begin(), m_Tasks.end(),
		[id](const Task& task) {
			return task.GetId() == id;
		});

	if (it != m_Tasks.end()) {
		return  &(*it); // return task
	}

	return nullptr;
}

//Task* TaskManager::FindById(int id) {
//
//	auto it = std::find_if(m_Tasks.begin(), m_Tasks.end(),
//		[id](const Task& task) {
//			return task.GetId() == id;
//		});
//
//	return (it != m_Tasks.end()) ? &(*it) : nullptr;
//}

std::optional<Task*> TaskManager::Add(const std::string& title,
	const std::optional<std::string>& content,
	TaskCategory category) {

	int id = GetNextAvailableId();

	// Create task with content if provided, otherwise use empty string
	std::string taskContent = content.has_value() ? content.value() : "";

	// Create the task (assuming Task constructor takes id, title, content)
	Task newTask(id, title, taskContent, category);

	try {
		// Generate a new ID
		int newId = m_Tasks.empty() ? 1 : m_Tasks.back().GetId() + 1;

		// Create the task with proper content handling
		std::string taskContent = content.has_value() ? content.value() : "";

		// Create and add the new task directly in the vector
		m_Tasks.emplace_back(newId, title, taskContent, category);

		// Return pointer to the last element (the newly added task)
		return &m_Tasks.back();
	}
	catch (const std::exception& e) {
		std::cerr << "Error adding task: " << e.what() << std::endl;
		return std::nullopt;
	}
}




std::optional<TaskOutputDto> TaskManager::Edit(int id,
	const std::string& title,
	const std::optional<std::string>& content,
	TaskCategory category )
{
	auto task = FindById(id);

	if (!task) {
		return std::nullopt; // Task not found
	}

	// Update the task
	task->SetTitle(title);

	if (content.has_value()) {
		task->SetContent(content.value());
	}

	task->SetCategory(category);

	// Return the updated task as DTO
	return TaskOutputDto(*task);
}

bool TaskManager::RemoveById(int id) {
	//auto it = std::remove_if(m_Tasks.begin(), m_Tasks.end(),
	//	[id](const Task& task) {
	//		return task.GetId() == id;
	//	});

	//m_Tasks.erase(it, m_Tasks.end());
	{
		auto task = FindById(id);

		if (!task)
			return false;
	}
	
	std::erase_if(m_Tasks, [id](const Task& task) {return task.GetId() == id;});

	return true;
}

void TaskManager::ToggleById(int id) {
	
	auto task = FindById(id);

	if (task) {
		task->ToggleDone();
	}
}

size_t TaskManager::GetTaskCount() const {
	return m_Tasks.size();
}

size_t TaskManager::GetCompletedCount() const {

	return std::count_if(m_Tasks.begin(), m_Tasks.end(),
		[](const Task& task) {
			return task.IsDone();
		});
}

size_t TaskManager::GetPendingCount() const {
	return std::count_if(m_Tasks.begin(), m_Tasks.end(),
		[](const Task& task) {
			return !task.IsDone();
		});
}

std::vector<TaskOutputDto> TaskManager::GetCompletedTasks() const {
	std::vector<TaskOutputDto> completedTasks;

	for (const auto& task : m_Tasks) {
		if (task.IsDone()) {
			// Create TaskOutputDto and store pointers (requires storing DTOs)
			completedTasks.push_back(TaskOutputDto(task));
		}
	}

	return completedTasks;
}

std::vector<TaskOutputDto> TaskManager::GetPendingTasks() const {
	std::vector<TaskOutputDto> pendingTasks;

	for (const auto& task : m_Tasks) {
		if (!task.IsDone()) {
			pendingTasks.push_back(TaskOutputDto(task));
		}
	}

	return pendingTasks;
}

bool TaskManager::TaskExists(int id) const {
	return std::any_of(m_Tasks.begin(), m_Tasks.end(),
		[id](const Task& task) {
			return task.GetId() == id;
		});
}

void TaskManager::ClearAllTasks() {
	m_Tasks.clear();
}


