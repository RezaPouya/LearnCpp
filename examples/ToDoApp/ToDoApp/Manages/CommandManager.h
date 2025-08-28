#pragma once
#include "../pch.h"
#include "TaskManager.h"

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
    const TaskManager& m_TaskManager;
public:
    
    CommandManager();

    void registerCommandHandler(MenuCommand command, std::function<void()> handler);
    void printWelcome() const;
    MenuCommand getCommandFromInput() const;
    void executeCommand(MenuCommand command);
    void handleInvalidCommand() const;
    void run();
    bool isRunning() const;
    MenuCommand getCurrentCommand() const;
    std::string getCommandName(MenuCommand command) const;

    void ShowMainMenu() const;
    void ShowList() const;

private:
    void initializeCommands();

    bool m_isRunning;
    MenuCommand m_currentCommand;
    std::unordered_map<MenuCommand, std::string> m_commandDescriptions;
    std::unordered_map<MenuCommand, std::function<void()>> m_commandHandlers;
};