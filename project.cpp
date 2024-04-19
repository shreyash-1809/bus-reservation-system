// bus.h
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
class Bus {
    string bus_number;
    string bus_driver;
    string bus_arrival;
    string bus_depart;
    string b_from;
    string b_to;
    string bus_seat[8][4];
 
public:
    void addNewBus();
    void makeReservation(Bus buses[], int busIndex);
    void clearSeats();
    void viewBusDetails();
    void showAvailableBuses(Bus buses[]);
    void showSeatAvailability(int busIndex);
    void displayLine(char ch);
};

// bus.cpp
#include "buss.h"
 
void Bus::addNewBus() {
    cout << "Enter Bus Number: ";
    cin >> bus_number;
 
    cout << "\nEnter Driver's Name: ";
    cin >> bus_driver;
 
    cout << "\nArrival Time: ";
    cin >> bus_arrival;
 
    cout << "\nDeparture Time: ";
    cin >> bus_depart;
 
    cout << "\nFrom: ";
    cin >> b_from;
 
    cout << "\nTo: ";
    cin >> b_to;
 
    clearSeats();
    cout << "\nNew Bus Added Successfully.\n";
}
 
void Bus::makeReservation(Bus buses[], int busIndex) {
    showSeatAvailability(busIndex);
 
    cout << "Enter Seat Number for Reservation: ";
    int seatNumber;
    cin >> seatNumber;
 
    if (seatNumber < 1 || seatNumber > 32) {
        cout << "Invalid seat number. Please enter a number between 1 and 32.\n";
        return;
    }
 
    int row = (seatNumber - 1) / 4;
    int col = (seatNumber - 1) % 4;
 
    if (buses[busIndex].bus_seat[row][col] == "Empty") {
        cout << "Enter Passenger's Name: ";
        cin >> buses[busIndex].bus_seat[row][col];
        cout << "Reservation Successful!\n";
    }
    else {
        cout << "The seat is already reserved. Please choose another seat.\n";
    }
}
 
void Bus::clearSeats() {
    for (int x = 0; x < 8; x++) {
        for (int z = 0; z < 4; z++) {
            bus_seat[x][z] = "Empty";
        }
    }
}
 
void Bus::viewBusDetails() {
    displayLine('*');
    cout << "Bus Number: \t" << bus_number
        << "\nDriver: \t" << bus_driver << "\t\tArrival Time: \t"
        << bus_arrival << "\tDeparture Time:" << bus_depart
        << "\nFrom: \t\t" << b_from << "\t\tTo: \t\t" << b_to << "\n";
    displayLine('*');
 
    showSeatAvailability(0);  // Display seat availability for this bus
}
 
void Bus::showAvailableBuses(Bus buses[]) {
    displayLine('*');
    cout << "Available Buses:\n";
    for (int i = 0; i < 5; i++) {
        if (!buses[i].bus_number.empty()) {
            cout << "Bus Number: " << buses[i].bus_number << "\tDriver: " << buses[i].bus_driver
                << "\tFrom: " << buses[i].b_from << "\tTo: " << buses[i].b_to << "\n";
        }
    }
    displayLine('_');
}
 
void Bus::showSeatAvailability(int busIndex) {
    cout << "Seat Availability:\n";
    int seatNumber = 1;
 
    for (int x = 0; x < 8; x++) {
        for (int z = 0; z < 4; z++) {
            cout << setw(5) << left << seatNumber << ".";
            cout << setw(10) << left << bus_seat[x][z];
            seatNumber++;
        }
        cout << "\n";
    }
 
    cout << "\nThere are " << (32 - seatNumber + 1) << " Seats Available in Bus Number: " << bus_number << "\n";
}
 
void Bus::displayLine(char ch) {
    for (int x = 80; x > 0; x--) {
        cout << ch;
    }
    cout << '\n';
}

// main.cpp
#include "buss.h"
 
int main() {
    const int MAX_BUSES = 5;
    Bus buses[MAX_BUSES];
 
    int choice;
 
    while (true) {
        cout << "\n\n";
        cout << "\t\t***SIMPLE BUS RESERVATION SYSTEM***";
        cout << "\n\n";
        cout << "\t\t\t1. Add New Bus\n\t\t\t"
            << "2. Make Reservation\n\t\t\t"
            << "3. View Reservation\n\t\t\t"
            << "4. Show Available Buses\n\t\t\t"
            << "5. Exit";
        cout << "\n\t\t\tEnter your Choice: ";
 
        cin >> choice;
 
        switch (choice) {
        case 1:
            buses[0].addNewBus();
            break;
 
        case 2:
            int busIndex;
            cout << "Enter Bus Index: ";
            cin >> busIndex;
            if (busIndex >= 0 && busIndex < MAX_BUSES) {
                buses[0].makeReservation(buses, busIndex);
            }
            else {
                cout << "Invalid Bus Index.\n";
            }
            break;
 
        case 3:
            buses[0].viewBusDetails();
            break;
 
        case 4:
            buses[0].showAvailableBuses(buses);
            break;
 
        case 5:
            cout << "Exiting the program. Thank you!\n";
            return 0;
 
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
 
    return 0;
}