#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string regNumber;
    string color;

public:
    Vehicle(string reg, string col) : regNumber(reg), color(col) {}

    virtual void writeToFile(ofstream& file) {
        file << "Vehicle Details:\n";
        file << "Registration: " << regNumber << "\n";
        file << "Color: " << color << "\n";
    }
};

class Car : public Vehicle {
private:
    int numSeats;

public:
    Car(string reg, string col, int seats) : Vehicle(reg, col), numSeats(seats) {}

    void writeToFile(ofstream& file) override {
        Vehicle::writeToFile(file);
        file << "Type: Car\n";
        file << "Number of Seats: " << numSeats << "\n\n";
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(string reg, string col, int capacity) : Vehicle(reg, col), engineCapacity(capacity) {}

    void writeToFile(ofstream& file) override {
        Vehicle::writeToFile(file);
        file << "Type: Bike\n";
        file << "Engine Capacity: " << engineCapacity << "cc\n"<<endl;
    }
};

int main() {
    ofstream outFile("vehicles.txt");

    Car myCar("G4A", "White", 5);
    Bike myBike("64TH3", "Black", 150);

    myCar.writeToFile(outFile);
    myBike.writeToFile(outFile);

    outFile.close();
    cout << "Vehicle details written to file.\n";

    return 0;
}
