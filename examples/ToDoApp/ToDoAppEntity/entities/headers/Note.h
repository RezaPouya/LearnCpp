#pragma once
#include <sstream>
#include <string>
#include <format>
#include <chrono>
#include <iostream>
#include "NoteCategory.h"
#include "../Dtos/NoteOutputDto.h"
#include "../../Utilities/TimeHelper.h"
#include "../../Utilities/TimeHelper.h"


using Clock = std::chrono::time_point<std::chrono::system_clock>;

class Note {
private:
    NoteCategory m_noteCategory = NoteCategory::Personal;
    int m_id;
    std::string m_title;
    std::string m_content;
    Clock m_createdAt;
    Clock m_lastUpdatedAt;

public:
    // Constructor declaration
    Note(int id, const std::string& title, const std::string& content);

    // Getters
    std::unique_ptr<NoteOutputDto> GetInfo() const;

    // Setters with automatic timestamp updates
    void setTitle(const std::string_view& newTitle) {
        m_title = newTitle;
        m_lastUpdatedAt = std::chrono::system_clock::now();
    }

    void setContent(const std::string_view& newContent) {
        m_content = newContent;
        m_lastUpdatedAt = std::chrono::system_clock::now();
    }

    void setCategory(NoteCategory newCategory) {
        m_noteCategory = newCategory;
        m_lastUpdatedAt = std::chrono::system_clock::now();
    }

    // Utility methods
    std::string getFormattedCreatedAt() const {
        return MyUtilities::TimeHelper::FormatTimePoint(m_createdAt);
    }

    std::string getFormattedLastUpdatedAt() const {
        return MyUtilities::TimeHelper::TimeHelper::FormatTimePoint(m_lastUpdatedAt);
    }
};