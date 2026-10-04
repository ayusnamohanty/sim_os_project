# Stage 6 – Final Implementation and Presentation

## 1. Project

SimOS – Multi-Core Operating System Simulator

## 2. Stage

Stage 6 – Final Implementation & Presentation

## 3. Stage Objective

The objective of Stage 6 is to complete the SimOS project, verify the final
working implementation, summarize the testing results, document the
achievements and limitations, and prepare the project for final
demonstration and presentation.

## 4. Final Implementation

The final SimOS implementation integrates the major components developed
through the previous stages.

The final system includes:

- Process Management
- Scheduler
- Multi-Core CPU execution
- Resource Manager
- Main Simulation Controller
- Process re-queuing
- Process termination
- Thread-based concurrent execution

## 5. Final System Architecture

The final system follows the modular architecture designed during Stage 3.

```text
                    SimOS Simulator
                           |
                           v
              Main Simulation Controller
                           |
          +----------------+----------------+
          |                |                |
          v                v                v
    Process Manager    Scheduler      Resource Manager
                           |
                           v
                     CPU Core Threads
                    /       |       \
                   v        v        v
                Core 1    Core 2    Core 3
                   |        |        |
                   +--------+--------+
                            |
                            v
                     Process Execution
The modules work together to simulate process scheduling, CPU execution,
resource allocation, and process completion.

6. Final Execution

The final simulator was executed using:

./sim_os

The final execution demonstrated:

Multiple CPU cores executing processes.
Scheduler re-queuing incomplete processes.
Resource allocation and release.
Process execution across different CPU cores.
Successful process termination.
Completion of the complete simulation.
7. Final Execution Evidence

During the final test, processes were executed on different CPU cores.

Examples include:

[CPU Core 2] Executing -> Process_Alpha
[CPU Core 1] Executing -> Process_Beta
[CPU Core 3] Executing -> Process_Gamma

The Scheduler also re-queued processes that still had remaining execution
time.

Example:

[Scheduler] Core 2 requeueing PID 105

Resource allocation and release were also observed:

[Resource Manager] PID 105 successfully acquired 2 resources. Remaining: 3
[Resource Manager] PID 105 released 2 resources. Available now: 5
8. Final Process Completion

All five simulated processes completed their execution during the final
test.

The observed process termination messages included:

[SimOS] Process 102 (Process_Beta) has TERMINATED on Core 1.
[SimOS] Process 101 (Process_Alpha) has TERMINATED on Core 2.
[SimOS] Process 104 (Process_Delta) has TERMINATED on Core 1.
[SimOS] Process 105 (Process_Epsilon) has TERMINATED on Core 2.
[SimOS] Process 103 (Process_Gamma) has TERMINATED on Core 3.

The final simulation ended with:

=== SimOS Multi-Core Simulation Completed Successfully ===

This confirms successful completion of the final prototype execution.

9. Final Testing Summary

The final system was evaluated using the testing activities performed in
Stage 5 and the final execution performed in Stage 6.

Feature	Result
Process Management	Passed
Process Scheduling	Passed
Multi-Core Execution	Passed
Resource Allocation	Passed
Resource Release	Passed
Process Re-Queue	Passed
Process Termination	Passed
End-to-End Simulation	Passed
10. Project Achievements

The project successfully achieved the following:

Developed a C++ based multi-core operating system simulator.
Implemented simulated process management.
Implemented scheduling of processes.
Implemented multi-core CPU execution.
Implemented resource allocation and release.
Implemented process re-queuing.
Implemented process termination.
Integrated the major components into a working prototype.
Tested the complete simulation.
Maintained project documentation and Git version control throughout
the development stages.
11. Known Limitation

During multi-core execution, console messages from different CPU threads
can occasionally appear interleaved.

For example, the final test contained an output similar to:

Priority: [Resource Manager] PID 3

This occurs because multiple execution threads can write to the console
at nearly the same time.

The underlying simulation continued successfully despite this output
formatting issue.

12. Possible Improvement

A future improvement is to introduce synchronized console logging.

A mutex-protected logging mechanism could ensure that each thread prints
its complete message without another thread interrupting the output.

This would improve:

Console readability
Debugging
Testing evidence
Monitoring of concurrent execution
13. Project Limitations

The current project is a simulator and does not operate as a real
operating system or real hardware-level CPU scheduler.

The CPU cores, processes, resources, and scheduling behavior are simulated
using C++ and software threads.

The current implementation also focuses on demonstrating the core concepts
rather than providing every feature of a production operating system.

14. Future Improvements

Possible future improvements include:

Additional scheduling algorithms.
More configurable CPU cores.
More advanced process states.
Dynamic resource management.
Improved synchronized logging.
Performance measurements.
Graphical monitoring of CPU and process activity.
Additional testing scenarios.
More detailed process statistics.
Improved user interaction and configuration.
15. Final Deliverables

The final project contains:

C++ source code
Header files
Makefile
Working simulator executable
Stage documentation
Architecture documentation
UML-style diagrams
Stage progress evidence
Git version control
GitHub repository
16. Git and Version Control

The project was maintained using Git throughout development.

The project includes separate documentation and evidence for each stage.

The completed stages are:

Stage 1 – Project Introduction
Stage 2 – Requirements & Development Plan
Stage 3 – System Design & Architecture
Stage 4 – Initial Implementation & Prototype
Stage 5 – Testing, Integration & Improvement
Stage 6 – Final Implementation & Presentation
17. Final Presentation Plan

The final presentation can demonstrate the project in the following order:

Introduce the SimOS project.
Explain the problem and project objective.
Explain the system architecture.
Show the main modules and class relationships.
Explain the scheduling and resource management flow.
Demonstrate the running simulator.
Show multi-core process execution.
Show resource allocation and release.
Show process re-queuing and termination.
Present testing results.
Explain achievements and limitations.
Discuss future improvements.
18. Final Demonstration

The final demonstration command is:

./sim_os

The expected successful completion message is:

=== SimOS Multi-Core Simulation Completed Successfully ===

This provides a simple demonstration that the integrated simulator can
execute the complete simulation successfully.

19. Final Project Status

The SimOS project has completed the six planned development stages:

Requirements
     |
     v
System Design
     |
     v
Implementation
     |
     v
Testing
     |
     v
Final Verification
     |
     v
Presentation

The final implementation demonstrates the integration of process
management, scheduling, multi-core execution, and resource management.

20. Conclusion

The SimOS – Multi-Core Operating System Simulator was successfully
developed through a structured six-stage software development process.

The project progressed from requirements and system design to
implementation, testing, integration, and final verification.

The final prototype successfully demonstrates multi-core process
execution, scheduling, resource management, process re-queuing, and
process termination.

The project also maintained documentation, evidence, and Git version
control throughout the development process.

The completed system provides a practical demonstration of operating
system concepts using Linux, C++, system programming, and software
thread-based simulation.

