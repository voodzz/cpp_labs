#ifndef TASK_ELECTRICCAR_H
#define TASK_ELECTRICCAR_H

#include "Car.h"
#include "ElectricVehicle.h"

class ElectricCar : public ElectricVehicle, public Car  {
public:
    ElectricCar(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC, double powerReserve = 0, int numberOfSeats = 0, bool autopilot = false);
    ~ElectricCar() = default;
    void startTheEngine() const override;
    void turnTheEngineOff() const override;
    std::string toString() const override;
protected:
    bool autopilot_;
};


#endif //TASK_CAR_H
