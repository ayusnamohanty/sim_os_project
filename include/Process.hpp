#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>

enum class ProcessState {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {
private:
    int pid;
    std::string name;
    int burstTime;
    int remainingTime;
    int priority;
    ProcessState state;

public:
    Process(int id, std::string processName, int time, int prio);

    int getPid() const;
    std::string getName() const;
    int getBurstTime() const;
    int getRemainingTime() const;
    int getPriority() const;
    ProcessState getState() const;

    void setState(ProcessState newState);
    void reduceRemainingTime(int timeSlice);
    void printProcessInfo() const;
};

#endif
