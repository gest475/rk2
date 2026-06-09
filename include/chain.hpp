#pragma once
#include <iostream>
#include <string>

enum class Task {
    CustomerIssue,
    Programming,
    HardProgramming,
    MoneyIssue,
    ImpossibleTask
};

class Employee {
protected:
    Employee* nextHandler;
public:
    Employee(Employee* next) : nextHandler(next) {}
    virtual ~Employee() = default;
    virtual void Work(Task task) = 0;
};

class CEO : public Employee {
public:
    CEO(Employee* next) : Employee(next) {}
    void Work(Task task) override {
        if (task == Task::MoneyIssue) {
            std::cout << "[CEO] Resolve money issue." << std::endl;
        } else if (nextHandler) {
            nextHandler->Work(task);
        }
    }
};

class SoftwareEngineer : public Employee {
private:
    bool trained = false;
public:
    SoftwareEngineer(Employee* next) : Employee(next) {}
    void Train() { trained = true; }
    void Work(Task task) override {
        if (task == Task::Programming) {
            std::cout << "[SoftwareEngineer] Programming." << std::endl;
        } else if (task == Task::HardProgramming && trained) {
            std::cout << "Successfully solve" << std::endl;
        } else if (nextHandler) {
            nextHandler->Work(task);
        }
    }
};

class CustomerSupporter : public Employee {
public:
    CustomerSupporter(Employee* next) : Employee(next) {}
    void Work(Task task) override {
        if (task == Task::CustomerIssue) {
            std::cout << "[CustomerSupporter] Resolve customer issue." << std::endl;
        } else if (nextHandler) {
            nextHandler->Work(task);
        }
    }
};

class God : public Employee {
public:
    God(Employee* next) : Employee(next) {}
    void Work(Task task) override {
        std::cout << "[God] God can do anything!" << std::endl;
    }
};
