# SimOS – System Architecture Diagram

## System Architecture

```text
+------------------------------------------------------+
|                    SimOS Simulator                   |
+------------------------------------------------------+
|              Main Simulation Controller              |
+-------------------------+----------------------------+
                          |
          +---------------+---------------+
          |               |               |
          v               v               v
+----------------+ +----------------+ +------------------+
|    Process     | |   Scheduler    | | Resource Manager |
|   Management   | |                | |                  |
+----------------+ +-------+--------+ +------------------+
                           |
                           v
                  +-------------------+
                  |     CPU Cores     |
                  +---------+---------+
                            |
              +-------------+-------------+
              |             |             |
              v             v             v
          +-------+     +-------+     +-------+
          |Core 1 |     |Core 2 |     |Core 3 |
          +---+---+     +---+---+     +---+---+
              |             |             |
              v             v             v
          Process       Process       Process
Component Responsibilities
Main Simulation Controller

Coordinates the overall simulation and initializes the major components.

Process Management

Creates and maintains simulated processes and their execution information.

Scheduler

Maintains the ready queue and selects processes for CPU execution.

Resource Manager

Handles resource allocation, tracking, and release.

CPU Cores

Simulate concurrent execution of processes using multiple execution threads.

Data Flow
Processes
    |
    v
Scheduler
    |
    v
Ready Queue
    |
    v
CPU Core Assignment
    |
    v
Resource Manager
    |
    v
Process Execution
    |
    v
Resource Release
    |
    v
Process Completion
