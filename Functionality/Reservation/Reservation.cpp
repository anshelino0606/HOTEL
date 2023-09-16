//
// Created by Anhelina Modenko on 15.09.2023.
//

#include "Reservation.h"

Reservation::Reservation(Room* room, const Date &dateStart, const Date& dateEnd, const unsigned int& userID)
 : room(room), dateStart(dateStart), dateEnd(dateEnd), userID(userID) {

}


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

