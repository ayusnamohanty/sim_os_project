# Stage 3 – System Design

## 1. Project
SimOS – Multi-Core Operating System Simulator

## 2. Stage
Stage 3 – System Design

## 3. System Overview

SimOS is a multi-core operating system simulator developed using C++.
The simulator models important operating system components such as processes,
CPU cores, scheduling, and resource management.

The system is designed to demonstrate how processes are selected for execution,
assigned to CPU cores, and managed during their execution.

The main components of the simulator are:

- Process Management
- CPU Core Management
- Scheduler
- Resource Manager
- Main Simulation Controller

## 4. System Architecture

The SimOS system follows a modular architecture.

```text
+--------------------------------------------------+
|                 SimOS Simulator                  |
+--------------------------------------------------+
|              Main Simulation Controller          |
+--------------------------------------------------+
          |              |              |
          v              v              v
+---------------+ +---------------+ +---------------+
| Process       | |   Scheduler   | |   Resource    |
| Management    | |               | |   Manager     |
+---------------+ +---------------+ +---------------+
          |              |
          |              v
          |       +----------------+
          +------>|   CPU Cores    |
                  | Core 1, Core 2 |
                  | Core 3, ...    |
                  +----------------+

## 5. Process Management Design

The Process component represents an individual process in the simulator.

Each process contains information such as:

- Process ID
- Process name
- Remaining execution time
- Priority
- Resource requirements
- Execution state

Processes are created and managed by the simulation controller.

A process may move through different states during simulation:

```text
+-------+
| Ready |
+---+---+
    |
    v
+---------+
| Running |
+----+----+
     |
     v
+-----------+
| Terminated|
+-----------+
6. Multi-Core CPU Design

The simulator supports multiple CPU cores.

Each CPU core can execute one process at a time.
The Scheduler checks the available cores and assigns ready processes
to suitable cores.

Example:

              SimOS
                |
        +-------+-------+
        |       |       |
        v       v       v
     Core 1  Core 2  Core 3
        |       |       |
        v       v       v
     Process Process Process

The multi-core design allows multiple processes to execute during the
same simulation period.

7. Scheduler Design

The Scheduler is responsible for selecting processes for execution.

The scheduler maintains a queue of ready processes and selects processes
according to their scheduling priority and availability of CPU cores.

The basic scheduling flow is:

Process Ready
      |
      v
Scheduler Queue
      |
      v
Select Process
      |
      v
Check Available Core
      |
      v
Assign Process to Core
      |
      v
Execute Process

The scheduler is implemented using thread-safe mechanisms so that multiple
CPU cores can safely access the scheduling queue.

8. Resource Manager Design

The Resource Manager controls the allocation and release of resources
required by processes.

Its main responsibilities are:

Check resource availability
Allocate resources to processes
Track allocated resources
Release resources after execution
Maintain the count of available resources

The resource allocation flow is:

Process Requests Resources
          |
          v
Check Availability
      /        \
   Available   Not Available
      |             |
      v             v
   Allocate       Wait
      |
      v
 Process Executes
      |
      v
 Release Resources
9. Main Simulation Flow

The complete simulation follows this general sequence:

Start Simulation
       |
       v
Create Processes
       |
       v
Initialize CPU Cores
       |
       v
Initialize Scheduler
       |
       v
Initialize Resource Manager
       |
       v
Add Processes to Scheduler
       |
       v
Assign Processes to CPU Cores
       |
       v
Allocate Required Resources
       |
       v
Execute Processes
       |
       v
Release Resources
       |
       v
Terminate Completed Processes
       |
       v
Simulation Completed
10. Main Classes

The main classes/modules in the current implementation are:

Process

Represents a process and stores its execution-related information.

Scheduler

Manages the ready queue and selects processes for execution.

ResourceManager

Manages resource allocation and release.

Main

Acts as the entry point of the simulator and controls the simulation.

11. Class Relationship
+----------------------+
|        Main          |
+----------+-----------+
           |
           v
+----------------------+
|      Scheduler       |
+----------+-----------+
           |
           v
+----------------------+
|       Process        |
+----------------------+

+----------------------+
|        Main          |
+----------+-----------+
           |
           v
+----------------------+
|  ResourceManager     |
+----------------------+

The Main module coordinates the Scheduler and Resource Manager.
The Scheduler works with Process objects while assigning processes
to CPU cores.

12. Process Execution Sequence

A simplified process execution sequence is:

Main
 |
 | Create Process
 v
Scheduler
 |
 | Select Process
 v
CPU Core
 |
 | Request Resources
 v
Resource Manager
 |
 | Allocate Resources
 v
CPU Core
 |
 | Execute Process
 v
Resource Manager
 |
 | Release Resources
 v
Process Terminated
13. Thread Safety

Since the simulator supports multiple CPU cores, multiple threads may
access shared data structures.

Thread synchronization is therefore required when accessing shared
scheduler queues and resource information.

The scheduler queue is designed to support safe access by multiple
execution threads.

This prevents race conditions when several CPU cores attempt to obtain
processes from the queue.

14. Data Flow

The major data flow in the system is:

Processes
    |
    v
Scheduler Queue
    |
    v
CPU Core Assignment
    |
    v
Resource Allocation
    |
    v
Process Execution
    |
    v
Resource Release
    |
    v
Process Completion
15. Design Goals

The system design aims to achieve the following:

Simulate multiple CPU cores.
Manage processes using a scheduler.
Provide safe access to shared scheduling data.
Manage resource allocation and release.
Demonstrate process execution and termination.
Maintain a modular C++ implementation.
16. Development Environment

The project is developed using:

Linux / Ubuntu environment
C++ programming language
GNU C++ compiler
Make build system
Git and GitHub for version control
17. Project Modules

The current source structure is organized as follows:

sim_os_project/
├── include/
│   ├── Process.hpp
│   ├── ResourceManager.hpp
│   └── Scheduler.hpp
│
├── src/
│   ├── Process.cpp
│   ├── ResourceManager.cpp
│   ├── Scheduler.cpp
│   └── main.cpp
│
├── docs/
│   ├── diagrams/
│   └── evidence/
│
├── Makefile
├── README.md
└── sim_os
18. Stage 3 Completion Criteria

Stage 3 is considered complete when:

System architecture is documented.
Major system components are identified.
Process execution flow is documented.
Multi-core CPU design is documented.
Scheduler design is documented.
Resource Manager design is documented.
Class relationships are documented.
Data flow is documented.
Thread-safety considerations are documented.
Design documentation is committed to Git.
19. Conclusion

The Stage 3 design provides a structured architecture for the SimOS
multi-core operating system simulator.

The design separates process management, scheduling, CPU execution,
and resource management into modular components. This structure provides
a clear foundation for further implementation, testing, and improvement
of the simulator.
