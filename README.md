# SimOS - Multi-Core Operating System Simulator

SimOS is an advanced multi-threaded Operating System simulator developed using C++17. The main purpose of the project is to simulate core kernel-level operations such as concurrent multi-core CPU execution, a thread-safe scheduling queue, process lifecycle management, and system resource allocation.

The system manages process states, ensures thread safety using mutual exclusion primitives, and handles concurrent task execution across multiple simulated CPU cores. If processes request or release system resources, the resource manager ensures safe allocation without race conditions or data corruption.

The project demonstrates practical concepts of C++17, multithreading, synchronization primitives, mutexes, process scheduling, resource management, Makefile automation, and version control.

---

## Project Type

Individual Capstone Project

---

## Programming Language

C++17

---

## Operating System

Linux / Ubuntu (WSL)

---

## Build System

GNU Make

---

## Compiler

GNU C++ Compiler (g++)

---

## Main Features

### 1. Multi-Core CPU Execution
* Spawns independent worker threads to simulate concurrent execution across multiple physical CPU cores.
* Allows multiple CPU cores to pull and process tasks simultaneously.

### 2. Thread-Safe Scheduler Queue
* Maintains a central task dispatch queue where processes wait for execution.
* Protected by synchronization primitives (`std::mutex`, locks) to prevent race conditions and ensure two CPU cores never collide over queue modifications.

### 3. Process Lifecycle Management
* Defines process structures with unique Process IDs (PIDs), priority levels, and execution states (`Ready`, `Running`, `Terminated`).
* Tracks dynamic state transitions as tasks progress through the system.

### 4. System Resource Management
* Simulates system and hardware blocks that processes must request and utilize during execution.
* Controls allocation and safely reclaims resources once a process finishes its lifecycle.

### 5. Robust Quality Diagnostics
* Tested using Valgrind to guarantee complete memory safety, verifying zero memory leaks (`All heap blocks were freed`) and zero context errors.

---

## Project Structure

```text
sim_os_project/
│
├── include/
│   ├── Process.hpp
│   ├── Scheduler.hpp
│   └── ResourceManager.hpp
│
├── src/
│   ├── Process.cpp
│   ├── Scheduler.cpp
│   ├── ResourceManager.cpp
│   └── main.cpp
│
├── Makefile
└── README.md
