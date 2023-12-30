#ifndef TASK_TRUCK_H
#define TASK_TRUCK_H

#include "Vehicle.h"
#include <spdlog/spdlog.h>

class Truck : public Vehicle {
public:
    Truck(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = DIESEL, double loadCapacity = 0);
    ~Truck() = default;
    void startTheEngine() const override;
    void turnTheEngineOff() const override;
    std::string toString() const override;
protected:
    double loadCapacity_;
};


#endif //TASK_CAR_H
