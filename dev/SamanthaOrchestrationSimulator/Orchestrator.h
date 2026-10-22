#pragma once

#include "Task.h"
#include "Agent.h"
#include <vector>
class Orchestrator
{
public:
    bool AssignTaskAutomatically(Task& task, std::vector<Agent>& agents);
    int AssignAllWaitingTasks(std::vector<Task>& tasks, std::vector<Agent>& agents);
    bool CompleteTask(Task& task, std::vector<Agent>& agents);
    std::string GetAssignmentFailureReason(
        const Task& task,
        const std::vector<Agent>& agents) const;
};