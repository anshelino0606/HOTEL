//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "Hotel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void Hotel::loadFromFile(const std::string &filename)  {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open the CSV file: " + filename);
        }

        std::string line;
        std::getline(file, line); // Read and discard the header line if it exists

        // Reset the file to the beginning
        file.clear(); // Clear any flags that might affect file operation
        file.seekg(0, std::ios::beg);

        // Count the number of lines in the file to determine the array size
        int numLines = 0;
        while (std::getline(file, line)) {
            numLines++;
        }

        // Reset the file again to the beginning
        file.clear();
        file.seekg(0, std::ios::beg);

        // Allocate memory for the dynamic array of rooms
        rooms = std::vector<Room>(numLines - 1);

        int roomIndex = 0;

        // Read and parse the CSV data
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue; // Skip empty lines
            }

            if (line.back() == '\r') {
                line.pop_back(); // Remove carriage return character if present
            }

            if (line.substr(0, 5) == "Hotel") {
                name = line;
            } else {
                // Parse room information
                std::istringstream iss(line);
                std::string token;

                // Variables to store CSV values
                unsigned int noRooms, roomArea, maxCapacity;
                double pricePerNight;

                if (std::getline(iss, token, ' ')) {
                    noRooms = std::stoi(token);
                }

                if (std::getline(iss, token, ' ')) {
                    roomArea = std::stoi(token);
                }

                if (std::getline(iss, token, ' ')) {
                    maxCapacity = std::stoi(token);
                }

                if (std::getline(iss, token, ' ')) {
                    pricePerNight = std::stod(token);
                }

                Room room(noRooms, roomArea, maxCapacity, pricePerNight);

                while (std::getline(iss, token, ',')) {
                    // Skip leading spaces
                    size_t pos = token.find_first_not_of(' ');
                    if (pos != std::string::npos) {
                        token = token.substr(pos);
                    }

                    // Check if the token is not empty
                    if (!token.empty()) {
                        // Assuming reservations are in the format "YYYY-MM-DD"
                        // divide it into year, month and day
                        int year, month, day;
                        year = std::stoi(token.substr(0, 4));
                        month = std::stoi(token.substr(5, 2));
                        day = std::stoi(token.substr(8, 2));
                        Date date(year, month, day);
                        rooms[roomIndex].addReservation(new Reservation(&rooms[roomIndex], date, date, 0));
                    }
                }

                // Create a Room object and add it to the current hotel

                this->rooms.push_back(room);
                roomIndex++;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error loading room information from CSV file: " << e.what() << std::endl;
    }
}

Room* Hotel::findAvailableRooms(const Date& dateStart, const Date& dateEnd, unsigned int capacity) {
    Room *availableRooms = new Room[MAX_NUMBER];
    int numAvailableRooms = 0;

    for (int i = 0; i < MAX_NUMBER; i++) {
        if (rooms[i].isNumberAvailableAt(dateStart, dateEnd, capacity)) {
            availableRooms[numAvailableRooms] = rooms[i];
            numAvailableRooms++;
        }
    }

    return availableRooms;
}

void Hotel::displayRoomsByClass(std::string roomClass) {
    unsigned int count = 0;
    for (int i = 0; i < MAX_NUMBER; i++) {
        count++;
        if (rooms[i].getClass() == roomClass) {
            // Display room information (you can customize this part)
            std::cout << "Room Number: " << count << std::endl;
            std::cout << "Room Class: " << rooms[i].getClass() << std::endl;
//            std::cout << "Room Price: " << rooms[i].getPricePerNight() << std::endl;

            std::cout << std::endl;  // Add a separator between rooms
        }
    }
}

Room Hotel::findBestRoomByPrice(const Date &dateStart, const Date &dateEnd, unsigned int capacity) {
    Room bestRoom;
    for (int i = 0; i < MAX_NUMBER; i++) {
        if (rooms[i].isNumberAvailableAt(dateStart, dateEnd, capacity) && rooms[i] < bestRoom) {
            bestRoom = rooms[i];
        }
    }
    return bestRoom;
}

void Hotel::addReservation(Guest& guest, Room& room, const Date& dateStart, const Date& dateEnd, unsigned int capacity) {
    // Check if the room is available for the specified dates
    if (room.isNumberAvailableAt(dateStart, dateEnd, capacity)) {
        // Create a Reservation object and add it to the room
        Reservation* reservation = new Reservation(&room, dateStart, dateEnd, guest.getID());
        room.addReservation(reservation);
    } else {
        std::cout << "The room is not available for the specified dates." << std::endl;
    }
}

Hotel::Hotel(const std::string &name) {
    this->name = name;
}


std::ostream& operator<<(std::ostream& os, const Hotel& hotel) {
    os << "Hotel: " << hotel.name << std::endl;
    if (hotel.rooms == std::vector<Room>(0)) {
        os << "No rooms available." << std::endl;
        return os;
    }
    os << "Rooms: " << std::endl;
    for (int i = 0; i < MAX_NUMBER; i++) {
        os << hotel.rooms[i] << std::endl;
    }
}

std::istream& operator>>(std::istream& is, Hotel& hotel) {
    is >> hotel.name;
    for (int i = 0; i < MAX_NUMBER; i++) {
        is >> hotel.rooms[i];
    }
    return is;
}

bool Hotel::operator<(const Hotel& other) const {
    return name < other.name;
}

bool Hotel::operator>(const Hotel& other) const {
    return name > other.name;
}

bool Hotel::operator>=(const Hotel& other) const {
    return name >= other.name;
}

bool Hotel::operator<=(const Hotel& other) const {
    return name <= other.name;
}

bool Hotel::operator==(const Hotel& other) const {
    return name == other.name;
}

bool Hotel::operator!=(const Hotel& other) const {
    return name != other.name;
}

Hotel& Hotel::operator=(const Hotel& other) {
    if (this != &other) {
        name = other.name;
        rooms = other.rooms;
    }
    return *this;
}

Hotel::Hotel() {
    name = "";
    rooms = std::vector<Room>(0);
}

void Hotel::removeReservation(Guest &guest, Room &room) {
    // Check if room has reservations on this guest's name
    if (room.hasReservationAt(guest)) {
        // Remove the reservation
        room.removeReservationAt(&guest);
    } else {
        std::cout << "The room does not have any reservations on this guest's name." << std::endl;
    }
}

int Hotel::getNumberOfRooms() const {
    return sizeof(rooms);
}