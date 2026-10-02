#include "Process.hpp"
#include <iostream>

Process::Process(int id, std::string processName, int time, int prio)
    : pid(id), name(processName), burstTime(time), remainingTime(time), priority(prio), state(ProcessState::READY) {}

int Process::getPid() const { return pid; }
std::string Process::getName() const { return name; }
int Process::getBurstTime() const { return burstTime; }
int Process::getRemainingTime() const { return remainingTime; }
int Process::getPriority() const { return priority; }
ProcessState Process::getState() const { return state; }

void Process::setState(ProcessState newState) {
    state = newState;
}

void Process::reduceRemainingTime(int timeSlice) {
    if (remainingTime > timeSlice) {
        remainingTime -= timeSlice;
    } else {
        remainingTime = 0;
        state = ProcessState::TERMINATED;
    }
}

void Process::printProcessInfo() const {
    std::cout << "[Process] ID: " << pid 
              << " | Name: " << name 
              << " | Remaining Time: " << remainingTime 
              << " | Priority: " << priority << "\n";
}
