#include "Orchestrator.h"
bool Orchestrator::AssignTask(Task& task, Agent& agent)
{
    if (agent.GetAvailable())
    {
        task.SetStatus("Assigned");
        agent.SetAvailable(false);
        return true;
    }
    return false;
}
bool Orchestrator::AssignTaskAutomatically(Task& task, std::vector<Agent>& agents)
{
    for (int i = 0; i < agents.size(); i++)
    {
        if (agents[i].GetAvailable())
        {
            task.SetStatus("Assigned");
            agents[i].SetAvailable(false);
            return true;
        }
    }
    return false;
}