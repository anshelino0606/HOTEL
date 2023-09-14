//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "Room.h"

Room::Room(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, Date *datesBooked,
           unsigned int pricePerNight)
           : noRooms(noRooms), roomArea(roomArea), pricePerNight(pricePerNight), datesBooked(nullptr), maxCapacity(maxCapacity) {

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


bool Room::isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number) {
    // Check if datesBooked is nullptr or no rooms are available
    if (!datesBooked || noRooms == 0) {
        return false; // No rooms are available
    }

    // Check if the room can accommodate the specified number of people
    if (number > maxCapacity) {
        return false; // The room cannot accommodate the desired number of people
    }

    // Iterate through the booked dates
    for (unsigned int i = 0; i < noRooms; ++i) {
        // Check if the booked date falls within the specified date range
        if (isDateInRange(datesBooked[i], dateStart, dateEnd)) {
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
    unsigned int numDays = (dateEnd.getYear() - dateStart.getYear()) * 365 +
                           (dateEnd.getMonth() - dateStart.getMonth()) * 30 +
                           (dateEnd.getDay() - dateStart.getDay());

    return numDays;
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


