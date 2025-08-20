#include "CommandManager.h"

CommandManager::CommandManager() : m_isRunning(true), m_currentCommand(MenuCommand::Home) {
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
        {MenuCommand::MarkDone, "Mark task as done"},
        {MenuCommand::ShowCompleted, "Show completed tasks"},
        {MenuCommand::ShowPending, "Show pending tasks"}
    };

    // Default command handlers (can be overridden)
    m_commandHandlers = {
        {MenuCommand::Exit, [this]() { m_isRunning = false; }},
        {MenuCommand::Home, [this]() { showMainMenu(); }},
        {MenuCommand::List, []() { std::cout << "Listing all tasks...\n"; }},
        {MenuCommand::Add, []() { std::cout << "Adding new task...\n"; }},
        {MenuCommand::Delete, []() { std::cout << "Deleting task...\n"; }},
        {MenuCommand::Edit, []() { std::cout << "Editing task...\n"; }},
        {MenuCommand::MarkDone, []() { std::cout << "Marking task as done...\n"; }},
        {MenuCommand::ShowCompleted, []() { std::cout << "Showing completed tasks...\n"; }},
        {MenuCommand::ShowPending, []() { std::cout << "Showing pending tasks...\n"; }}
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

void CommandManager::showMainMenu() const {
    std::cout << "\n=== MAIN MENU ===\n";
    std::cout << "Available commands:\n";

    for (const auto& [command, description] : m_commandDescriptions) {
        if (command != MenuCommand::Exit && command != MenuCommand::Home) {
            std::cout << static_cast<int>(command) << ". " << description << "\n";
        }
    }
    std::cout << static_cast<int>(MenuCommand::Exit) << ". "
        << m_commandDescriptions.at(MenuCommand::Exit) << "\n";
    std::cout << "===========================================================\n";
}

MenuCommand CommandManager::getCommandFromInput() const {
    int input;
    std::cout << "\nEnter command number: ";

    if (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
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
    case 5: return MenuCommand::MarkDone;
    case 6: return MenuCommand::ShowCompleted;
    case 7: return MenuCommand::ShowPending;
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
    showMainMenu();

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
            showMainMenu();
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
    case MenuCommand::MarkDone: return "MarkDone";
    case MenuCommand::ShowCompleted: return "ShowCompleted";
    case MenuCommand::ShowPending: return "ShowPending";
    case MenuCommand::Invalid: return "Invalid";
    default: return "Unknown";
    }
}