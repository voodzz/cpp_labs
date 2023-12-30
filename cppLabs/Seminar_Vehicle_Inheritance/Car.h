#ifndef TASK_CAR_H
#define TASK_CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, int numberOfSeats = 0);
    ~Car() = default;
    void startTheEngine() const override;
    void turnTheEngineOff() const override;
    std::string toString() const override;
protected:
    int numberOfSeats_;
};


#endif //TASK_CAR_H
