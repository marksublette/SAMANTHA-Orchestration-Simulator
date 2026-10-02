# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

##  Project and Portfolio I: Computer Science

- **Mark Sublette**
- **October 4, 2026**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- `clear`: Clear the Screen
- `pwd`: Print the "Working Directory"
- `ls`: List files and folders
- `ls -a`: List files and folders, including invisible files
- `ls -lah`: List all files and folders, in human readable form
- `cd`: Change directory
- `cd /`: Change directory, go to root directory
- `cd ~`: Change directory and go to user home directory
- `cd ..`: Change directory, go up one folder level
- `cd ../..`: Change directory, go up two folder levels
- `cd ~/Desktop`: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

When I dragged the folder into Terminal, it automatically entered the full path to that folder after the `cd` command. After pressing Enter, Terminal changed the working directory to that folder.

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

Local version control stores different versions of files on the local computer. Centralized version control uses one central server that developers connect to and work from. Distributed version control gives each developer a complete copy of the repository and its history. Git is a distributed version control system.

**2. Using Terminal, there are also essential Git commands to know.**

- `git clone URL`: Clone a repository
- `git config --global user.name "Your Name"`: Set up a global user name
- `git config --global user.email "email@example.com"`: Set up a global email address to match my GitHub account
- `git status`: Show the current state of the directory and staging area
- `git add .`: Add modified files to the next commit
- `git commit -m "message"`: Make a commit with a new message
- `git log`: Show my commit history
- `git help`: Show Git's help screen

**3. Connecting to GitHub using Terminal.**

HTTPS is the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

I open the repository on GitHub, select Code, choose HTTPS, and copy the repository URL. In Terminal I move to the folder where I want the repository and use `git clone` followed by the HTTPS URL. GitHub may require me to authenticate before it can access a private repository. After it is cloned, I can move into the repository folder and work with it locally.

**4. Using .gitignore and Why it's Important**

Most repositories contain a `.gitignore` file.

- **What is the purpose of this file?**

A `.gitignore` file tells Git which files and folders should not be tracked or committed. This keeps temporary, generated, and unnecessary files out of the repository.

- **What is the `.DS_Store` file and why would you want to ignore it?**

`.DS_Store` is a file created by macOS to store folder display settings. It is not part of the project, so there is no reason to track it in Git.

- **What other file or folder would you want to add to a .gitignore file and why?**

I would add `.vs/` because Visual Studio creates temporary settings and cache files there. I actually ran into this during my project when Git tried to track Visual Studio files that did not belong in the repository.

# Reference Links

The Git command reference and GitHub documentation were the most helpful resources for me this week. I also learned a lot by actually using Git and troubleshooting problems with authentication, cloning, and `.gitignore` while setting up my project.

**Terminal Commands**  
[GitHub Git Cheat Sheet](https://docs.github.com/en/get-started/git-basics/git-cheatsheet)

**Three Types of Version Control**  
[Git Clone Guide](https://github.com/git-guides/git-clone)

**Git Commands**  
[GitHub Git Cheat Sheet](https://docs.github.com/en/get-started/git-basics/git-cheatsheet)

**Connecting to GitHub using Terminal**  
[GitHub - Cloning a Repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

**Using .gitignore and Why it's Important**  
[GitHub - Ignoring Files](https://docs.github.com/en/get-started/git-basics/ignoring-files)
