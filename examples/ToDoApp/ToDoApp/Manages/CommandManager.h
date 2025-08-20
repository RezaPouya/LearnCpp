#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <map>
#include <memory>

enum class MenuCommand {
    Exit = -1,
    Home = 0,
    List = 1,
    Add = 2,
    Delete = 3,
    Edit = 4,
    MarkDone = 5,
    ShowCompleted = 6,
    ShowPending = 7,
    Invalid = 99
};

class CommandManager {
private:
    std::map<MenuCommand, std::string> m_commandDescriptions;
    std::map<MenuCommand, std::function<void()>> m_commandHandlers;
    bool m_isRunning;
    MenuCommand m_currentCommand;

    void initializeCommands();

public:
    CommandManager();

    // Command registration
    void registerCommandHandler(MenuCommand command, std::function<void()> handler);

    // UI methods
    void printWelcome() const;
    void showMainMenu() const;
    void handleInvalidCommand() const;

    // Command processing
    MenuCommand getCommandFromInput() const;
    void executeCommand(MenuCommand command);

    // Main loop
    void run();

    // Getters
    bool isRunning() const;
    MenuCommand getCurrentCommand() const;
    std::string getCommandName(MenuCommand command) const;
};

