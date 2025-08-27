#include "headers/Task.h"
// Constructor implementation
Task::Task(const int id, const std::string& title, const std::string& content)
    : m_id(id),
    m_title(title),
    m_content(content),
    m_createdAt(std::chrono::system_clock::now()),
    m_lastUpdatedAt(std::chrono::system_clock::now()) {
}

// GetInfo implementation
std::unique_ptr<TaskOutputDto> Task::GetInfo() const {
    return std::make_unique<TaskOutputDto>(
        m_id,
        m_isDone,
        m_noteCategory,
        m_title,
        m_content,
        m_createdAt,
        m_lastUpdatedAt,
        m_doneAt
    );
}