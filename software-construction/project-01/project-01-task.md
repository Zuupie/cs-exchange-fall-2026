# Project 1 – Using the Linux Terminal

**Course:** COMP 2710 (Software Construction) · Fall 2026
**Environment:** Linux (remote AU server via SSH, or WSL on Windows)
**Topics:** Basic Linux commands, `script`, system info, compiling C++ with g++, `tar`

> Task description summarized in my own words. The original assignment sheet is the instructor's material and is not included here.

## Overview

Set up a Linux programming environment for the course, practice the basic terminal commands, inspect the machine's hardware, and compile a first C++ program. Terminal sessions are recorded with the `script` command, and everything is submitted as one compressed archive.

## 1. Environment Setup

Either connect to the remote Linux server via SSH (Mac/Linux) or use the Windows Subsystem for Linux. On the shared lab machines there are no admin rights, so `sudo` is off-limits there.

## 2. Recording Sessions with `script`

`script <filename>` records everything typed and printed in the terminal until `exit` is entered. Without a filename, the log is saved as `typescript`.

```bash
script commands.script
# ... run commands ...
exit
```

## 3. Tasks

### Task 1 – Basic commands → `commands.script`
Record a session demonstrating each of these:

| Command | Purpose |
|---------|---------|
| `pwd` | Show current directory |
| `ls` | List files |
| `mkdir` | Create a directory |
| `cp` | Copy a file |
| `mv` | Move/rename a file |
| `rm` | Delete a file |
| `chmod` | Change file permissions |
| `clear` | Clear the screen |
| `who` | Show logged-in users |
| `nproc` | Show number of CPU cores |
| `g++ --help` | Show compiler help |

### Task 2 – System information
Save the output of these commands to files using redirection (`command > file.txt`):

| Command | Output file |
|---------|-------------|
| `more /proc/cpuinfo` | `cpuinfo.txt` |
| `more /proc/meminfo` | `meminfo.txt` |
| `lspci` | `lspci.txt` |
| `more /proc/interrupts` | `interrupts.txt` |

These reveal CPU frequency, cache size, memory, PCI devices, and interrupt sources.

### Task 3 – First C++ program → `simple.cpp`
Write a program that:

1. Asks how many integers (fewer than 10) the user wants to enter, then reads them
2. Prints the factorial of each positive integer entered
3. Computes and prints the standard deviation of the numbers

Check the compiler version with `g++ -v`, then compile and run:

```bash
g++ simple.cpp -o simple
./simple
```

## 4. Deliverable

Put all six files in a `project1/` directory and pack them into `Firstname_Lastname.tar.gz`:

1. `commands.script`
2. `cpuinfo.txt`
3. `meminfo.txt`
4. `lspci.txt`
5. `interrupts.txt`
6. `simple.cpp`

```bash
tar -zcvf Firstname_Lastname.tar.gz project1/
```

## Grading Breakdown

| Part | Weight |
|------|--------|
| Environment setup | 10% |
| Linux commands (Task 1) | 33% |
| System information (Task 2) | 12% |
| g++: compile / run / output (Task 3) | 35% |
| tar archive | 10% |