#include "Agent.h"
Agent::Agent()
{
    name = "";
    specialty = "";
    available = true;
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