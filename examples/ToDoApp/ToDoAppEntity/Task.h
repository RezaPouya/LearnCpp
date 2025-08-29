#pragma once

#include "pch.h"
#include "TimeHelper.h"
#include "Enums.h"

// Correct type aliases
using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Task {
private:
    TaskCategory m_noteCategory = TaskCategory::Personal;
    int m_id;
    std::string m_title;
    std::string m_content;
    TimePoint m_createdAt;
    TimePoint m_lastUpdatedAt;
    bool m_isDone = false;
    std::optional<TimePoint> m_doneAt;

    void MarkAsDone() {
        if (!m_isDone) {
            m_isDone = true;
            m_doneAt = Clock::now();
            UpdateLastUpdated();
        }
    }

    void MarkAsUndone() {
        if (m_isDone) {
            m_isDone = false;
            m_doneAt = std::nullopt;
            UpdateLastUpdated();
        }
    }

public:
    // Constructor implementation
    Task(int id, const std::string& title, const std::string& content, TaskCategory category)
        : m_id(id), m_title(title), m_content(content), m_noteCategory(category),
        m_createdAt(Clock::now()), m_lastUpdatedAt(Clock::now()) {
    }

    // Setters with automatic timestamp updates
    void SetTitle(std::string_view newTitle) {
        m_title = newTitle;
        UpdateLastUpdated();
    }

    void SetContent(std::string_view newContent) {
        m_content = newContent;
        UpdateLastUpdated();
    }

    void SetCategory(TaskCategory newCategory) {
        m_noteCategory = newCategory;
        UpdateLastUpdated();
    }



    void ToggleDone() {
        m_isDone ? MarkAsUndone() : MarkAsDone();
    }

    // Utility methods
    std::string GetFormattedCreatedAt() const {
        return MyUtilities::TimeHelper::FormatTimePoint(m_createdAt);
    }

    std::string GetFormattedLastUpdatedAt() const {
        return MyUtilities::TimeHelper::FormatTimePoint(m_lastUpdatedAt);
    }

    std::string GetFormattedDoneAt() const {
        return m_doneAt.has_value()
            ? MyUtilities::TimeHelper::FormatTimePoint(m_doneAt.value())
            : "Not completed";
    }

    // Basic getters
    int GetId() const { return m_id; }
    TaskCategory GetCategory() const { return m_noteCategory; }
    const std::string& GetTitle() const { return m_title; }
    const std::string& GetContent() const { return m_content; }
    TimePoint GetCreatedAt() const { return m_createdAt; }
    TimePoint GetLastUpdatedAt() const { return m_lastUpdatedAt; }
    bool IsDone() const { return m_isDone; }
    std::optional<TimePoint> GetDoneAt() const { return m_doneAt; }

private:
    void UpdateLastUpdated() {
        m_lastUpdatedAt = Clock::now();
    }
};