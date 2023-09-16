//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "RoomStandard.h"

RoomStandard::RoomStandard(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, Reservation* reservations,
                           unsigned int pricePerNight) : Room(1, roomArea, maxCapacity, reservations,
                                                              pricePerNight) {

}

bool RoomStandard::isNumberAvailableAt(const Date &dateStart, const Date &dateEnd, unsigned int number) {
    return Room::isNumberAvailableAt(dateStart, dateEnd, number);
}

unsigned int RoomStandard::calculateCost(const Date &dateStart, const Date &dateEnd) {
    unsigned int numDays = calculateNumberOfDays(dateStart, dateEnd);

    // Calculate the base cost without any adjustments
    unsigned int baseCost = numDays * pricePerNight;

    // Calculate the cost for amenities (1% per amenity)
    unsigned int amenityCost = amenities.size() * (baseCost / 100);

    // Adjust the base cost by adding the amenity cost
    return baseCost + amenityCost;
}

unsigned int RoomStandard::calculateNumberOfDays(const Date &dateStart, const Date &dateEnd) {
    return Room::calculateNumberOfDays(dateStart, dateEnd);
}

bool RoomStandard::operator<(const Room &other) const {
    return Room::operator<(other);
}

bool RoomStandard::operator>(const Room &other) const {
    return Room::operator>(other);
}

bool RoomStandard::operator>=(const Room &other) const {
    return Room::operator>=(other);
}

bool RoomStandard::operator<=(const Room &other) const {
    return Room::operator<=(other);
}

bool RoomStandard::operator==(const Room &other) const {
    return Room::operator==(other);
}

bool RoomStandard::operator!=(const Room &other) const {
    return Room::operator!=(other);
}

bool RoomStandard::addAmenity(const std::string &amenity) {
    // Check if the amenity already exists in the amenities list
    for (const std::string& existingAmenity : amenities) {
        if (existingAmenity == amenity) {
            return false; // Amenity already exists, can't add it again
        }
    }

    // If the amenity is not a duplicate, add it to the list
    amenities.push_back(amenity);
    return true; // Amenity added successfully
}

bool RoomStandard::addReservation(Reservation *reservation) {
    Room::addReservation(reservation);
}


