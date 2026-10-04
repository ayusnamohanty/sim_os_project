# Stage 4 – Implementation and Prototype

## 1. Project

SimOS – Multi-Core Operating System Simulator

## 2. Stage

Stage 4 – Implementation and Prototype

## 3. Stage Objective

The objective of Stage 4 is to implement the system design developed in Stage 3 and verify that the main SimOS components work together as a functional prototype.

The implementation focuses on:

- Process management
- Multi-core CPU execution
- Thread-safe scheduling
- Resource management
- Process execution and termination
- Integration of all major components

## 4. Implementation Environment

The SimOS prototype is developed using:

- Linux / Ubuntu 24.04
- C++ programming language
- GNU C++ compiler
- Make build system
- Git and GitHub for version control

## 5. Implemented Modules

The current implementation contains the following major modules:

### Process

The Process module represents individual processes in the simulator.

It stores information such as:

- Process ID
- Process name
- Remaining execution time
- Priority
- Process execution state
- Resource requirements

The process information is used by the scheduler to select processes for execution.

### Scheduler

The Scheduler manages the ready queue of processes.

Its responsibilities include:

- Maintaining the ready queue
- Selecting processes for execution
- Assigning processes to CPU cores
- Re-queuing processes that are not yet completed
- Providing thread-safe access to the scheduling queue

### Resource Manager

The Resource Manager controls the resources required by processes.

Its responsibilities include:

- Checking resource availability
- Allocating resources
- Tracking available resources
- Releasing resources after execution
- Preventing resource allocation when resources are unavailable

### Main

The Main module acts as the entry point of the simulator.

It:

1. Creates processes.
2. Loads processes into the ready queue.
3. Initializes the scheduler.
4. Initializes the resource manager.
5. Starts the CPU core threads.
6. Coordinates process execution.
7. Displays the simulation results.

## 6. Multi-Core CPU Implementation

The prototype supports concurrent execution using multiple CPU core threads.

The current simulation demonstrates three concurrent CPU cores.

Each CPU core:

- Requests a process from the scheduler.
- Executes the selected process.
- Requests required resources.
- Releases resources after execution.
- Re-queues the process if execution is not complete.
- Terminates the process when its remaining execution time reaches zero.

This demonstrates the basic behavior of a multi-core operating system scheduler.

## 7. Process Scheduling Implementation

Processes are initially loaded into the scheduler's ready queue.

The scheduler selects processes from the queue and assigns them to available CPU cores.

During execution, a process may still have remaining execution time. In this situation, the scheduler re-queues the process so that it can continue execution during a later scheduling cycle.

The scheduling flow is:

```text
Process Created
      |
      v
Ready Queue
      |
      v
Scheduler Selects Process
      |
      v
Assign to CPU Core
      |
      v
Execute Process
      |
      +------------------+
      |                  |
      | Remaining Time > 0
      v                  |
Re-queue Process <-------+
      |
      | Remaining Time = 0
      v
Process Terminated
