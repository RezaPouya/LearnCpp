#pragma once
#include <sstream>
#include <string>
#include <format>
#include <chrono>
#include <iostream>
#include "TaskCategory.h"
#include "../Dtos/TaskOutputDto.h"
#include "../../Utilities/TimeHelper.h"
#include "../../Utilities/TimeHelper.h"


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
	Clock m_doneAt;

public:
	// Constructor declaration
	Task(int id, const std::string& title, const std::string& content);

	// Getters
	std::unique_ptr<TaskOutputDto> GetInfo() const;

	// Setters with automatic timestamp updates
	void setTitle(const std::string_view& newTitle) {
		m_title = newTitle;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void setContent(const std::string_view& newContent) {
		m_content = newContent;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void setCategory(TaskCategory newCategory) {
		m_noteCategory = newCategory;
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}

	void markAsDone() {
		if (!m_isDone) {
			m_isDone = true;
			m_doneAt = std::chrono::system_clock::now();
			updateLastUpdated();
		}
	}

	void markAsUndone() {
		if (m_isDone) {
			m_isDone = false;
			m_doneAt = Clock{}; // Reset to default time point
			updateLastUpdated();
		}
	}

	void toggleDone() {
		m_isDone ? markAsUndone() : markAsDone();
	}

	// Utility methods
	std::string getFormattedCreatedAt() const {
		return MyUtilities::TimeHelper::FormatTimePoint(m_createdAt);
	}

	std::string getFormattedLastUpdatedAt() const {
		return MyUtilities::TimeHelper::TimeHelper::FormatTimePoint(m_lastUpdatedAt);
	}

	std::string getFormattedDoneAt() const {
		return (m_isDone) ? MyUtilities::TimeHelper::FormatTimePoint(m_doneAt) : "Not completed";
	}

private:
	void updateLastUpdated() {
		m_lastUpdatedAt = std::chrono::system_clock::now();
	}
};