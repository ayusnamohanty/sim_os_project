# Stage 1 – Project Introduction

## Project Title

**SimOS – Multi-Core Operating System Simulator**

---

## 1. Introduction

SimOS is a C++17-based Operating System simulator developed in a Linux environment. The project demonstrates important Operating System and system programming concepts through the simulation of multiple CPU cores, process scheduling, concurrent process execution, and shared resource management.

The simulator uses C++ threads to represent multiple CPU cores. Processes are placed into a ready queue and are executed by the available CPU cores. Shared resources are managed using synchronization mechanisms to ensure safe concurrent access.

The project is developed as an individual project covering Linux, system programming, and C++ programming concepts.

---

## 2. Problem Statement

Modern Operating Systems need to manage multiple processes and CPU resources efficiently. Understanding how processes are scheduled, executed concurrently, and provided with shared resources can be difficult through theoretical study alone.

The problem addressed by SimOS is to create a practical simulation that demonstrates how multiple processes can be managed and executed across multiple CPU cores while maintaining safe access to shared resources.

---

## 3. Project Objectives

The main objectives of SimOS are:

1. To simulate the execution of multiple processes.
2. To simulate multiple CPU cores using C++ threads.
3. To implement a process ready queue.
4. To demonstrate concurrent process execution.
5. To manage shared system resources.
6. To demonstrate process state transitions.
7. To use thread synchronization to protect shared data.
8. To provide a practical understanding of Operating System concepts.

---

## 4. Project Scope

The scope of the project includes:

- Process representation and management.
- Process state management.
- Ready queue management.
- Multi-core CPU simulation.
- Concurrent execution using C++ threads.
- Shared resource allocation and release.
- Thread synchronization using mutexes.
- Process re-queuing when execution is incomplete.
- Process termination after completion.
- Linux-based compilation and execution.

The project focuses on simulation and educational demonstration rather than implementing a complete real-world Operating System.

---

## 5. Expected Outcome

The expected outcome of the project is a working Linux-based C++ simulator that can:

- Create and manage simulated processes.
- Maintain a ready queue.
- Execute processes using multiple CPU threads.
- Allocate and release shared resources.
- Safely manage concurrent access to shared data.
- Track process execution and termination.
- Demonstrate important Operating System concepts through observable terminal output.

---

## 6. Applications

The project can be used for:

- Understanding Operating System process management.
- Demonstrating CPU scheduling concepts.
- Understanding multi-core execution.
- Learning thread synchronization.
- Understanding shared resource management.
- Academic demonstrations of Operating System concepts.
- Practical learning of C++ system programming.

---

## 7. Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Main programming language |
| Linux / Ubuntu | Development and execution environment |
| g++ | C++ compiler |
| `std::thread` | Simulation of CPU cores |
| `std::mutex` | Thread synchronization |
| `std::queue` | Ready queue implementation |
| Makefile | Build automation |
| Git | Version control |

---

## 8. Major Project Components

The project consists of the following major components:

### Process

Represents an individual process and stores information such as process ID, name, burst time, remaining execution time, priority, and process state.

### Scheduler

Manages the ready queue and provides processes to the CPU cores for execution.

### Resource Manager

Manages the shared resources available to processes and controls resource allocation and release.

### CPU Threads

Multiple C++ threads are used to simulate multiple CPU cores executing processes concurrently.

### Main Program

Coordinates the creation of processes, scheduler, resource manager, CPU threads, and overall simulation execution.

---

## 9. Initial Project Workflow

The basic workflow of the system is:

```text
Start SimOS
     ↓
Create Processes
     ↓
Add Processes to Ready Queue
     ↓
Create CPU Threads
     ↓
CPU Core Gets Process
     ↓
Process State = RUNNING
     ↓
Request Resources
     ↓
Execute Process
     ↓
Reduce Remaining Execution Time
     ↓
Process Completed?
    / \
  Yes  No
   ↓    ↓
TERMINATED
        ↓
      READY
        ↓
   Requeue Process
