> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**

→ SAMANTHA Orchestration Simulator

  
**What does your program currently do? (1–3 sentences)**   

→ The program currently allows the user to create a task, view the task and agent information, and assign the task to an available agent. The Orchestrator handles the assignment and updates the task status and agent availability when the assignment is successful.


---
## 🔍 Current Progress Check  
  
**What is working right now?**   

→ The menu and program loop are working. I can create and view a task, view the agent, and use the Orchestrator to assign the task to the agent. The task status and agent availability update correctly after assignment.

  
**What is NOT working or incomplete?**   

→ The program currently supports only one task and one agent. There is no way to complete a task and release the agent, and the assignment logic does not yet choose between multiple agents.

  
**What feels confusing or messy in your code?**   

→ The program is still small, so the code does not feel very messy yet. The main concern is that more of the program logic is starting to collect inside the menu in main(), so I want to keep the classes responsible for their own parts as the project grows.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   

→ Multiple Task and Agent Support

  
**What does this feature do?**   

→ This feature will allow the simulator to store and manage multiple tasks and multiple agents instead of being limited to one of each.
  
**Why is this feature important?**   

→ An orchestration system needs to make decisions between multiple tasks and agents. Supporting more than one of each will allow the simulator to begin testing more realistic assignment behavior. 
  
---
### Feature 2  
**Name:**   

→ Improved Automatic Task Assignment

  
**What does this feature do?**   

→ This feature will allow the Orchestrator to look at the available agents and decide which agent should receive a task instead of requiring the program to provide one specific agent. 
  
**Why is this feature important?**   

→ The main purpose of the simulator is to model orchestration. Giving the Orchestrator responsibility for choosing an agent makes the simulation closer to the system I eventually want to test and expand.   
  
---
  
### Feature 3 (optional)  
**Name:**   

→ Task Completion and Agent Release
  
**What does this feature do?**   

→ This feature will allow the user to mark an assigned task as completed. When the task is completed, its status will change to Completed and the agent assigned to it will become available again.
  
**Why is this feature important?**   

→ Right now an agent becomes unavailable after receiving a task and stays that way. Completing tasks and releasing agents creates a full work cycle and allows agents to be reused for additional tasks.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   

→ I do not currently plan to add another class this week. Task, Agent, and Orchestrator already separate the main responsibilities of the program. I will add another class later if the program grows enough to need one.   
  
**Will you modify any existing classes? How?**   

→ Yes. Task will need additional information to track which agent is assigned to it. Agent may need additional state for handling assignments. Orchestrator will be expanded so it can work with multiple tasks and agents, choose an available agent, complete tasks, and release agents.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   

→ I plan to use a `std::vector<Task>` to store multiple tasks and a `std::vector<Agent>` to store multiple agents. This will allow the number of tasks and agents to grow while the program is running. 
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →  The simulator displays the main menu and loads the available tasks and agents.
2. User chooses →  The user selects an option to create or view tasks, view agents, assign a task, complete a task, or exit the program.
3. Program responds →  The program performs the selected action and displays the results. The Orchestrator handles task assignment and updates the status of the affected Task and Agent.
4. Loop/next step → The program returns to the main menu so the user can continue working with tasks and agents until Exit is selected.
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→  I will make the prompts more specific so the user knows what information is expected and what each menu option does.
  
- Better error handling:   
→  I will add input validation so invalid menu choices and incorrect values do not cause the program to fail or enter a bad input state. The program will explain the problem and allow the user to try again.
  
- Improved menu/navigation:   
→  I will update the menu as new features are added and keep the options organized and consistent. After completing an action, the user will return to the main menu instead of reaching a dead end.
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   I think the hardest part will be changing the program from one Task and one Agent to vectors containing multiple Tasks and Agents without breaking the functionality that already works. The Orchestrator will also need to make decisions about which Agent should receive a Task.
  
**What is your plan if you get stuck?**   
→  I will test one change at a time instead of changing the entire program at once. I will use the debugger and console output to follow what the program is doing, review the class material when necessary, and ask questions when I do not understand why something is happening.

---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→  Input validation and error handling.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→  I will practice checking user input before allowing the program to use it, test the program with intentionally incorrect input, and learn how to clear and recover from a failed input state instead of allowing bad input to break the program loop.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]  Add support for multiple Tasks and Agents 
- [ ]  Improve automatic task assignment logic
- [ ]  Add task completion and Agent release
- [ ]  Add input validation and user feedback
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.

---

## Week 2 Development Results

**Features Added:**  
→ Added support for multiple Tasks and Agents using vectors. Added automatic task assignment, Task completion, and Agent release so Agents can be reused after completing work.

**Code Structure Updates:**  
→ Expanded the Task class so a Task can remember which Agent was assigned to it. Expanded the Orchestrator so it can search the Agent collection automatically and complete Tasks while releasing the correct Agent.

**Usability Improvements:**  
→ Added input validation for the main menu, Task complexity, and Task selection. Invalid input now displays a helpful message and allows the program to recover instead of leaving the input stream in a failed state.

**What Changed and Why:**  
→ The Week 1 program was limited to one Task and one Agent. These changes allow the simulator to manage multiple objects and complete a full Task lifecycle from Waiting to Assigned to Completed. The input improvements also make the program easier and safer for someone else to use.