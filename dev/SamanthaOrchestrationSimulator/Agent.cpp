#include "Agent.h"
Agent::Agent()
{
    name = "";
    specialty = "";
    available = true;
    capabilityLevel = 1;
}
void Agent::SetName(const std::string& agentName)
{
    name = agentName;
}
void Agent::SetSpecialty(const std::string& agentSpecialty)
{
    specialty = agentSpecialty;
}
void Agent::SetAvailable(bool agentAvailable)
{
    available = agentAvailable;
}
void Agent::SetCapabilityLevel(int level)
{
    capabilityLevel = level;
}
std::string Agent::GetName() const
{
    return name;
}
std::string Agent::GetSpecialty() const
{
    return specialty;
}
bool Agent::GetAvailable() const
{
    return available;
}
int Agent::GetCapabilityLevel() const
{
    return capabilityLevel;
}