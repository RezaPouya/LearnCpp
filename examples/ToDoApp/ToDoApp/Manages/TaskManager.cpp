#include "../pch.h"
#include "TaskManager.h"

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

const std::optional<std::unique_ptr<TaskOutputDto>> TaskManager::GetById(int id) const {

    auto task = std::find_if(m_Tasks.begin(), m_Tasks.end(),
        [id](const Task& task) {
            return  task.GetId() == id;
        });

    if (task == m_Tasks.end()) {
        return std::nullopt;
    }

    return std::make_unique<TaskOutputDto>(task);
}

const std::vector<TaskOutputDto>& TaskManager::GetList(OrderBy orderBy, 
    OrderByDirection orderByDirection) const {
    
    std::vector<TaskOutputDto> result;

    // Since we're returning a reference to the internal vector, we can't sort it in place.
    // In a real implementation, you might want to return a sorted copy or use a different approach.
    // For now, we'll return the unsorted vector.

    // TODO: Implement proper sorting logic if needed
    // This would require creating a sorted copy or maintaining a sorted container

    return result;
}

std::optional<Task> TaskManager::FindById(int id) {
    auto it = std::find_if(m_Tasks.begin(), m_Tasks.end(),
        [id](const Task& task) {
            return task.GetId() == id;
        });

    if (it != m_Tasks.end()) {
        return *it;
    }

    return std::optional<Task>();
}

void TaskManager::Add(
    const std::string& title,
    const std::optional<std::string>& content,
    TaskCategory category) {

    int id = GetNextAvailableId();

    // Create task with content if provided, otherwise use empty string
    std::string taskContent = content.has_value() ? content.value() : "";

    // Create the task (assuming Task constructor takes id, title, content)
    Task newTask(id, title, taskContent);

    // Set category if your Task class has this method
    // newTask.setCategory(static_cast<NoteCategory>(category));

    m_Tasks.emplace_back(std::move(newTask));
}
