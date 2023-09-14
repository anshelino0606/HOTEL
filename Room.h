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
        unsigned int maxCapacity,
        Date* datesBooked,
        unsigned int pricePerNight);


    // is number available at certain date for certain amount of people
    bool isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number);

    // cost for range of dates
    unsigned int calculateCost(const Date& dateStart, const Date& dateEnd);

    // number of days for booked room
    unsigned int calculateNumberOfDays(const Date& dateStart, const Date& dateEnd);

    // comparison of price
    bool operator<(const Room& other) const;
    bool operator>(const Room& other) const;
    bool operator>=(const Room& other) const;
    bool operator<=(const Room& other) const;
    bool operator==(const Room& other) const;
    bool operator!=(const Room& other) const;


private:
    unsigned int noRooms;
    unsigned int roomArea;
    unsigned int maxCapacity;
    Date* datesBooked;
    unsigned int pricePerNight;
};


#endif //HOTEL_ROOM_H
