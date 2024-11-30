# Linux Administration - Task1 <img src="linux_logo.png" width="200" height="150" align="center">

## Questions:
* 1- [List Linux distributions](#1-linux-distributions)
* 2- [From the slides what is the man command used for?](#2-man-command)
* 3- [What is the difference between rm and rmdir using man command?](#3-rm-vs-rmdir)
* 4- [Create the following hierarchy under your home directory](#4-create-hierarchy) <img src="q4.png">
* 5- [Copy the /etc/passwd file to your home directory making its name is mypasswd](#5-copy-passwd)
* 6- [Rename this new file to be oldpasswd](#6-rename-passwd)
* 7- [You are in /usr/bin, list four ways to go to your home directory](#7-go-home)
* 8- [List Linux commands in /usr/bin that start with letter w](#8-w-commands)
* 9- [What command type are used for? (from the slide)](#9-command-type)
* 10- [Show 2 types of command file in /usr/bin that start with letter c](#10-c-commands)
* 11- [Using man command find the command to read file](#11-read-file)
* 12- [What is the usage of apropos command?](#12-apropos-command)
* 13- [Bash Script](#13-bash-script) <img src="bash.png">

## Answers:

<img src="new_branch.png">

### 1. Linux Distributions:
* Ubuntu
* Fedora
* CentOS

### 2. Man Command
System wide documentation system that provides short reference manuals (pages) for individual commands, API functions, concepts, configuration file syntax, file formats. Used with External commands and some internal commands.

### 3. Rm vs Rmdir
* `rm` command is used to remove objects such as files, directories, symbolic links, etc from the file system.
<img src="man_rm.png">

* `rmdir` command is used to remove empty directories from the file system.
<img src="man_rmdir.png">

### 4. Create Hierarchy
<img src="q4_ans_pt1.png">

* a. Error, directory not empty.
Removed it using `rm -rf` command.
<img src="q4_ans_a.png">

* b. I knew that `rmdir -p` command will remove the parent directory if it becomes empty after removing the child directory, but i didn't use it because the directory is not empty.

* c. 
    * **Absolute path:** /home/user/docs/mycv
    * **Relative path:** docs/mycv

### 5. Copy Passwd
* Used `cp` command to copy the file.
<img src="q5_ans_pt1.png">
<img src="q5_ans_pt2.png">

### 6. Rename Passwd
* Used `mv` command to rename the file.
<img src="q6_ans.png">

### 7. Go Home
* 1. `cd`
* 2. `cd ~`
* 3. `cd $HOME`
* 4. `cd ../../home/mans`
<img src="q7_ans.png">

### 8. W Commands
<img src="q8_ans.png">

### 9. Command Type
Display information about command type.

### 10. C Commands
<img src="q10_ans.png">

### 11. Read File
* `man -k read` 
<img src="q11_ans.png">

### 12. Apropos Command
Search the manual page names and descriptions.
<img src="q12_ans.png">

### 13. Bash Script
```bash
#!/bin/bash
cd $HOME
mkdir myDirectory
echo "myDirectory created in home folder"
cd myDirectory
mkdir secondDirectory
echo "secondDirectory created in myDirectory"
cd secondDirectory
touch myNotePaper
echo "myNotePaper created in secondDirectory"
cp myNotePaper ../
echo "myNotePaper copied to myDirectory"
cd ..
mv myNotePaper myOldNotePaper
echo "myNotePaper renamed to myOldNotePaper in myDirectory"
echo "Task completed successfully"
```
<img src="q13_ans.png">
<img src="q13_ans_2.png">

---

*Ali Mohamed Ali Elmansoury
ITI Embedded Systems - Intake 45*