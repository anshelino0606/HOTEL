//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "Room.h"
#include <fstream>
#include <iostream>

Room::Room(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, Reservation *reservations,
           unsigned int pricePerNight)
           : noRooms(noRooms), roomArea(roomArea), pricePerNight(pricePerNight), maxCapacity(maxCapacity) {

    for (unsigned int i = 0; i < noRooms; ++i) {
        this->reservations[i] = reservations[i];
    }
}

bool Room::isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd) {
    // Compare year, month, and day of the dates to check if date is in range
    if (date.getYear() > rangeEnd.getYear() || date.getYear() < rangeStart.getYear())
        return false;

    if (date.getYear() == rangeEnd.getYear() && date.getMonth() > rangeEnd.getMonth())
        return false;

    if (date.getYear() == rangeStart.getYear() && date.getMonth() < rangeStart.getMonth())
        return false;

    if (date.getYear() == rangeEnd.getYear() && date.getMonth() == rangeEnd.getMonth() && date.getDay() > rangeEnd.getDay())
        return false;

    if (date.getYear() == rangeStart.getYear() && date.getMonth() == rangeStart.getMonth() && date.getDay() < rangeStart.getDay())
        return false;

    return true;
}


bool Room::isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number) {
    // Check if datesBooked is nullptr or no rooms are available
    if (noRooms == 0) {
        return false; // No rooms are available
    }

    // Check if the room can accommodate the specified number of people
    if (number > maxCapacity) {
        return false; // The room cannot accommodate the desired number of people
    }

    // Iterate through the booked dates
    for (unsigned int i = 0; i < noRooms; ++i) {
        // Get the start and end dates of the reservation
        const Date& reservationStartDate = reservations[i].getDateStart();
        const Date& reservationEndDate = reservations[i].getDateEnd();

        // Check if the reservation overlaps with the specified date range
        if (dateStart <= reservationEndDate && dateEnd >= reservationStartDate) {
            return false; // Room is not available for the specified dates
        }
    }

    return true; // Room is available for the specified dates and suitable for the desired number of people
}


unsigned int Room::calculateCost(const Date& dateStart, const Date& dateEnd) {
    // Calculate the number of days for the booking
    unsigned int numDays = calculateNumberOfDays(dateStart, dateEnd);

    // Calculate the base cost without discount
    unsigned int baseCost = numDays * pricePerNight;

    // Apply a 10% discount if the booking is longer than 10 days
    if (numDays > 10) {
        // Calculate the discount amount
        unsigned int discount = (baseCost * 10) / 100;

        // Subtract the discount from the base cost
        baseCost -= discount;
    }

    return baseCost;
}

unsigned int Room::calculateNumberOfDays(const Date& dateStart, const Date& dateEnd) {
    unsigned int totalDays = 0;
    for (const Reservation* reservation : this->reservations) {
        if (reservation) {
            // Calculate the duration of each reservation and add it to the total
            totalDays += reservation->getDurationInDays();
        }
    }
    return totalDays;
}


bool Room::operator<(const Room &other) const {
    return pricePerNight < other.pricePerNight;
}

bool Room::operator>(const Room &other) const {
    return pricePerNight > other.pricePerNight;
}

bool Room::operator<=(const Room &other) const {
    return pricePerNight <= other.pricePerNight;
}

bool Room::operator>=(const Room &other) const {
    return pricePerNight >= other.pricePerNight;
}

bool Room::operator==(const Room &other) const {
    return pricePerNight == other.pricePerNight;
}

bool Room::operator!=(const Room &other) const {
    return pricePerNight != other.pricePerNight;
}

bool Room::addReservation(Reservation *reservation) {
    if (numReservations < MAX_NUMBER) {
        // Check if the new reservation conflicts with existing reservations
        bool hasConflict = false;
        for (unsigned int i = 0; i < numReservations; ++i) {
            const Date& existingStart = reservations[i].getDateStart();
            const Date& existingEnd = reservations[i].getDateEnd();
            const Date& newStart = reservation->getDateStart();
            const Date& newEnd = reservation->getDateEnd();

            // Check for date range overlap
            if (newStart <= existingEnd && newEnd >= existingStart) {
                hasConflict = true;
                break; // There's a conflict; no need to check further
            }
        }

        if (!hasConflict) {
            reservations[numReservations++] = reservation;
        }
    }
}

std::string Room::getClass() {
    return "None";
}


Room::Room(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, Reservation *reservations,
           unsigned int pricePerNight)
        : noRooms(noRooms), roomArea(roomArea), pricePerNight(pricePerNight), maxCapacity(maxCapacity) {
    this->reservations = new Reservation[noRooms];
    for (unsigned int i = 0; i < noRooms; ++i) {
        this->reservations[i] = new Reservation();
    }
}

bool isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd) {
    // Compare year, month, and day of the dates to check if date is in range
    if (date.getYear() > rangeEnd.getYear() || date.getYear() < rangeStart.getYear())
        return false;

    if (date.getYear() == rangeEnd.getYear() && date.getMonth() > rangeEnd.getMonth())
        return false;

    if (date.getYear() == rangeStart.getYear() && date.getMonth() < rangeStart.getMonth())
        return false;

    if (date.getYear() == rangeEnd.getYear() && date.getMonth() == rangeEnd.getMonth() && date.getDay() > rangeEnd.getDay())
        return false;

    if (date.getYear() == rangeStart.getYear() && date.getMonth() == rangeStart.getMonth() && date.getDay() < rangeStart.getDay())
        return false;

    return true;
}




Room::Room(const Room &other)
        : noRooms(other.noRooms), roomArea(other.roomArea),
          maxCapacity(other.maxCapacity), pricePerNight(other.pricePerNight) {
    if (other.reservations != nullptr) {
        reservations = new Reservation[noRooms];
        std::copy(other.reservations, other.reservations + noRooms, reservations);
    }
}

Room::Room(Room&& other) noexcept : noRooms(0), roomArea(0), maxCapacity(0), reservations(nullptr), pricePerNight(0) {
    swap(*this, other);
}

void swap(Room &first, Room &second) noexcept {
    using std::swap;
    swap(first.noRooms, second.noRooms);
    swap(first.roomArea, second.roomArea);
    swap(first.maxCapacity, second.maxCapacity);
    swap(first.reservations, second.reservations);
    swap(first.pricePerNight, second.pricePerNight);

}

Room::~Room() {
    delete[] reservations;
}

Room::Room(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, unsigned int pricePerNight)
        : noRooms(noRooms), roomArea(roomArea), maxCapacity(maxCapacity), pricePerNight(pricePerNight), datesBooked(nullptr) {}

unsigned int Room::getNoRooms() const {
    return noRooms;
}

unsigned int Room::getRoomArea() const {
    return roomArea;
}


unsigned int Room::getMaxCapacity() const {
    return maxCapacity;
}

unsigned int Room::getPricePerNight() const {
    return pricePerNight;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
    os << "No. of Rooms: " << room.noRooms << "\n";
    os << "Room Area: " << room.roomArea << " sq. ft.\n";
    os << "Max Capacity: " << room.maxCapacity << " people\n";
    os << "Price per Night: $" << room.pricePerNight << "\n";
    os << "Dates Booked: ";
    for (unsigned int i = 0; i < room.noRooms; ++i) {
        os << room.reservations[i];
        if (i < room.noRooms - 1) {
            os << ", ";
        }
    }
    os << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Room &room) {
    // Read room properties from the input stream, e.g., noRooms, roomArea, maxCapacity, pricePerNight
    is >> room.noRooms >> room.roomArea >> room.maxCapacity >> room.pricePerNight;

    // Read datesBooked (assuming date format "YYYY-MM-DD, YYYY-MM-DD, ...")
    char comma;
    is >> comma; // Read the comma after pricePerNight
    room.reservations = new Reservation[room.noRooms];
    for (unsigned int i = 0; i < room.noRooms; ++i) {
        is >> room.reservations[i];
        if (i < room.noRooms - 1) {
            is >> comma;
        }
    }

    return is;
}

void Room::loadFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "FILE DID NOT OPEN: " << fileName << std::endl;
        return;
    }

    file >> *this;
}

Room::Room()
        : noRooms(0), roomArea(0), maxCapacity(0), reservations(nullptr), pricePerNight(0) {}
