#include <iostream>
#include "Task.h"
#include "Agent.h"
#include "Orchestrator.h"
int main()
{
    Task testTask;
    testTask.SetName("Generate Animation");
    testTask.SetComplexity(8);
    testTask.SetStatus("Waiting");
    std::cout << "Task Name: " << testTask.GetName() << '\n';
    std::cout << "Complexity: " << testTask.GetComplexity() << '\n';
    std::cout << "Status: " << testTask.GetStatus() << '\n';
    std::cout << '\n';
    Agent testAgent;
    testAgent.SetName("Animation Agent");
    testAgent.SetSpecialty("Animation");
    testAgent.SetAvailable(true);
    std::cout << "Agent Name: " << testAgent.GetName() << '\n';
    std::cout << "Specialty: " << testAgent.GetSpecialty() << '\n';
    std::cout << "Available: " << testAgent.GetAvailable() << '\n';
    std::cout << '\n';
    Orchestrator testOrchestrator;
    bool assigned = testOrchestrator.AssignTask(testTask, testAgent);
    std::cout << "Task Assigned: " << assigned << '\n';
    std::cout << "Task Status: " << testTask.GetStatus() << '\n';
    std::cout << "Agent Available: " << testAgent.GetAvailable() << '\n';
    return 0;
}