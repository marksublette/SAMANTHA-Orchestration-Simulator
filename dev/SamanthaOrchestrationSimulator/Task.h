#pragma once
#include <string>
class Task
{
private:
    std::string name;
    int complexity;
    std::string status;
    int assignedAgentIndex;
    std::string requiredSpecialty;
public:
    Task();
    void SetName(const std::string& taskName);
    void SetComplexity(int taskComplexity);
    void SetStatus(const std::string& taskStatus);
    std::string GetName() const;
    int GetComplexity() const;
    std::string GetStatus() const;
    void SetAssignedAgentIndex(int agentIndex);
    int GetAssignedAgentIndex() const;
    void SetRequiredSpecialty(const std::string& specialty);
    std::string GetRequiredSpecialty() const;
};