#include "headers/Note.h"

#include <memory>

// Constructor implementation
Note::Note(const int id, const std::string& title, const std::string& content)
    : m_id(id),
    m_title(title),
    m_content(content),
    m_createdAt(std::chrono::system_clock::now()),
    m_lastUpdatedAt(std::chrono::system_clock::now()) {
}

// GetInfo implementation
std::unique_ptr<NoteOutputDto> Note::GetInfo() const {
    return std::make_unique<NoteOutputDto>(
        m_id,
        m_noteCategory,
        m_title,
        m_content,
        m_createdAt,
        m_lastUpdatedAt
    );
}