# SimOS - Multi-Core Operating System Simulator

## 📌 Project Overview

**SimOS** is a C++17-based multi-core Operating System simulator that demonstrates how processes can be scheduled and executed concurrently across multiple CPU cores.

The project simulates important Operating System concepts such as:

* Process management
* CPU scheduling
* Multi-core execution
* Thread synchronization
* Resource allocation and release
* Process states
* Ready queues
* Time-slice based execution

The simulator uses C++ threads to represent multiple CPU cores and mutexes to ensure safe access to shared resources.

---

## 🎯 Objectives

The main objectives of this project are:

1. To simulate the execution of multiple processes on multiple CPU cores.
2. To implement a thread-safe process scheduler.
3. To demonstrate concurrent process execution using C++ threads.
4. To manage shared system resources safely.
5. To simulate process execution using time slices.
6. To demonstrate process state transitions from `READY` to `RUNNING` and finally `TERMINATED`.

---

## 🛠️ Technologies Used

| Technology              | Purpose                               |
| ----------------------- | ------------------------------------- |
| C++17                   | Main programming language             |
| GNU g++                 | Compiler                              |
| Linux                   | Development and execution environment |
| POSIX/Linux environment | Runtime environment                   |
| `std::thread`           | Multi-core simulation                 |
| `std::mutex`            | Thread synchronization                |
| Makefile                | Build automation                      |
| Git/GitHub              | Version control                       |

---

## ✨ Main Features

### 1. Multi-Core CPU Simulation

The simulator creates **3 CPU core threads**.

Each thread represents an independent CPU core that fetches processes from the shared ready queue and executes them.

```text
                 SimOS Scheduler
                       │
              ┌────────┼────────┐
              ↓        ↓        ↓
           Core 1    Core 2    Core 3
              │        │        │
              ↓        ↓        ↓
           Process  Process  Process
```

The CPU cores operate concurrently using C++ `std::thread`.

---

### 2. Process Management

Each process contains the following information:

* Process ID (PID)
* Process name
* Burst time
* Remaining execution time
* Priority
* Current process state

The project defines four process states:

```text
READY
RUNNING
WAITING
TERMINATED
```

The process state is initially set to `READY`.

When a CPU core starts executing a process, its state changes to `RUNNING`.

After its remaining execution time reaches zero, the process becomes `TERMINATED`.

---

### 3. Ready Queue

The `Scheduler` class manages the ready queue.

The ready queue is implemented using:

```cpp
std::queue<Process>
```

Processes are added to the queue before execution.

CPU cores retrieve processes from this shared queue.

The scheduler provides:

* Process insertion
* Process retrieval
* Process re-queuing
* Queue size checking
* Thread-safe queue access

---

### 4. Thread-Safe Scheduling

Since multiple CPU cores access the same ready queue simultaneously, synchronization is required.

The project uses:

```cpp
std::mutex
```

to protect the queue.

For example:

```cpp
std::lock_guard<std::mutex> lock(queueMutex);
```

This prevents multiple CPU threads from modifying the queue at the same time and helps avoid race conditions.

The `tryGetNextProcess()` function performs the process retrieval while holding the mutex.

---

### 5. Resource Management

The `ResourceManager` class manages shared system resources.

The simulator starts with:

```text
Total Resources = 5
```

A CPU core attempts to allocate:

```text
2 resources
```

before executing a process.

If enough resources are available, they are allocated to the process.

After execution, the resources are released.

Example:

```text
[Resource Manager] PID 101 successfully acquired 2 resources.
[Resource Manager] PID 101 released 2 resources.
```

Resource allocation is protected using a mutex to ensure thread safety.

---

### 6. Process Execution

Each CPU core executes a process for a limited amount of time.

If the required resources are successfully allocated:

```text
Execution Time = 3
```

Otherwise:

```text
Execution Time = 2
```

The remaining process execution time is reduced accordingly.

For example:

```text
Burst Time = 8

After execution:
8 → 5 → 2 → 0
```

When the remaining time reaches zero, the process is terminated.

---

### 7. Process Re-Queueing

If a process has not completed its execution, it is placed back into the ready queue.

Example:

```text
Process Running
      ↓
Time Slice Executed
      ↓
Remaining Time > 0
      ↓
State = READY
      ↓
Reinsert into Ready Queue
```

This allows the process to be executed again by a CPU core.

---

## 📂 Project Structure

```text
sim_os_project-main/
│
├── include/
│   ├── Process.hpp
│   ├── ResourceManager.hpp
│   └── Scheduler.hpp
│
├── src/
│   ├── main.cpp
│   ├── Process.cpp
│   ├── ResourceManager.cpp
│   └── Scheduler.cpp
│
├── Makefile
├── README.md
└── sim_os
```

---

## 🧩 Main Components

### Process

**Files:**

```text
include/Process.hpp
src/Process.cpp
```

The `Process` class represents an operating system process.

It stores:

```text
PID
Name
Burst Time
Remaining Time
Priority
State
```

Important functions include:

```cpp
getPid()
getName()
getBurstTime()
getRemainingTime()
getPriority()
getState()
setState()
reduceRemainingTime()
printProcessInfo()
```

---

### Scheduler

**Files:**

```text
include/Scheduler.hpp
src/Scheduler.cpp
```

The `Scheduler` manages the process ready queue.

Main functions:

```cpp
addProcess()
hasProcesses()
tryGetNextProcess()
requeueProcess()
getQueueSize()
```

The scheduler uses a mutex to make queue operations thread-safe.

---

### ResourceManager

**Files:**

```text
include/ResourceManager.hpp
src/ResourceManager.cpp
```

The `ResourceManager` controls the shared resources available to processes.

Main functions:

```cpp
allocate()
release()
getAvailableResources()
```

A mutex is used to protect resource allocation and release operations.

---

### Main Program

**File:**

```text
src/main.cpp
```

The main program:

1. Creates the scheduler.
2. Creates the resource manager.
3. Creates the initial processes.
4. Adds processes to the ready queue.
5. Creates three CPU threads.
6. Executes processes concurrently.
7. Waits for all CPU threads to finish.
8. Displays the completion message.

---

## 🔄 Working Flow

The overall working of SimOS can be represented as:

```text
             Start SimOS
                  ↓
        Create Scheduler
                  ↓
       Create Resource Manager
                  ↓
        Create Processes
                  ↓
       Add Processes to Queue
                  ↓
       Spawn 3 CPU Threads
                  ↓
       ┌──────────┼──────────┐
       ↓          ↓          ↓
    CPU Core 1 CPU Core 2 CPU Core 3
       │          │          │
       └──────────┼──────────┘
                  ↓
        Get Process from Queue
                  ↓
         Set State = RUNNING
                  ↓
        Request System Resources
                  ↓
          Resources Available?
             /          \
           Yes           No
            ↓             ↓
      Execute 3       Execute 2
      time units      time units
            \             /
             ↓           ↓
          Reduce Remaining Time
                  ↓
          Remaining Time = 0?
             /          \
           Yes           No
            ↓             ↓
       TERMINATED       READY
                          ↓
                   Requeue Process
                          ↓
                   Continue Execution
```

---

## 👥 Initial Processes

The simulator initially creates five processes:

| PID | Process         | Burst Time | Priority |
| --: | --------------- | ---------: | -------: |
| 101 | Process_Alpha   |          6 |        2 |
| 102 | Process_Beta    |          4 |        1 |
| 103 | Process_Gamma   |          8 |        3 |
| 104 | Process_Delta   |          5 |        2 |
| 105 | Process_Epsilon |          7 |        1 |

These processes are inserted into the scheduler's ready queue before the CPU threads start.

---

## ⚙️ System Configuration

The current simulation uses:

```text
Number of CPU Cores: 3
Total Resources: 5
Resources Requested Per Execution: 2
Execution Time With Resources: 3
Execution Time Without Resources: 2
```

---

## 🔨 Building the Project

### Prerequisites

Make sure the following are installed:

* g++
* Make
* C++17 compatible compiler
* Linux/WSL environment

Check the compiler:

```bash
g++ --version
```

---

### Compile

Navigate to the project directory:

```bash
cd sim_os_project-main
```

Then run:

```bash
make
```

The Makefile compiles:

```text
src/main.cpp
src/Process.cpp
src/Scheduler.cpp
src/ResourceManager.cpp
```

and creates the executable:

```text
sim_os
```

---

## ▶️ Running the Simulator

After successful compilation:

```bash
./sim_os
```

The simulator will start and display information about:

* Loaded processes
* CPU core execution
* Resource allocation
* Resource release
* Process re-queueing
* Process termination

---

## 🧹 Cleaning the Build

To remove the compiled object files and executable:

```bash
make clean
```

This removes:

```text
*.o
sim_os
```

---

## 🖥️ Example Output

A typical execution produces output similar to:

```text
=== Starting SimOS Multi-Core Threaded Scheduler & Resource Manager ===

[SimOS] Loaded Process_Alpha (PID: 101) into Ready Queue.
[SimOS] Loaded Process_Beta (PID: 102) into Ready Queue.
[SimOS] Loaded Process_Gamma (PID: 103) into Ready Queue.
[SimOS] Loaded Process_Delta (PID: 104) into Ready Queue.
[SimOS] Loaded Process_Epsilon (PID: 105) into Ready Queue.

=== Spawning Multi-Core CPU Threads (3 Concurrent Cores) ===

[CPU Core 1] Executing -> [Process] ID: 101 | Name: Process_Alpha
[Resource Manager] PID 101 successfully acquired 2 resources.

[CPU Core 2] Executing -> [Process] ID: 102 | Name: Process_Beta
[Resource Manager] PID 102 successfully acquired 2 resources.

[Resource Manager] PID 101 released 2 resources.

[Scheduler] Core 1 requeueing PID 101
```

Because the project uses multiple threads, the exact order of output may vary between executions.

---

## 🔐 Thread Synchronization

Thread synchronization is an important part of this project.

Two shared components require protection:

### Scheduler Queue

Protected using:

```cpp
std::mutex queueMutex;
```

### Resource Manager

Protected using:

```cpp
std::mutex resourceMutex;
```

This prevents multiple CPU threads from simultaneously modifying shared data in an unsafe way.

---

## 🧠 Operating System Concepts Demonstrated

This project demonstrates several important Operating System concepts:

* Process management
* Process states
* CPU scheduling
* Multi-core processing
* Concurrent execution
* Thread synchronization
* Mutex locking
* Shared resource management
* Ready queues
* Time-slice execution
* Process termination
* Re-queuing of processes

---

## 📚 Learning Outcomes

Through this project, the following concepts can be understood practically:

1. How processes can be represented in an OS simulator.
2. How a scheduler manages a ready queue.
3. How multiple CPU cores can execute processes concurrently.
4. Why synchronization is required when threads share data.
5. How mutexes prevent race conditions.
6. How system resources can be allocated and released.
7. How processes can be re-queued when their execution is incomplete.
8. How a process eventually reaches the `TERMINATED` state.

---

## 🚀 Future Improvements

The current project can be extended with additional Operating System features such as:

* Round Robin scheduling with configurable time quantum
* Priority scheduling
* Shortest Job First scheduling
* Multiple resource types
* Waiting/blocked process queues
* Process creation during runtime
* Deadlock detection
* CPU utilization statistics
* Process waiting time calculation
* Turnaround time calculation
* Response time calculation
* Scheduling performance comparison
* Interactive user input
* Graphical monitoring interface

---

## 👨‍💻 Author

**SimOS Project**

**B.Tech Computer Science and Engineering**

---

## 📄 License

This project is intended for educational and academic purposes.
