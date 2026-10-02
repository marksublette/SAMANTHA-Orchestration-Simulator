#pragma once
#include <string>
class Agent
{
private:
    std::string name;
    std::string specialty;
    bool available;
public:
    Agent();
    void SetName(const std::string& agentName);
    void SetSpecialty(const std::string& agentSpecialty);
    void SetAvailable(bool agentAvailable);
    std::string GetName() const;
    std::string GetSpecialty() const;
    bool GetAvailable() const;
};