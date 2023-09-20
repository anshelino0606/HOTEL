//
// Created by Anhelina Modenko on 15.09.2023.
//

#include "Reservation.h"
#include <fstream>
//Reservation::Reservation(Room* room, const Date &dateStart, const Date& dateEnd, const unsigned int& userID)
// : room(room), dateStart(dateStart), dateEnd(dateEnd), userID(userID) {
//
//}


const Room* Reservation::getRoom() const {
    return room;
}

unsigned int Reservation::getGuestID() const {
    return userID;
}


unsigned int Reservation::getDurationInDays() const {
    unsigned int numDays = (dateEnd.getYear() - dateStart.getYear()) * 365 +
                           (dateEnd.getMonth() - dateStart.getMonth()) * 30 +
                           (dateEnd.getDay() - dateStart.getDay());

    return numDays;
}

void Reservation::updateReservation(Room *newRoom, const Date &newDateStart, const Date &newDateEnd) {
    room = newRoom;
    dateEnd = newDateEnd;
    dateStart = newDateStart;
}

void Reservation::cancelReservation() {
    this->room = nullptr;
}

bool Reservation::isValid() const {
    return false;
}

Date Reservation::getDateStart() const {
    return dateStart;
}

Date Reservation::getDateEnd() const {
    return dateEnd;
}

Reservation::Reservation()
        : room(nullptr), dateStart(Date(0, 0, 0)), dateEnd(Date(0, 0, 0)), userID(0), isCheckedIn(false),
            cost(0), numGuests(0), confirmationCode(""), specialRequests("") {}

Reservation::Reservation(Room *room, const Date &dateStart, const Date &dateEnd, unsigned int userID)
        : room(room), dateStart(dateStart), dateEnd(dateEnd), userID(userID), isCheckedIn(false),
          cost(0), numGuests(0), confirmationCode(""), specialRequests("") {}

Reservation::Reservation(Room *room, const Date &dateStart, const Date &dateEnd, unsigned int userID, bool isCheckedIn,
                         unsigned int cost, unsigned int numGuests, const std::string &confirmationCode,
                         const std::string &specialRequests)
        : room(room), dateStart(dateStart), dateEnd(dateEnd), userID(userID), isCheckedIn(isCheckedIn),
          cost(cost), numGuests(numGuests), confirmationCode(confirmationCode),
          specialRequests(specialRequests) {}

Reservation::Reservation(const Reservation &other) {
    this->room = other.room;
    this->dateStart = other.dateStart;
    this->dateEnd = other.dateEnd;
    this->userID = other.userID;
    this->isCheckedIn = other.isCheckedIn;
    this->cost = other.cost;
    this->numGuests = other.numGuests;
    this->confirmationCode = other.confirmationCode;
    this->specialRequests = other.specialRequests;
}

Reservation &Reservation::operator=(const Reservation &other) {
    if (this == &other) {
        return *this;
    }

    // Perform deep copy of Reservation members
    this->room = other.room;
    this->dateStart = other.dateStart;
    this->dateEnd = other.dateEnd;
    this->userID = other.userID;
    this->isCheckedIn = other.isCheckedIn;
    this->cost = other.cost;
    this->numGuests = other.numGuests;
    this->confirmationCode = other.confirmationCode;
    this->specialRequests = other.specialRequests;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Reservation &reservation) {
    os << "Room: " << reservation.room->getRoomNumber() << "\n";
    os << "Start Date: " << reservation.getDateStart() << "\n";
    os << "End Date: " << reservation.getDateEnd() << "\n";
    os << "User ID: " << reservation.getGuestID() << "\n";
    os << "Checked In: " << (reservation.isCheckedIn ? std::string("Yes") : std::string("No")) << "\n";
    os << "Cost: $" << reservation.room->getPricePerNight() << "\n";
    os << "Number of Guests: " << reservation.numGuests << "\n";
    os << "Confirmation Code: " << reservation.confirmationCode << "\n";
    os << "Special Requests: " << reservation.specialRequests << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Reservation &reservation) {
    return is;
}

