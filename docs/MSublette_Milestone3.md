# Milestone 3 — SAMANTHA Orchestration Simulator

## Project Overview

During Week 3, I focused on improving the reliability, organization, and functionality of the SAMANTHA Orchestration Simulator. I addressed the feedback from Milestone 2, refactored existing code, and expanded the Orchestrator's automatic Task assignment capabilities.

## Features Added

**Specialty and Complexity-Based Assignment**

- Added capability ratings from 1 to 10 for Agents.
    
- Expanded the simulator from two Agents to five, with different specialties and capability levels.
    
- Improved automatic assignment so the Orchestrator evaluates Agent specialty, availability, and capability against Task complexity.
    
- Implemented best-fit selection, choosing the lowest-capability Agent qualified to complete the Task.
    

**Automatic Batch Assignment**

- Added the ability to assign multiple Waiting Tasks with one menu selection.
    
- Tasks are processed in the order they were created.
    
- Tasks that cannot be assigned remain Waiting until a qualified Agent becomes available.
    
- Added ass