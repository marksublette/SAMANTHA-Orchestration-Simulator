# Project & Portfolio 1

Mark Sublette

Hello my name is Mark. I am a student from Beaumont, TX. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>
### Week 1
**Overview:**  
This week I set up my GitHub repository, Project board, Issues, and development environment for the SAMANTHA Orchestration Simulator. I created the Task, Agent, and Orchestrator classes and built a working menu that lets the user create a task, view the task and agent, and assign the task to an available agent.
<br>
**Challenges:**  
The biggest challenge this week was getting GitHub and Visual Studio to work together correctly. I had problems with authentication, cloning the private repository, and getting Git to ignore files created by Visual Studio. It took some time to figure out, but I got everything working.
<br>
**Accomplishments:**  
I learned quite a bit about GitHub this week and understand branches, Issues, Project boards, and commits better than I did when I started. I also got the first working version of the simulator running. The Orchestrator can now assign a Task to an Agent and update both of their states.
<br>
**Next Steps:**  
Next week I want to add more functionality to the simulator, improve input validation, and start expanding the orchestration system beyond a single task and agent.
<br>
### Week 2
**Overview:**  
This week I expanded the SAMANTHA Orchestration Simulator from handling one Task and Agent to handling multiple Tasks and Agents using vectors. I added automatic task assignment, task completion and Agent release, and improved input validation and user feedback.
**Challenges:**  
The biggest challenge was changing the program to work with multiple objects without breaking the functionality I already had. Input validation also took some testing because I wanted the program to recover correctly from both incorrect values and incorrect input types.
**Accomplishments:**  
I have a much better understanding of vectors, references, and how objects can interact with each other. The Orchestrator can now find an available Agent automatically, and completing a Task releases that Agent so it can be used again.
**Next Steps:**  
Next week I want to continue improving the orchestration logic and code organization while building on the working system I have now.
### Week 3
**Week 3 End-of-Week Stand-Up — SAMANTHA Orchestration Simulator**

**Overview:** This week I focused on improving the reliability, organization, and functionality of my simulator. I started by addressing the feedback from Milestone 2 and then expanded the Orchestrator's decision-making capabilities.

**Improvements:** I replaced the old input validation with getline(), stoi(), and try/catch. I also fixed the issue where Tasks could be assigned multiple times. I refactored the main menu into smaller functions to make the code easier to read and maintain.

The biggest improvement was expanding automatic Task assignment. Users now select a Task type and complexity level, and the Orchestrator evaluates Agent specialties, capability ratings, and availability to choose the best-qualified Agent. It can also assign multiple waiting Tasks automatically with one menu selection.

**Challenges:** One challenge was understanding why refactoring working code was necessary. I learned that improving code organization isn't necessarily about making a program faster, but about making it easier to maintain and expand. I also had to troubleshoot specialty matching and make sure Agents were released correctly after completing Tasks.

**Feedback:** Kari recommended improving input validation and preventing duplicate Task assignments. I implemented and tested both corrections. Her feedback helped me focus on reliability before adding more functionality.

**Next Steps:** My focus for Week 4 is completing final testing, fixing any remaining bugs, improving documentation, and preparing the simulator for delivery and my portfolio.

### Week 4

My final stand up...
