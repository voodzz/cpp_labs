#include "ElectricCar.h"


ElectricCar::ElectricCar(int maxSpeed, double engineCapacity, EngineType engineType, double powerReserve, int numberOfSeats, bool autopilot) :
    ElectricVehicle(maxSpeed, engineCapacity, engineType, powerReserve), Car(numberOfSeats), autopilot_(autopilot) {
    spdlog::debug("Electric Car constructor.");
}

void ElectricCar::startTheEngine() const {
    spdlog::info("The engine has been started.");
}

void ElectricCar::turnTheEngineOff() const {
    spdlog::info("The engine has been turned off.");
}

std::string ElectricCar::toString() const {
    return ElectricVehicle::toString() + ", Autopilot is: " + boolToString(autopilot_) + "\n";
}


