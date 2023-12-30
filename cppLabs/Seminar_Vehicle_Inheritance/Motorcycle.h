#ifndef TASK_MOTORCYCLE_H
#define TASK_MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, bool protectiveBars = false);
    ~Motorcycle() = default;
    void startTheEngine() const override;
    void turnTheEngineOff() const override;
    std::string toString() const override;
protected:
    bool protectiveBars_;
};


#endif //TASK_CAR_H
