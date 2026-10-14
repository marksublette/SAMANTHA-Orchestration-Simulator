#include "Orchestrator.h"
bool Orchestrator::AssignTask(Task& task, Agent& agent)
{
    if (task.GetStatus() == "Waiting" && agent.GetAvailable())
    {
        task.SetStatus("Assigned");
        agent.SetAvailable(false);
        return true;
    }
    return false;
}
bool Orchestrator::AssignTaskAutomatically(Task& task, std::vector<Agent>& agents)
{
    if (task.GetStatus() != "Waiting")
    {
        return false;
    }
    int bestAgentIndex = -1;
    for (size_t i = 0; i < agents.size(); i++)
    {
        if (agents[i].GetAvailable() &&
            agents[i].GetSpecialty() == task.GetRequiredSpecialty() &&
            agents[i].GetCapabilityLevel() >= task.GetComplexity())
        {
            if (bestAgentIndex == -1 ||
                agents[i].GetCapabilityLevel() <
                agents[bestAgentIndex].GetCapabilityLevel())
            {
                bestAgentIndex = static_cast<int>(i);
            }
        }
    }
    if (bestAgentIndex == -1)
    {
        return false;
    }
    task.SetStatus("Assigned");
    task.SetAssignedAgentIndex(bestAgentIndex);
    agents[bestAgentIndex].SetAvailable(false);
    return true;
}
int Orchestrator::AssignAllWaitingTasks(
    std::vector<Task>& tasks,
    std::vector<Agent>& agents)
{
    int assignedCount = 0;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].GetStatus() == "Waiting")
        {
            bool assigned = AssignTaskAutomatically(tasks[i], agents);
            if (assigned)
            {
                assignedCount++;
            }
        }
    }
    return assignedCount;
}
bool Orchestrator::CompleteTask(Task& task, std::vector<Agent>& agents)
{
    int agentIndex = task.GetAssignedAgentIndex();
    if (task.GetStatus() != "Assigned")
    {
        return false;
    }
    if (agentIndex < 0 || agentIndex >= agents.size())
    {
        return false;
    }
    task.SetStatus("Completed");
    agents[agentIndex].SetAvailable(true);
    task.SetAssignedAgentIndex(-1);
    return true;
}