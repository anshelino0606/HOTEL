//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "RoomLux.h"

RoomLux::RoomLux(unsigned int noRooms, unsigned int roomArea, unsigned int maxCapacity, Reservation *reservations,
                           unsigned int pricePerNight) : Room(noRooms, roomArea, maxCapacity, reservations,
                                                              pricePerNight) {

}

bool RoomLux::isNumberAvailableAt(const Date &dateStart, const Date &dateEnd, unsigned int number) {
    return Room::isNumberAvailableAt(dateStart, dateEnd, number);
}

unsigned int RoomLux::calculateCost(const Date &dateStart, const Date &dateEnd) {
    unsigned int numDays = calculateNumberOfDays(dateStart, dateEnd);

    unsigned int baseCost = numDays * (pricePerNight * 2); // Cost is twice per area for Lux

    if (noRooms > 1) {
        baseCost += (noRooms - 1) * 50; // Adjust per additional room
    }

    return baseCost;
}

unsigned int RoomLux::calculateNumberOfDays(const Date &dateStart, const Date &dateEnd) {
    return Room::calculateNumberOfDays(dateStart, dateEnd);
}

bool RoomLux::operator<(const Room &other) const {
    return Room::operator<(other);
}

bool RoomLux::operator>(const Room &other) const {
    return Room::operator>(other);
}

bool RoomLux::operator>=(const Room &other) const {
    return Room::operator>=(other);
}

bool RoomLux::operator<=(const Room &other) const {
    return Room::operator<=(other);
}

bool RoomLux::operator==(const Room &other) const {
    return Room::operator==(other);
}

bool RoomLux::operator!=(const Room &other) const {
    return Room::operator!=(other);
}

bool RoomLux::isCompliantWithStandard() const {
    switch (this->standard) {
        case RegulatoryStandard::STANDARD:
            return roomArea >= 30; // Example: Standard Lux rooms must have at least 30 sq. meters
        case RegulatoryStandard::PREMIUM:
            return roomArea >= 40; // Example: Premium Lux rooms must have at least 40 sq. meters
        case RegulatoryStandard::ULTRA_PREMIUM:
            return roomArea >= 50; // Example: Ultra-Premium Lux rooms must have at least 50 sq. meters
        default:
            return false; // Unknown standard, not compliant
    }
}

bool RoomLux::addReservation(Reservation *reservation) {
    Room::addReservation(reservation);
}

std::string RoomLux::getClass() {
    return "Lux";
}

RoomLux::RoomLux()
    : Room() {}
