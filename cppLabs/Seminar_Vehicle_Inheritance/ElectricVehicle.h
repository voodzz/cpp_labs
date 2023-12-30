#ifndef TASK_ELECTRICVEHICLE_H
#define TASK_ELECTRICVEHICLE_H

#include "Vehicle.h"

class ElectricVehicle : public Vehicle {
public:
    ElectricVehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC,
                    double powerReserve = 0);
    ~ElectricVehicle() = default;

    virtual void setPowerReserve(const double& value);
    std::string toString() const override;
protected:
    double powerReserve_;

};


#endif //TASK_ELECTRICVEHICLE_H
