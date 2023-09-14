//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_ROOM_H
#define HOTEL_ROOM_H

#include "Date.h"

class Room {

public:

    Room(unsigned int noRooms,
        unsigned int roomArea,
        unsigned int noAvailableRooms,
        Date* datesBooked,
        unsigned int pricePerNight);

    bool isNumberAvailableAt(const Date& dateStart, const Date& dateEnd);
    unsigned int calculateCost(const Date& dateStart, const Date& dateEnd);
    unsigned int calculateNumberOfDays(const Date& dateStart, const Date& dateEnd);

private:
    unsigned int noRooms;
    unsigned int roomArea;
    unsigned int noAvailableRooms;
    Date* datesBooked;
    unsigned int pricePerNight;
};


#endif //HOTEL_ROOM_H
