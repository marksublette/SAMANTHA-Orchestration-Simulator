#include <iostream>
#include "Task.h"
#include "Agent.h"
#include "Orchestrator.h"
int main()
{
    int choice = -1;//note to self in my best fat russian guy in parents basement voice, "zero bad....-1 gooooood."
    Task task;//keep it outta the loop brah, it's need to know.
    Agent agent;
    Orchestrator orchestrator;
    agent.SetName("Animation Agent");
    agent.SetSpecialty("Animation");
    agent.SetAvailable(true);
    while (choice != 0)
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "   SAMANTHA ORCHESTRATION SIMULATOR\n";
        std::cout << "========================================\n";
        std::cout << "1. Create Task\n";
        std::cout << "2. View Task\n";
        std::cout << "3. View Agent\n";
        std::cout << "4. Assign Task\n";
        std::cout << "0. Exit\n";
        std::cout << "\nEnter selection: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {// extra scope because of variables
            std::string taskName;
            int taskComplexity;
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, taskName);
            std::cout << "Enter task complexity (1-10): ";
            std::cin >> taskComplexity;
            task.SetName(taskName);
            task.SetComplexity(taskComplexity);
            task.SetStatus("Waiting");
            std::cout << "Task created.\n";
            break;
        }
        case 2://simple statements
            std::cout << "\nTask Name: " << task.GetName() << '\n';
            std::cout << "Complexity: " << task.GetComplexity() << '\n';
            std::cout << "Status: " << task.GetStatus() << '\n';
            break;
        case 3://simple statements
            std::cout << "\nAgent Name: " << agent.GetName() << '\n';
            std::cout << "Specialty: " << agent.GetSpecialty() << '\n';
            std::cout << "Available: " << agent.GetAvailable() << '\n';
            break;
        case 4:
        {// extra scope because of variables
            bool assigned = orchestrator.AssignTask(task, agent);
            if (assigned)
            {
                std::cout << "Task assigned successfully.\n";
            }
            else
            {
                std::cout << "Task could not be assigned.\n";
            }
            break;
        }//I'm out G-Dog
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