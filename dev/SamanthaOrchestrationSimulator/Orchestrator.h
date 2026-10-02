#pragma once

#include "Task.h"
#include "Agent.h"
class Orchestrator
{
public:
    bool AssignTask(Task& task, Agent& agent);
};