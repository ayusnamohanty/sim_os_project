# Stage 3 – Progress Evidence

## Project

SimOS – Multi-Core Operating System Simulator

## Stage

Stage 3 – System Design

---

## Evidence 1 – System Architecture

The overall architecture of the SimOS simulator has been designed.

The architecture identifies the following major components:

- Main Simulation Controller
- Process Management
- Scheduler
- Resource Manager
- CPU Cores

The responsibilities and interaction between these components are documented
in the Stage 3 system design.

---

## Evidence 2 – Process Design

The Process component and its execution states have been documented.

The main process states are:

- READY
- RUNNING
- TERMINATED

The transitions between these states are represented in the State Machine Diagram.

---

## Evidence 3 – Multi-Core CPU Design

The system design includes multiple CPU cores for simulated concurrent
process execution.

The architecture demonstrates how processes are assigned to different
CPU cores by the Scheduler.

---

## Evidence 4 – Scheduler Design

The Scheduler design includes:

- Ready queue management
- Process selection
- CPU core assignment
- Process re-queuing when execution is not completed

---

## Evidence 5 – Resource Manager Design

The Resource Manager is responsible for:

- Checking resource availability
- Allocating resources
- Tracking allocated resources
- Releasing resources
- Maintaining available resources

---

## Evidence 6 – UML Diagrams

The following diagrams have been prepared:

1. System Architecture Diagram
2. Class Diagram
3. Sequence Diagram
4. State Machine Diagram

---

## Evidence 7 – Class Design

The main classes/modules identified in the system are:

- Process
- Scheduler
- ResourceManager
- Main

Their responsibilities and relationships are documented in the Class Diagram.

---

## Evidence 8 – Sequence Design

The Process Execution Sequence documents the interaction between:

- Main
- Scheduler
- CPU Core
- Resource Manager

The sequence covers process creation, scheduling, resource allocation,
execution, resource release, and process completion.

---

## Evidence 9 – Thread Safety

Thread-safety considerations have been documented because multiple CPU
execution threads may access shared scheduling and resource data.

Synchronization is required to prevent unsafe concurrent access and
race conditions.

---

## Evidence 10 – Development Environment

The project continues to use:

- Linux / Ubuntu
- C++
- GNU C++ compiler
- Make
- Git
- GitHub

---

## Stage 3 Progress Status

The following Stage 3 activities have been completed:

- [x] System architecture documented
- [x] Major components identified
- [x] Process design documented
- [x] Multi-core CPU design documented
- [x] Scheduler design documented
- [x] Resource Manager design documented
- [x] Data flow documented
- [x] Class Diagram created
- [x] Sequence Diagram created
- [x] State Machine Diagram created
- [x] System Architecture Diagram created

---


