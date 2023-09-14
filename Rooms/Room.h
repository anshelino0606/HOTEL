//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_ROOM_H
#define HOTEL_ROOM_H

#include "../Date/Date.h"

class Room {

public:

    Room(unsigned int noRooms,
        unsigned int roomArea,
        unsigned int maxCapacity,
        Date* datesBooked,
        unsigned int pricePerNight);


    // is number available at certain date for certain amount of people
    virtual bool isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);
    virtual bool isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number);

    // cost for range of dates
    virtual unsigned int calculateCost(const Date& dateStart, const Date& dateEnd);

    // number of days for booked room
    virtual unsigned int calculateNumberOfDays(const Date& dateStart, const Date& dateEnd);

    // comparison of price
    virtual bool operator<(const Room& other) const;
    virtual bool operator>(const Room& other) const;
    virtual bool operator>=(const Room& other) const;
    virtual bool operator<=(const Room& other) const;
    virtual bool operator==(const Room& other) const;
    virtual bool operator!=(const Room& other) const;


private:
    unsigned int noRooms;
    unsigned int roomArea;
    unsigned int maxCapacity;
    Date* datesBooked;
    unsigned int pricePerNight;
};


#endif //HOTEL_ROOM_H
