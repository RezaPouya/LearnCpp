#pragma once
#include "pch.h"
#include "EnumHelpers.h"
#include "Enums.h"
#include "Task.h"

class TaskOutputDto {
public:
    int Id;
    bool IsDone = false;
    std::string Category;
    std::string Title;
    std::string Content;
    std::chrono::system_clock::time_point CreatedAt;
    std::chrono::system_clock::time_point LastUpdatedAt;
    std::optional<std::chrono::system_clock::time_point> DoneAt;
    std::string Status;

    TaskOutputDto(int id,
        bool isDone,
        TaskCategory category,  // Changed to pass by value
        const std::string& title,
        const std::string& content,
        std::chrono::system_clock::time_point createdAt,
        std::chrono::system_clock::time_point lastUpdatedAt,
        std::optional<std::chrono::system_clock::time_point> doneAt)  // Fixed type
        : Id(id),
        IsDone(isDone),
        Category(EnumHelper::GetCategoryString(category)),
        Title(title),
        Content(content),
        CreatedAt(createdAt),
        LastUpdatedAt(lastUpdatedAt),
        DoneAt(doneAt),
        Status(getStatusString(isDone)) {  // Initialize Status last
    }

    TaskOutputDto(const Task& task)
        : Id(task.GetId()),
        IsDone(task.IsDone()),
        Category(EnumHelper::GetCategoryString(task.GetCategory())),
        Title(task.GetTitle()),
        Content(task.GetContent()),
        CreatedAt(task.GetCreatedAt()),
        LastUpdatedAt(task.GetLastUpdatedAt()),
        DoneAt(task.GetDoneAt()),
        Status(getStatusString(task.IsDone())) {  // Initialize Status with proper value
    }



private:
    static std::string getStatusString(bool isDone) {
        return isDone ? "Completed" : "Pending";
    }
};