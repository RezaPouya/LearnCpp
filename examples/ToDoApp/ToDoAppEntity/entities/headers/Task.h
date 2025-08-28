#include "../../pch.h"
#include "../../Dtos/TaskOutputDto.h"
#include "../../Utilities/TimeHelper.h"
#include "Enums.h"

using Clock = std::chrono::time_point<std::chrono::system_clock>;

class Task {
private:
	TaskCategory m_noteCategory = TaskCategory::Personal;
	int m_id;
	std::string m_title;
	std::string m_content;
	Clock m_createdAt;
	Clock m_lastUpdatedAt;
	bool m_isDone = false;
	std::optional<Clock> m_doneAt;

public:
	// Constructor declaration
	Task(int id, const std::string& title, const std::string& content , const TaskCategory category);

	// Getters
	std::unique_ptr<TaskOutputDto> GetInfo() const;

	// Setters with automatic timestamp updates
	void SetTitle(const std::string_view& newTitle) {
		m_title = newTitle;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void SetContent(const std::string_view& newContent) {
		m_content = newContent;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void SetCategory(TaskCategory newCategory) {
		m_noteCategory = newCategory;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void MarkAsDone() {
		if (!m_isDone) {
			m_isDone = true;
			m_doneAt = std::chrono::system_clock::now();
			updateLastUpdated();
		}
	}

	void MarkAsUndone() {
		if (m_isDone) {
			m_isDone = false;
			m_doneAt = Clock{}; // Reset to default time point
			updateLastUpdated();
		}
	}

	void ToggleDone() {
		m_isDone ? MarkAsUndone() : MarkAsDone();
	}

	// Utility methods
	std::string getFormattedCreatedAt() const {
		return MyUtilities::TimeHelper::FormatTimePoint(m_createdAt);
	}

	std::string getFormattedLastUpdatedAt() const {
		return MyUtilities::TimeHelper::TimeHelper::FormatTimePoint(m_lastUpdatedAt);
	}

	std::string getFormattedDoneAt() const {
		return (m_doneAt.has_value()) ? MyUtilities::TimeHelper::FormatTimePoint(m_doneAt.value()) : "Not completed";
	}


	int GetId() const { return m_id; }
	TaskCategory GetCategory() const { return m_noteCategory; }
	std::string GetTitle() const { return m_title; }
	std::string GetContent() const { return m_content; }
	Clock GetCreatedAt() const { return m_createdAt; }
	Clock GetLastUpdatedAt() const { return m_lastUpdatedAt; }
	bool GetIsDone() const { return m_isDone; }
	std::optional< Clock> GetDoneAt() const { return m_doneAt; }

private:
	void updateLastUpdated() {
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}
};