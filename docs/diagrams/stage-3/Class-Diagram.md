# SimOS – Class Diagram

## Class Diagram

```text
+---------------------------+
|          Process          |
+---------------------------+
| - processId               |
| - name                    |
| - priority                |
| - executionTime           |
| - remainingTime           |
| - state                   |
+---------------------------+
| + execute()               |
| + isCompleted()           |
| + getState()              |
+-------------+-------------+
              |
              |
              v
+---------------------------+
|         Scheduler         |
+---------------------------+
| - readyQueue              |
+---------------------------+
| + addProcess()            |
| + getNextProcess()        |
| + schedule()              |
+-------------+-------------+
              |
              |
              v
+---------------------------+
|      ResourceManager      |
+---------------------------+
| - availableResources     |
| - allocatedResources     |
+---------------------------+
| + allocateResource()      |
| + releaseResource()       |
| + isAvailable()           |
+---------------------------+

              ^
              |
+-------------+-------------+
|            Main           |
+---------------------------+
| + main()                  |
| + startSimulation()       |
+---------------------------+
Class Responsibilities
Process

Represents a simulated process and stores its execution-related information.

Scheduler

Maintains the ready queue and selects processes for execution.

ResourceManager

Manages the availability, allocation, and release of shared resources.

Main

Acts as the entry point and coordinates the overall simulation.

Class Relationships
-Main coordinates the Scheduler.
-Main coordinates the ResourceManager.
-Scheduler manages Process objects.
-ResourceManager manages resources required by processes.
