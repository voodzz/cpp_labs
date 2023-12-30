#include <spdlog/spdlog.h>
#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(int maxSpeed, double engineCapacity, EngineType engineType, double powerReserve) :
    Vehicle(maxSpeed, engineCapacity, engineType), powerReserve_(powerReserve) {
    spdlog::debug("Electric Vehicle constructor.");
};

void ElectricVehicle::setPowerReserve(const double& value) {
    powerReserve_ = value;
};

std::string ElectricVehicle ::toString() const {
    return Vehicle::toString() + ", The power reserve: " + std::to_string(powerReserve_);
}

