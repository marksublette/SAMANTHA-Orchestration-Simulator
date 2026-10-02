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