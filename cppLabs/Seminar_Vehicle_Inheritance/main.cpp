#include <iostream>
#include <spdlog/spdlog.h>
#include "Car.h"
#include "ElectricCar.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Vehicle.h"

int main() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("Application started.");
    Car Toyota(100, 5, PETROL, 4);
    Motorcycle Suzuki(200, 1.25, PETROL, true);
    Truck DAF(80, 8, DIESEL, 40);
    ElectricCar Tesla(100, 0, ELECTRIC, 200, 4, true);
    Toyota.startTheEngine();
    Suzuki.startTheEngine();
    DAF.startTheEngine();
    std::cout << Suzuki.toString();
    std::cout << DAF.toString();
    std::cout << Toyota.toString();
    std::cout << Tesla.toString();
    spdlog::info("Application finished.");
    return 0;
}
