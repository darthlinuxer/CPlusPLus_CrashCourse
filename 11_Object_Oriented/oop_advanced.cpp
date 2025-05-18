#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers

// Base class: Vehicle
class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string &brand, int year) : brand(brand), year(year) {}

    // Virtual function to demonstrate polymorphism
    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    virtual ~Vehicle() = default;
};

// Derived class: Car
class Car : public Vehicle {
    int numberOfDoors;

public:
    Car(const std::string &brand, int year, int numberOfDoors)
        : Vehicle(brand, year), numberOfDoors(numberOfDoors) {}

    void displayInfo() const override {
        std::cout << "Car - Brand: " << brand << ", Year: " << year
                  << ", Doors: " << numberOfDoors << std::endl;
    }
};

// Derived class: Motorcycle
class Motorcycle : public Vehicle {
    bool hasSidecar;

public:
    Motorcycle(const std::string &brand, int year, bool hasSidecar)
        : Vehicle(brand, year), hasSidecar(hasSidecar) {}

    void displayInfo() const override {
        std::cout << "Motorcycle - Brand: " << brand << ", Year: " << year
                  << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

// Demonstrating encapsulation with a class
class Garage {
    std::vector<Vehicle *> vehicles; // Encapsulated data

public:
    void addVehicle(Vehicle *vehicle) {
        vehicles.push_back(vehicle);
    }

    void showVehicles() const {
        for (const auto &vehicle : vehicles) {
            vehicle->displayInfo();
        }
    }

    ~Garage() {
        for (auto &vehicle : vehicles) {
            delete vehicle; // Clean up dynamically allocated memory
        }
    }
};

int main() {
    Garage garage;

    // Adding vehicles to the garage using raw pointers (existing code)
    garage.addVehicle(new Car("Toyota", 2020, 4));
    garage.addVehicle(new Motorcycle("Harley-Davidson", 2018, true));

    // Displaying all vehicles in the garage
    garage.showVehicles();

    // Modern way: Using smart pointers
    std::vector<std::unique_ptr<Vehicle>> smartGarage;
    smartGarage.push_back(std::make_unique<Car>("Smart Toyota", 2021, 4));
    smartGarage.push_back(std::make_unique<Motorcycle>("Smart Harley-Davidson", 2019, false));

    for (const auto &vehicle : smartGarage) {
        vehicle->displayInfo();
    }

    return 0;
}

/*
Output:
Car - Brand: Toyota, Year: 2020, Doors: 4
Motorcycle - Brand: Harley-Davidson, Year: 2018, Sidecar: Yes
Smart Car - Brand: Smart Toyota, Year: 2021, Doors: 4
Smart Motorcycle - Brand: Smart Harley-Davidson, Year: 2019, Sidecar: No
*/