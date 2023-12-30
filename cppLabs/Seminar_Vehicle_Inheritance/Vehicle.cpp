#include <vector>
#include <spdlog/spdlog.h>
#include "Vehicle.h"

std::string boolToString(bool b) {
    return b ? "true" : "false";
}

Vehicle::Vehicle(int maxSpeed, double engineCapacity, EngineType engineType) : maxSpeed_(maxSpeed),
                                                                               engineCapacity_(engineCapacity),
                                                                               engineType_(engineType) {
    spdlog::debug("Vehicle constructor.");
};

void Vehicle::setMaxSpeed(const int& value) {
    maxSpeed_ = value;
}

void Vehicle::setEngineCapacity(const double& value) {
    engineCapacity_ = value;
}

void Vehicle::setEngineType(const EngineType& value) {
    engineType_ = value;
}

std::string engineTypeToString(EngineType engineType) {
    std::vector<std::string> names{"PETROL", "DIESEL", "GAS", "ELECTRIC"};
    return names[engineType];
}

std::string Vehicle::toString() const {
    return "Max speed: " + std::to_string(maxSpeed_) + "km/h, Engine capacity: " +
           std::to_string(engineCapacity_) + " liters, Engine type: " +
           ::engineTypeToString(engineType_);
}

