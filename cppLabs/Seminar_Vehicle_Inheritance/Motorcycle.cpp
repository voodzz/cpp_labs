#include <spdlog/spdlog.h>
#include "Motorcycle.h"


Motorcycle::Motorcycle(int maxSpeed, double engineCapacity, EngineType engineType, bool protectiveBars) :
    Vehicle(maxSpeed, engineCapacity, engineType), protectiveBars_(protectiveBars) {
    spdlog::debug("Motorcycle constructor.");
};

void Motorcycle::startTheEngine() const {
    spdlog::info("The engine has been started.");
}

void Motorcycle::turnTheEngineOff() const {
    spdlog::info("The engine has been turned off.");
}

std::string Motorcycle::toString() const {
    return Vehicle::toString() + ", The protective bar: " + boolToString(protectiveBars_) + "\n";
}
