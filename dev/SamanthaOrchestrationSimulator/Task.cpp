#include "Task.h"
Task::Task()
{
    name = "";
    complexity = 1;
    status = "Waiting";
    assignedAgentIndex = -1;
}
void Task::SetName(const std::string& taskName)
{
    name = taskName;
}
void Task::SetComplexity(int taskComplexity)
{
    complexity = taskComplexity;
}
void Task::SetStatus(const std::string& taskStatus)
{
    status = taskStatus;
}
void Task::SetAssignedAgentIndex(int agentIndex)
{
    assignedAgentIndex = agentIndex;
}
std::string Task::GetName() const
{
    return name;
}
int Task::GetComplexity() const
{
    return complexity;
}
std::string Task::GetStatus() const
{
    return status;
}
int Task::GetAssignedAgentIndex() const
{
    return assignedAgentIndex;
}