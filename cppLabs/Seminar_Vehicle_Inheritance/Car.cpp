#include "Car.h"

Car::Car(int maxSpeed, double engineCapacity, EngineType engineType, int numberOfSeats) :
        Vehicle(maxSpeed, engineCapacity, engineType), numberOfSeats_(numberOfSeats) {
    spdlog::debug("Car constructor.");
};

void Car::startTheEngine() const {
    spdlog::info("The engine has been started.");
}

void Car::turnTheEngineOff() const {
    spdlog::info("The engine has been turned off.");
}

std::string Car::toString() const {
    return Vehicle::toString() + ", The number of seats: " + std::to_string(numberOfSeats_) + "\n";
}
