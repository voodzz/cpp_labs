#include <spdlog/spdlog.h>
#include "Truck.h"

Truck::Truck(int maxSpeed, double engineCapacity, EngineType engineType, double loadCapacity) :
    Vehicle(maxSpeed, engineCapacity, engineType), loadCapacity_(loadCapacity) {
    spdlog::debug("Truck constructor.");
};

void Truck::startTheEngine() const {
    spdlog::info("The engine has been started.");
}

void Truck::turnTheEngineOff() const {
    spdlog::info("The engine has been turned off.");
}

std::string Truck::toString() const {
    return Vehicle::toString() + ", The load capacity: "  + std::to_string(loadCapacity_) + "\n";
}
