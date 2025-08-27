#include "../pch.h"
#include "../../ToDoAppEntity/entities/headers/Task.h"
#include "../../ToDoAppEntity/entities/headers/Enums.h"

class TaskManager {
private:
    std::vector<Task> m_Tasks;

    TaskManager() = default; // Private constructor for singleton pattern

    // Delete copy constructor and assignment operator
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    std::optional<Task> FindById(int id);

    const Task* FindById(int id) const;

public:
    // Singleton access method
    static TaskManager& GetInstance();

    // Task management methods
    const std::vector<TaskOutputDto>& GetList(OrderBy orderBy = OrderBy::Create,
        OrderByDirection orderByDirection = OrderByDirection::Descending) const;

    const std::optional<std::unique_ptr<TaskOutputDto>> GetById(int id) const;

    void Add(const std::string& title,
        const std::optional<std::string>& content = std::nullopt,
        TaskCategory category = TaskCategory::Personal);

    void Edit(int id,
        const std::string& title,
        const std::optional<std::string>& content = std::nullopt,
        TaskCategory category = TaskCategory::Personal);

    void RemoveById(int id);
    void ToggleById(int id);

    // Utility methods
    size_t GetTaskCount() const;
    size_t GetCompletedCount() const;
    size_t GetPendingCount() const;
    int GetLastId() const;
    int GetNextAvailableId() const;

    // Additional useful methods
    std::vector<const Task*> GetCompletedTasks() const;
    std::vector<const Task*> GetPendingTasks() const;
    bool TaskExists(int id) const;

    // For testing/debugging
    void ClearAllTasks();
};