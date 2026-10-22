SAMANTHA Orchestration Simulator

## Project Overview

During Week 4, I focused on finalizing, testing, and polishing the SAMANTHA Orchestration Simulator. Rather than introducing major new features, I concentrated on improving usability, verifying object interactions, removing unnecessary code, and ensuring the program works reliably.

## Final Features and Improvements

### Improved Task and Agent Displays

Updated the simulator to display more useful information about Tasks and Agents.

- Added Agent capability ratings from 1 to 10 to the Agent display.
    
- Replaced numeric availability indicators with readable Available and Busy statuses.
    
- Updated the Task display to identify the Agent assigned to each active Task.
    
- Verified that the displays update correctly after Task assignment and completion.
    

### Improved Automatic Assignment Feedback

Added a function that explains why a Task cannot be assigned.

The simulator now distinguishes between:

- No Agent having the required specialty.
    
- No Agent having sufficient capability.
    
- All qualified Agents being busy.
    

Tasks that cannot be assigned remain Waiting without changing Agent availability.

## Refactoring and Code Quality

Reviewed the Task, Agent, and Orchestrator class structures to verify appropriate use of objects, references, and data structures.

Removed the unused manual assignment method from `Orchestrator.h` and `Orchestrator.cpp`. This method did not record the assigned Agent's index, which could have caused inconsistent Task tracking.

Preserved the automatic best-fit scheduling system, which selects Agents based on specialty, capability, and availability.

The project uses references to allow the Orchestrator to modify the original Task and Agent objects without unnecessary copying.

## Bug Fixes and Stability

Reviewed previously corrected problems, including invalid input handling, duplicate Task assignments, and Agent release after Task completion.

Verified that:

- Invalid menu selections are rejected.
    
- Invalid Task complexity values are rejected.
    
- Invalid Task numbers are rejected.
    
- Waiting Tasks cannot be completed.
    
- Completed Tasks cannot be completed again.
    
- Assigned and Completed Tasks cannot be reassigned.
    
- Completing a Task releases only its assigned Agent.
    
- Automatic batch assignment continues to function correctly.
    

No new bugs were identified during the completed final testing.

## Final Testing

Tested the simulator in Visual Studio using both valid and invalid inputs.

Testing included menu navigation, Task creation, automatic assignment, Task completion, Agent availability, and repeated operations.

Verified that multiple Tasks can be assigned automatically according to Agent qualifications and that Tasks remain Waiting when no qualified Agent is available.

Confirmed that the application builds successfully after the final refactoring changes.

## Final Program Structure

The simulator uses three primary classes:

**Task:** Stores Task name, complexity, required specialty, status, and assigned Agent index.

**Agent:** Stores Agent name, specialty, capability rating, and availability.

**Orchestrator:** Evaluates Task requirements, selects qualified Agents, assigns Waiting Tasks, completes Tasks, and explains assignment failures.

The main application provides an interactive console menu for creating Tasks, viewing Tasks and Agents, assigning Tasks automatically, completing Tasks, and exiting.

## Final Reflection

The most valuable improvement I made during this course was learning how to manage software development through GitHub. I became more comfortable using branches, commits, Pull Requests, Issues, and Project Boards.

I also gained a better understanding of how multiple classes interact and why refactoring, testing, and documentation are important.

The finished simulator demonstrates how a C++ application can coordinate multiple objects and make automatic decisions based on defined requirements.

## Future Development

If I continued developing the simulator, I would explore additional Agent specialties, Task priorities, more advanced scheduling algorithms, and saving and loading Task information between sessions.