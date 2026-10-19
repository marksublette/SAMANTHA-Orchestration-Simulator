#include <iostream>
#include "Task.h"
#include "Agent.h"
#include "Orchestrator.h"
#include <vector>
#include <string>
void DisplayMenu()
{
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "   SAMANTHA ORCHESTRATION SIMULATOR\n";
    std::cout << "========================================\n";
    std::cout << "1. Create Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. View Agents\n";
    std::cout << "4. Assign Tasks Automatically\n";
    std::cout << "5. Complete Task\n";
    std::cout << "0. Exit\n";
}
void DisplayTasks(const std::vector<Task>& tasks, const std::vector<Agent>& agents)
{
    if (tasks.empty())
    {
        std::cout << "\nNo tasks have been created yet.\n";
    }
    else
    {
        std::cout << "\nTasks:\n";
        for (size_t i = 0; i < tasks.size(); i++)
        {
            std::cout << "\nTask " << i + 1 << '\n';
            std::cout << "Name: " << tasks[i].GetName() << '\n';
            std::cout << "Complexity: " << tasks[i].GetComplexity() << '\n';
            std::cout << "Status: " << tasks[i].GetStatus() << '\n';
            int agentIndex = tasks[i].GetAssignedAgentIndex();
            if (tasks[i].GetStatus() == "Assigned" &&
                agentIndex >= 0 &&
                static_cast<size_t>(agentIndex) < agents.size())
            {
                std::cout << "Assigned Agent: "
                    << agents[agentIndex].GetName() << '\n';
            }
        }
    }
}
void DisplayAgents(const std::vector<Agent>& agents)
{
    if (agents.empty())
    {
        std::cout << "\nNo agents are available.\n";
    }
    else
    {
        std::cout << "\nAgents:\n";
        for (size_t i = 0; i < agents.size(); i++)
        {
            std::cout << "\nAgent " << i + 1 << '\n';
            std::cout << "Name: " << agents[i].GetName() << '\n';
            std::cout << "Specialty: " << agents[i].GetSpecialty() << '\n';
            std::cout << "Capability Level: " << agents[i].GetCapabilityLevel() << "/10\n";
            std::cout << "Status: "
                << (agents[i].GetAvailable() ? "Available" : "Busy")
                << '\n';
        }
    }
}
int SelectTask(const std::vector<Task>& tasks)
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << ". "
            << tasks[i].GetName()
            << " - "
            << tasks[i].GetStatus()
            << '\n';
    }
    std::cout << "Enter task number: ";
    std::string input;
    std::getline(std::cin, input);
    try
    {
        size_t position = 0;
        int taskChoice = std::stoi(input, &position);
        if (position != input.length() ||
            taskChoice < 1 ||
            static_cast<size_t>(taskChoice) > tasks.size())
        {
            throw std::invalid_argument("Invalid task selection");
        }
        return taskChoice - 1;
    }
    catch (const std::exception&)
    {
        std::cout << "Invalid task selection. Please enter a valid task number.\n";
        return -1;
    }
}
int main()
{
    int choice = -1;//note to self in my best fat russian guy in parents basement voice, "zero bad....-1 gooooood."
    std::vector<Task> tasks;//keep it outta the loop brah, it's need to know.
    std::vector<Agent> agents;
    Orchestrator orchestrator;
    Agent basicAnimationAgent;
    basicAnimationAgent.SetName("Basic Animation Agent");
    basicAnimationAgent.SetSpecialty("Animation");
    basicAnimationAgent.SetCapabilityLevel(3);
    basicAnimationAgent.SetAvailable(true);
    agents.push_back(basicAnimationAgent);
    Agent advancedAnimationAgent;
    advancedAnimationAgent.SetName("Advanced Animation Agent");
    advancedAnimationAgent.SetSpecialty("Animation");
    advancedAnimationAgent.SetCapabilityLevel(7);
    advancedAnimationAgent.SetAvailable(true);
    agents.push_back(advancedAnimationAgent);
    Agent expertAnimationAgent;
    expertAnimationAgent.SetName("Expert Animation Agent");
    expertAnimationAgent.SetSpecialty("Animation");
    expertAnimationAgent.SetCapabilityLevel(10);
    expertAnimationAgent.SetAvailable(true);
    agents.push_back(expertAnimationAgent);
    Agent basicImageAgent;
    basicImageAgent.SetName("Basic Image Agent");
    basicImageAgent.SetSpecialty("Image Generation");
    basicImageAgent.SetCapabilityLevel(4);
    basicImageAgent.SetAvailable(true);
    agents.push_back(basicImageAgent);
    Agent expertImageAgent;
    expertImageAgent.SetName("Expert Image Agent");
    expertImageAgent.SetSpecialty("Image Generation");
    expertImageAgent.SetCapabilityLevel(10);
    expertImageAgent.SetAvailable(true);
    agents.push_back(expertImageAgent);
    while (choice != 0)
    {
        DisplayMenu();
        std::cout << "\nEnter selection: ";
        std::string input;
        std::getline(std::cin, input);
        try
        {
            size_t position = 0;
            choice = std::stoi(input, &position);
            if (position != input.length() || choice < 0 || choice > 5)
            {
                throw std::invalid_argument("Invalid menu selection");
            }
        }
        catch (const std::exception&)
        {
            std::cout << "Invalid input. Please enter a number from 0 to 5.\n";
            choice = -1;
            continue;
        }
        switch (choice)
        {
        case 1:
        {// extra scope because of variables
            std::string taskName;
            int taskComplexity;
            Task newTask;
            std::cout << "\nSelect Task type:\n";
            std::cout << "1. Animation\n";
            std::cout << "2. Image Generation\n";
            std::cout << "Enter selection: ";
            std::string taskType;
            std::getline(std::cin, taskType);
            while (taskType != "1" && taskType != "2")
            {
                std::cout << "Invalid selection. Please enter 1 or 2: ";
                std::getline(std::cin, taskType);
            }
            if (taskType == "1")
            {
                taskName = "Animation";
            }
            else
            {
                taskName = "Image Generation";
            }
            while (true)
            {
                std::cout << "Enter task complexity (1-10): ";
                std::string input;
                std::getline(std::cin, input);
                try
                {
                    size_t position = 0;
                    taskComplexity = std::stoi(input, &position);
                    if (position != input.length() ||
                        taskComplexity < 1 || taskComplexity > 10)
                    {
                        throw std::invalid_argument("Invalid complexity");
                    }
                    break;
                }
                catch (const std::exception&)
                {
                    std::cout << "Invalid complexity. Please enter a number from 1 to 10.\n";
                }
            }
            std::string requiredSpecialty = taskName;
            newTask.SetName(taskName);
            newTask.SetComplexity(taskComplexity);
            newTask.SetRequiredSpecialty(requiredSpecialty);
            newTask.SetStatus("Waiting");
            tasks.push_back(newTask);
            std::cout << "Task created.\n";
            break;
        }
        case 2:
        {
            DisplayTasks(tasks, agents);
            break;
        }
        case 3:
        {
            DisplayAgents(agents);
            break;
        }
        case 4:
        {
            if (tasks.empty())
            {
                std::cout << "No tasks have been created yet.\n";
                break;
            }
            std::vector<bool> wasWaiting;
            for (size_t i = 0; i < tasks.size(); i++)
            {
                wasWaiting.push_back(tasks[i].GetStatus() == "Waiting");
            }
            int assignedCount = orchestrator.AssignAllWaitingTasks(
                tasks, agents);
            std::cout << "\nAutomatic Assignment Results\n";
            std::cout << "----------------------------\n";
            std::cout << assignedCount
                << (assignedCount == 1 ? " Task assigned.\n" : " Tasks assigned.\n");
            for (size_t i = 0; i < tasks.size(); i++)
            {
                if (wasWaiting[i] && tasks[i].GetStatus() == "Assigned")
                {
                    int agentIndex = tasks[i].GetAssignedAgentIndex();
                    if (agentIndex >= 0 &&
                        static_cast<size_t>(agentIndex) < agents.size())
                    {
                        std::cout << "Task " << i + 1
                            << " (" << tasks[i].GetName()
                            << ", Complexity " << tasks[i].GetComplexity()
                            << ") -> " << agents[agentIndex].GetName()
                            << '\n';
                    }
                }
            }
            int waitingCount = 0;
            for (size_t i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].GetStatus() == "Waiting")
                {
                    waitingCount++;
                }
            }
            std::cout << waitingCount
                << (waitingCount == 1 ? " Task remaining.\n" : " Tasks remaining.\n");
            break;
        }
        case 5:
        {
            if (tasks.empty())
            {
                std::cout << "No tasks have been created yet.\n";
                break;
            }
            std::cout << "\nSelect a task to complete:\n";
            int taskIndex = SelectTask(tasks);
            if (taskIndex == -1)
            {
                break;
            }
            bool completed = orchestrator.CompleteTask(
                tasks[taskIndex],
                agents);
            if (completed)
            {
                std::cout << "Task completed successfully. Agent is available again.\n";
            }
            else
            {
                std::cout << "Task could not be completed. It must be assigned first.\n";
            }
            break;
        }
        case 0:
            std::cout << "Exiting simulator.\n";
            break;
        default://whoopsie
            std::cout << "Invalid selection. Try again.\n";
            break;
        }
    }
    return 0;
}