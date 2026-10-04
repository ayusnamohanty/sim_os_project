# Stage 2 – Project Requirements & Development Plan

## Project Title

**SimOS – Multi-Core Operating System Simulator**

---

## 1. Project Requirements Document (PRD)

### 1.1 Purpose

The purpose of SimOS is to provide a practical simulation of Operating System concepts using C++ in a Linux environment.

The simulator focuses on process management, multi-core CPU execution, scheduling, concurrent execution, and shared resource management.

---

## 2. Project Scope

The project will simulate the following Operating System activities:

- Creation and management of processes.
- Maintaining a ready queue.
- Scheduling processes for CPU execution.
- Simulating multiple CPU cores.
- Concurrent process execution using C++ threads.
- Allocation and release of shared resources.
- Process state management.
- Synchronization of shared data.
- Process completion and termination.
- Linux-based compilation and execution.

The project is an educational simulator and does not attempt to implement a complete real-world Operating System.

---

## 3. Functional Requirements

Functional requirements describe what the system should do.

### FR-01: Process Management

The system shall create and maintain simulated processes with information such as:

- Process ID
- Process name
- Remaining execution time
- Priority
- Process state

### FR-02: Ready Queue

The system shall maintain a ready queue containing processes waiting for CPU execution.

### FR-03: Process Scheduling

The scheduler shall select processes from the ready queue and assign them to available CPU cores.

### FR-04: Multi-Core CPU Simulation

The system shall simulate multiple CPU cores using C++ threads.

Each CPU thread shall execute assigned processes independently.

### FR-05: Process Execution

The system shall simulate process execution by reducing the remaining execution time of a process.

### FR-06: Process State Management

The system shall maintain appropriate process states such as:

- READY
- RUNNING
- TERMINATED

### FR-07: Resource Management

The system shall manage shared resources and allow processes to acquire and release resources.

### FR-08: Resource Synchronization

The system shall protect shared resources and shared data structures from unsafe concurrent access.

### FR-09: Process Re-queuing

If a process does not complete during its execution period, the system shall place it back into the ready queue for further execution.

### FR-10: Process Termination

The system shall mark a process as terminated after its required execution is completed.

### FR-11: Simulation Completion

The system shall display a completion message after all simulated processes have completed execution.

---

## 4. Non-Functional Requirements

### NFR-01: Performance

The simulator should execute the simulation efficiently without unnecessary delays.

### NFR-02: Reliability

The system should complete the simulation without crashes during normal execution.

### NFR-03: Concurrency Safety

Shared data structures and resources should be protected from race conditions using suitable synchronization mechanisms.

### NFR-04: Maintainability

The source code should be modular, readable, and organized into suitable source and header files.

### NFR-05: Portability

The project should be capable of being compiled and executed in a Linux environment using standard C++ tools.

### NFR-06: Usability

The simulator should provide clear terminal output showing important process, CPU, resource, and simulation events.

### NFR-07: Version Control

The project shall use Git for tracking development progress and maintaining different stages of the project.

### NFR-08: Documentation

Each project stage shall have proper documentation, evidence, and progress records.

---

## 5. Major Project Modules

The project is divided into the following major modules.

### 5.1 Process Module

Responsible for representing and maintaining process information.

Main responsibilities:

- Store process details.
- Maintain process state.
- Track remaining execution time.
- Store process priority.

### 5.2 Scheduler Module

Responsible for managing the ready queue and assigning processes to CPU cores.

Main responsibilities:

- Maintain the ready queue.
- Select processes for execution.
- Re-queue processes that are not completed.

### 5.3 CPU/Core Module

Responsible for simulating CPU core execution.

Main responsibilities:

- Represent CPU cores using threads.
- Obtain processes from the scheduler.
- Execute assigned processes.
- Report process completion.

### 5.4 Resource Manager Module

Responsible for managing shared resources.

Main responsibilities:

- Track available resources.
- Allocate resources to processes.
- Release resources after process execution.
- Synchronize resource access.

### 5.5 Synchronization Module

Responsible for protecting shared data structures used by multiple threads.

Main responsibilities:

- Protect the ready queue.
- Protect shared resource information.
- Prevent unsafe concurrent access.

### 5.6 Main Simulation Module

Responsible for coordinating the complete simulation.

Main responsibilities:

- Initialize the simulator.
- Create processes.
- Start CPU threads.
- Coordinate scheduler and resource manager.
- Detect simulation completion.

---

## 6. Project Features

The main planned features are:

1. Multi-core CPU simulation.
2. Multi-threaded process execution.
3. Process ready queue.
4. Process scheduling.
5. Process state tracking.
6. Shared resource management.
7. Resource allocation and release.
8. Thread synchronization.
9. Process re-queuing.
10. Process termination.
11. Terminal-based simulation output.
12. Linux-based execution.

---

## 7. Development Environment

The project will be developed using:

| Tool/Technology | Purpose |
|---|---|
| Linux / Ubuntu | Development environment |
| C++17 | Programming language |
| g++ | Compiler |
| Make | Build automation |
| C++ Threads | Multi-core simulation |
| Mutex | Thread synchronization |
| Queue | Ready queue |
| Git | Version control |
| GitHub | Remote repository |

---

## 8. Project Deliverables

The following deliverables are planned for the complete project:

### Documentation

- Stage 1 – Project Introduction
- Stage 2 – Requirements & Development Plan
- Stage 3 – System Design & Architecture
- Stage 4 – Initial Implementation & Prototype
- Stage 5 – Testing, Integration & Improvement
- Stage 6 – Final Implementation & Presentation

### Technical Deliverables

- C++ source code
- Header files
- Makefile
- Working executable
- UML diagrams
- System architecture diagram
- Testing documentation
- Git repository
- Project report

---

## 9. Development Plan

The project will be developed incrementally through six stages.

### Stage 1 – Project Introduction

Completed activities:

- Project idea identified.
- Problem statement defined.
- Objectives defined.
- Project scope defined.
- Expected outcome identified.
- Major components identified.

### Stage 2 – Requirements & Development Plan

Current stage activities:

- Define functional requirements.
- Define non-functional requirements.
- Prepare PRD.
- Identify modules and features.
- Define deliverables.
- Prepare development plan and timeline.

### Stage 3 – System Design & Architecture

Planned activities:

- Prepare system architecture.
- Prepare architecture diagram.
- Identify component responsibilities.
- Define data structures.
- Prepare class diagram.
- Prepare sequence diagram.
- Prepare state machine diagram.
- Finalize implementation plan.

### Stage 4 – Initial Implementation & Prototype

Planned activities:

- Implement core modules.
- Integrate modules.
- Build the initial working prototype.
- Demonstrate basic functionality.
- Record development issues and solutions.

### Stage 5 – Testing, Integration & Improvement

Planned activities:

- Perform unit testing.
- Perform integration testing.
- Perform system testing.
- Debug identified issues.
- Improve reliability and performance.
- Update documentation and Git repository.

### Stage 6 – Final Implementation & Presentation

Planned activities:

- Complete final implementation.
- Perform final testing.
- Prepare final documentation.
- Prepare presentation.
- Demonstrate the complete system.
- Document limitations and future improvements.

---

## 10. Development Timeline

| Stage | Main Activities | Planned Output |
|---|---|---|
| Stage 1 | Introduction, objectives, scope | Project introduction |
| Stage 2 | Requirements, PRD, development plan | Requirements document |
| Stage 3 | Architecture, UML, data structures | System design |
| Stage 4 | Core implementation and prototype | Working prototype |
| Stage 5 | Testing, debugging, improvement | Tested system |
| Stage 6 | Final implementation and presentation | Final project |

---

## 11. Version Control Plan

Git will be used throughout the project to maintain development history.

The following approach will be followed:

- Each major stage will have one or more meaningful commits.
- Documentation changes will be committed.
- Major implementation changes will be committed separately.
- The main branch will contain stable project versions.
- The GitHub repository will be updated regularly.
- Commit messages will clearly describe the changes.

Example commit messages:

```text
Complete Stage 1 project documentation
Complete Stage 2 requirements and development plan
Add system architecture and UML diagrams
Implement initial SimOS prototype
Add testing and integration documentation
Complete final project documentation
