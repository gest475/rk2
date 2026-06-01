#pragma once
#include <iostream>
#include <string>

enum class Task {
    CustomerIssue, Programming, HardProgramming, MoneyIssue, M_And_A, ImpossibleTask
};

inline std::string GetNameOfTask(Task task) {
    switch (task) {
        case Task::CustomerIssue:   return "CustomerIssue";
        case Task::Programming:     return "Programming";
        case Task::HardProgramming: return "HardProgramming";
        case Task::MoneyIssue:      return "MoneyIssue";
        case Task::M_And_A:         return "M_And_A";
        case Task::ImpossibleTask:  return "ImpossibleTask";
        default: throw std::invalid_argument("");
    }
}

class Worker {
public:
    explicit Worker(Worker* successor) : successor_(successor) {}
    virtual ~Worker() = default;
    void Work(Task task) {
        if (WorkImpl_(task)) return;
        if (successor_) successor_->Work(task);
        else std::cout << "Fail to handle task. (" << GetNameOfTask(task) << ")" << std::endl;
    }
    Worker* ChangeSuccessor(Worker* successor) {
        Worker* old = successor_;
        successor_ = successor;
        return old;
    }
private:
    virtual bool WorkImpl_(Task task) = 0;
    Worker* successor_;
};

class CustomerSupporter : public Worker {
public:
    using Worker::Worker;
private:
    bool WorkImpl_(Task task) override {
        if (task == Task::CustomerIssue) {
            std::cout << "[CustomerSupporter] Resolve customer issue." << std::endl;
            return true;
        }
        return false;
    }
};

class SoftwareEngineer : public Worker {
public:
    using Worker::Worker;
    void Train() { isTrained_ = true; }
private:
    bool WorkImpl_(Task task) override {
        if (task == Task::Programming) {
            std::cout << "[SoftwareEngineer] Programming." << std::endl;
            return true;
        }
        if (task == Task::HardProgramming) {
            if (isTrained_) {
                std::cout << "[SoftwareEngineer] Successfully solve hard problem!" << std::endl;
                return true;
            } else {
                std::cout << "[SoftwareEngineer] Try to solve hard problem. But failed." << std::endl;
                return false;
            }
        }
        return false;
    }
    bool isTrained_{false};
};

class CEO : public Worker {
public:
    using Worker::Worker;
private:
    bool WorkImpl_(Task task) override {
        if (task == Task::MoneyIssue) {
            std::cout << "[CEO] Resolve money issue." << std::endl;
            return true;
        }
        if (task == Task::M_And_A) {
            std::cout << "[CEO] Do M&A." << std::endl;
            return true;
        }
        return false;
    }
};

class God : public Worker {
public:
    using Worker::Worker;
private:
    bool WorkImpl_(Task) override {
        std::cout << "[God] God can do anything!" << std::endl;
        return true;
    }
};
