#include "CommandManager.h"
#include <iostream>
#include <limits>
#include "TaskManager.h"
#include "../../ToDoAppEntity/TimeHelper.h"

CommandManager::CommandManager() :m_TaskManager(TaskManager::GetInstance()),
m_isRunning(true), m_currentCommand(MenuCommand::Home) {

    initializeCommands();
}

void CommandManager::initializeCommands() {
    // Command descriptions
    m_commandDescriptions = {
        {MenuCommand::Exit, "Exit the application"},
        {MenuCommand::Home, "Return to home menu"},
        {MenuCommand::List, "List all tasks"},
        {MenuCommand::Add, "Add a new task"},
        {MenuCommand::Delete, "Delete a task"},
        {MenuCommand::Edit, "Edit a task"},
        {MenuCommand::ToggleStatus, "Mark task as done"},
    };

    // Default command handlers (can be overridden)
    m_commandHandlers = {
        {MenuCommand::Exit, [this]() { m_isRunning = false; }},
        {MenuCommand::Home, [this]() { ShowMainMenu(); }},
        {MenuCommand::List, [this]() { ShowList(); }},
        {MenuCommand::Add, [this]() {  CreateTask(); }},
        {MenuCommand::Delete, [this]() { DeleteTask(); }},
        {MenuCommand::Edit, [this]() { EditTask(); }},
        {MenuCommand::ToggleStatus, [this]() { ToggleStatus(); }},
    };
}

void CommandManager::registerCommandHandler(MenuCommand command, std::function<void()> handler) {
    m_commandHandlers[command] = handler;
}

void CommandManager::printWelcome() const {
    std::cout << "===========================================================\n";
    std::cout << "========= Welcome to this wonderful Todo App ==============\n";
    std::cout << "===========================================================\n\n";
}


MenuCommand CommandManager::getCommandFromInput() const {
    int input;
    std::cout << "\nEnter command number: ";

    if (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return MenuCommand::Invalid;
    }

    // Convert integer input to MenuCommand enum
    switch (input) {
    case -1: return MenuCommand::Exit;
    case 0: return MenuCommand::Home;
    case 1: return MenuCommand::List;
    case 2: return MenuCommand::Add;
    case 3: return MenuCommand::Delete;
    case 4: return MenuCommand::Edit;
    case 5: return MenuCommand::ToggleStatus;
    default: return MenuCommand::Invalid;
    }
}

void CommandManager::executeCommand(MenuCommand command) {
    if (m_commandHandlers.find(command) != m_commandHandlers.end()) {
        m_currentCommand = command;
        m_commandHandlers[command]();
    }
    else {
        std::cout << "Unknown command!\n";
    }
}

void CommandManager::handleInvalidCommand() const {
    std::cout << "Invalid command! Please try again.\n";
    std::cout << "Type " << static_cast<int>(MenuCommand::Home)
        << " to see available commands.\n";
}

void CommandManager::run() {
    printWelcome();

    ShowMainMenu();

    while (m_isRunning) {
        MenuCommand command = getCommandFromInput();

        if (command == MenuCommand::Invalid) {
            handleInvalidCommand();
            continue;
        }

        executeCommand(command);

        // If command wasn't Exit and we're still running, show menu again
        if (m_isRunning && command != MenuCommand::Home) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
            ShowMainMenu();
        }
    }

    std::cout << "Thank you for using the Todo App! Goodbye!\n";
}

bool CommandManager::isRunning() const {
    return m_isRunning;
}

MenuCommand CommandManager::getCurrentCommand() const {
    return m_currentCommand;
}

std::string CommandManager::getCommandName(MenuCommand command) const {
    switch (command) {
    case MenuCommand::Exit: return "Exit";
    case MenuCommand::Home: return "Home";
    case MenuCommand::List: return "List";
    case MenuCommand::Add: return "Add";
    case MenuCommand::Delete: return "Delete";
    case MenuCommand::Edit: return "Edit";
    case MenuCommand::ToggleStatus: return "Toggle Status";
    case MenuCommand::Invalid: return "Invalid";
    default: return "Unknown";
    }
}

//----------------------------------------------------------------------------------

void CommandManager::ShowMainMenu() const {
    std::cout << "\n=== MAIN MENU ===\n";
    std::cout << "Available commands:\n";

    // Manually specify the display order
    std::array<MenuCommand , 5> displayOrder = {
        MenuCommand::List,
        MenuCommand::Add,
        MenuCommand::Delete,
        MenuCommand::Edit,
        MenuCommand::ToggleStatus,
    };

    // Display in specified order
    for (MenuCommand cmd : displayOrder) {
        if (m_commandDescriptions.find(cmd) != m_commandDescriptions.end()) {
            std::cout << static_cast<int>(cmd) << ". " << m_commandDescriptions.at(cmd) << "\n";
        }
    }

    std::cout << static_cast<int>(MenuCommand::Exit) << ". "
        << m_commandDescriptions.at(MenuCommand::Exit) << "\n";
    std::cout << "\n===========================================================\n";
}

void CommandManager::ShowList() const {
    size_t taskCount = m_TaskManager.GetTaskCount();

    if (taskCount == 0) {
        std::cout << "You don't have any tasks defined!" << std::endl;
    }
    else {
        std::cout << "Your Tasks (" << taskCount << "):" << std::endl;
        std::cout << "...................................................." << std::endl;

        for (const auto& task : m_TaskManager.GetList()) {
            std::cout << task.Id << " - "
                << MyUtilities::TimeHelper::FormatTimePoint(task.CreatedAt) << " - "
                << task.Title << " - state: " << task.Status << std::endl;
        }
    }

    ShowMainMenu();
}
 

void CommandManager::CreateTask() {
    std::cout << "\n=== ADD NEW TASK ===\n";

    // Get task title
    std::string title;
    std::cout << "Enter task title: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);

    if (title.empty()) {
        std::cout << "Title cannot be empty! Operation cancelled.\n";
        return;
    }

    // Get task content
    std::string content;
    std::cout << "Enter task content (optional, press Enter to skip): ";
    std::getline(std::cin, content);

    // Get task category
    std::cout << "\nSelect category:\n";
    std::cout << "1. Personal\n";
    std::cout << "2. Work\n";
    std::cout << "3. Learning\n";
    std::cout << "Enter choice (1-3, default: Personal): ";

    TaskCategory category = TaskCategory::Personal;
    std::string categoryInput;
    std::getline(std::cin, categoryInput);

    if (!categoryInput.empty()) {
        switch (categoryInput[0]) {
        case '1': category = TaskCategory::Personal; break;
        case '2': category = TaskCategory::Work; break;
        case '3': category = TaskCategory::Learning; break;
        default:
            std::cout << "Invalid choice. Using default category: Personal\n";
            break;
        }
    }

    // Confirm and add task
    std::cout << "\nTask details:\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Content: " << (content.empty() ? "[No content]" : content) << "\n";
    std::cout << "Category: " << EnumHelper::GetCategoryString(category) << "\n";

    std::cout << "\nAdd this task? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        
        auto newTask = m_TaskManager.Add(title, content, category);

        if (newTask.has_value()) {
            std::cout << "Task added successfully! Task ID: " << newTask.value()->GetId() << "\n";
        }
        else {
            std::cout << "Failed to add task!\n";
        }
    }
    else {
        std::cout << "Task addition cancelled.\n";
    }
}

void CommandManager::DeleteTask() {
    std::cout << "\n=== DELETE TASK ===\n";

    if (m_TaskManager.GetTaskCount() == 0) {
        std::cout << "No tasks available to delete!\n";
        return;
    }

    ShowList();

    int taskId;
    std::cout << "\nEnter Task ID to delete: ";
    std::cin >> taskId;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Operation cancelled.\n";
        return;
    }

    std::cout << "Are you sure you want to delete task " << taskId << "? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        if (m_TaskManager.RemoveById(taskId)) {
            std::cout << "Task " << taskId << " deleted successfully!\n";
        }
        else {
            std::cout << "Task " << taskId << " not found!\n";
        }
    }
    else {
        std::cout << "Deletion cancelled.\n";
    }
}


void CommandManager::EditTask() {
    std::cout << "\n=== EDIT TASK ===\n";

    if (m_TaskManager.GetTaskCount() == 0) {
        std::cout << "No tasks available to edit!\n";
        return;
    }

    ShowList();

    int taskId;
    std::cout << "\nEnter Task ID to edit: ";
    std::cin >> taskId;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Operation cancelled.\n";
        return;
    }

    // Check if task exists
    auto task = m_TaskManager.FindTaskById(taskId);
    if (!task.has_value()) {
        std::cout << "Task " << taskId << " not found!\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get new title
    std::string newTitle;
    std::cout << "Enter new title (press Enter to keep current): ";
    std::getline(std::cin, newTitle);

    // Get new content
    std::string newContent;
    std::cout << "Enter new content (press Enter to keep current): ";
    std::getline(std::cin, newContent);

    // Get new category
    std::cout << "\nSelect new category:\n";
    std::cout << "1. Personal (default)\n";
    std::cout << "2. Work\n";
    std::cout << "3. Learning\n";
    std::cout << "Enter choice (press Enter to keep current): ";

    std::optional<TaskCategory> newCategory = std::nullopt;
    std::string categoryInput;
    std::getline(std::cin, categoryInput);

    if (!categoryInput.empty()) {
        switch (categoryInput[0]) {
        case '1': newCategory = TaskCategory::Personal; break;
        case '2': newCategory = TaskCategory::Work; break;
        case '3': newCategory = TaskCategory::Learning; break;
        default:
            std::cout << "Invalid choice. Keeping current category.\n";
            break;
        }
    }
    else {
        newCategory =  task.value().GetCategory();
    }

    // Convert to optional for editing
    std::optional<std::string> contentOpt;
    if (!newContent.empty()) {
        contentOpt = newContent;
    }
    else {
        contentOpt = task.value().GetContent();
    }

    // Perform edit
    auto editedTask = m_TaskManager.Edit(taskId, newTitle, contentOpt,
        newCategory.value_or(TaskCategory::Personal));

    if (editedTask.has_value()) {
        std::cout << "Task " << taskId << " updated successfully!\n";
    }
    else {
        std::cout << "Failed to update task " << taskId << "!\n";
    }
}


void CommandManager::ToggleStatus() {
    std::cout << "\n=== MARK TASK AS DONE ===\n";

    if (m_TaskManager.GetTaskCount() == 0) {
        std::cout << "No tasks available!\n";
        return;
    }

    // Show pending tasks only
    auto pendingTasks = m_TaskManager.GetPendingTasks();

    if (pendingTasks.empty()) {
        std::cout << "No pending tasks!\n";
        return;
    }

    std::cout << "Pending Tasks:\n";
    std::cout << "....................................................\n";
    for (const auto& task : pendingTasks) {
        std::cout << task.Id << " - " << task.Title << "\n";
    }

    int taskId;
    std::cout << "\nEnter Task ID to mark as done: ";
    std::cin >> taskId;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Operation cancelled.\n";
        return;
    }

    auto task = m_TaskManager.GetById(taskId);
    if (task) {

        m_TaskManager.ToggleById(taskId);
        task = m_TaskManager.GetById(taskId);
        std::cout << "Task " << taskId << " status changed to " << task.value().Status << "\n";
    }
    else {
        std::cout << "Task " << taskId << " not found!\n";
    }
   
}