#include <iostream>
#include "Task.h"
#include "Agent.h"
#include "Orchestrator.h"
#include <vector>
#include <string>
int main()
{
    int choice = -1;//note to self in my best fat russian guy in parents basement voice, "zero bad....-1 gooooood."
    std::vector<Task> tasks;//keep it outta the loop brah, it's need to know.
    std::vector<Agent> agents;
    Orchestrator orchestrator;
    Agent animationAgent;
    animationAgent.SetName("Animation Agent");
    animationAgent.SetSpecialty("Animation");
    animationAgent.SetAvailable(true);
    agents.push_back(animationAgent);
    Agent imageAgent;
    imageAgent.SetName("Image Agent");
    imageAgent.SetSpecialty("Image Generation");
    imageAgent.SetAvailable(true);
    agents.push_back(imageAgent);
    while (choice != 0)
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "   SAMANTHA ORCHESTRATION SIMULATOR\n";
        std::cout << "========================================\n";
        std::cout << "1. Create Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. View Agents\n";
        std::cout << "4. Assign Task\n";
        std::cout << "5. Complete Task\n";
        std::cout << "0. Exit\n";
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
            std::cout << "Enter task name: ";
            std::getline(std::cin, taskName);
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
            newTask.SetName(taskName);
            newTask.SetComplexity(taskComplexity);
            newTask.SetStatus("Waiting");
            tasks.push_back(newTask);
            std::cout << "Task created.\n";
            break;
        }
        case 2:
        {
            if (tasks.empty())
            {
                std::cout << "\nNo tasks have been created yet.\n";
            }
            else
            {
                std::cout << "\nTasks:\n";
                for (int i = 0; i < tasks.size(); i++)
                {
                    std::cout << "\nTask " << i + 1 << '\n';
                    std::cout << "Name: " << tasks[i].GetName() << '\n';
                    std::cout << "Complexity: " << tasks[i].GetComplexity() << '\n';
                    std::cout << "Status: " << tasks[i].GetStatus() << '\n';
                }
            }
            break;
        }
        case 3:
        {
            if (agents.empty())
            {
                std::cout << "\nNo agents are available.\n";
            }
            else
            {
                std::cout << "\nAgents:\n";
                for (int i = 0; i < agents.size(); i++)
                {
                    std::cout << "\nAgent " << i + 1 << '\n';
                    std::cout << "Name: " << agents[i].GetName() << '\n';
                    std::cout << "Specialty: " << agents[i].GetSpecialty() << '\n';
                    std::cout << "Available: " << agents[i].GetAvailable() << '\n';
                }
            }
            break;
        }
        case 4:
        {
            if (tasks.empty())
            {
                std::cout << "No tasks are available to assign.\n";
                break;
            }
            if (agents.empty())
            {
                std::cout << "No agents are available.\n";
                break;
            }
            std::cout << "\nSelect a task to assign:\n";
            for (int i = 0; i < tasks.size(); i++)
            {
                std::cout << i + 1 << ". "
                    << tasks[i].GetName()
                    << " - "
                    << tasks[i].GetStatus()
                    << '\n';
            }
            int taskChoice;
            std::cout << "Enter task number: ";
            std::string input;
            std::getline(std::cin, input);
            try
            {
                size_t position = 0;
                taskChoice = std::stoi(input, &position);
                if (position != input.length() ||
                    taskChoice < 1 ||
                    static_cast<size_t>(taskChoice) > tasks.size())
                {
                    throw std::invalid_argument("Invalid task selection");
                }
            }
            catch (const std::exception&)
            {
                std::cout << "Invalid task selection. Please enter a valid task number.\n";
                break;
            }
            bool assigned = orchestrator.AssignTaskAutomatically(
                tasks[taskChoice - 1],
                agents);
            if (assigned)
            {
                std::cout << "Task assigned successfully.\n";
            }
            else
            {
                std::cout << "Task could not be assigned. No agents are available.\n";
            }
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
            for (int i = 0; i < tasks.size(); i++)
            {
                std::cout << i + 1 << ". "
                    << tasks[i].GetName()
                    << " - "
                    << tasks[i].GetStatus()
                    << '\n';
            }
            int taskChoice;
            std::cout << "Enter task number: ";
            std::string input;
            std::getline(std::cin, input);
            try
            {
                size_t position = 0;
                taskChoice = std::stoi(input, &position);
                if (position != input.length() ||
                    taskChoice < 1 ||
                    static_cast<size_t>(taskChoice) > tasks.size())
                {
                    throw std::invalid_argument("Invalid task selection");
                }
            }
            catch (const std::exception&)
            {
                std::cout << "Invalid task selection. Please enter a valid task number.\n";
                break;
            }
            bool completed = orchestrator.CompleteTask(
                tasks[taskChoice - 1],
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