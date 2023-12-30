#ifndef TASK_VEHICLE_H
#define TASK_VEHICLE_H

#include <string>
#include <spdlog/spdlog.h>

std::string boolToString(bool b);

enum EngineType {
    PETROL = 0,
    DIESEL,
    GAS,
    ELECTRIC
};

std::string engineTypeToString(EngineType engineType);

class Vehicle {
public:
    Vehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL);
    ~Vehicle() = default;
    Vehicle(const Vehicle& other) = default;
    Vehicle& operator=(const Vehicle& other) = default;
    Vehicle(Vehicle&& other) = default;
    Vehicle& operator=(Vehicle&& other) = default;

    virtual void setMaxSpeed(const int& value);
    virtual void setEngineCapacity(const double& value);
    virtual void setEngineType(const EngineType& value);
    virtual std::string toString() const;
    virtual void startTheEngine() const = 0;
    virtual void turnTheEngineOff() const = 0;
protected:
    int maxSpeed_;
    double engineCapacity_;
    EngineType engineType_;
};


#endif //TASK_VEHICLE_H
