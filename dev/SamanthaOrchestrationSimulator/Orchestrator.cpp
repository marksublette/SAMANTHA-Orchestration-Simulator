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
    for (int i = 0; i < agents.size(); i++)
    {
        if (agents[i].GetAvailable())
        {
            task.SetStatus("Assigned");
            task.SetAssignedAgentIndex(i);
            agents[i].SetAvailable(false);
            return true;
        }
    }
    return false;
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