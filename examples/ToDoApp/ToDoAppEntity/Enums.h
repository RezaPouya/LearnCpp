#pragma once

enum struct TaskCategory : char {
	Personal = 0,
	Work = 1,
	Learning = 2,
};

enum struct OrderBy : char {
    Id,
    Create,
    Completed,
};

enum struct OrderByDirection : char {
    Descending,
    Ascending
};
