#pragma once
#include <cstdint> // For fixed-width types (uint32_t, etc.)
#include <string>
#include <vector>
#include <variant> // C++17 for storing different media types

// Use strongly typed enums for safety
enum class MediaType : uint32_t {
	None = 0,
	Text = 1,
	Image = 2,
	Audio = 3,
	Video = 4
};


struct PouyaGlobalHeader {
    uint32_t magic;
    uint16_t version;
    uint16_t flags; // For future use (e.g., encrypted flag)
    uint32_t records_count;
    uint64_t index_table_offset;
    std::string creation_date;
    uint64_t app_version; 
};