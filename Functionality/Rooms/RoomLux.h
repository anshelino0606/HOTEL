//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_ROOMLUX_H
#define HOTEL_ROOMLUX_H

#include "Room.h"

enum class RegulatoryStandard {
    STANDARD,
    PREMIUM,
    ULTRA_PREMIUM
};

class RoomLux : public Room {
public:
    RoomLux(unsigned int noRooms,
                 unsigned int roomArea,
                 unsigned int maxCapacity,
                 Reservation* reservations,
                 unsigned int pricePerNight);


    // is number available at certain date for certain amount of people
    bool isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number) override;

    // cost for range of dates
    unsigned int calculateCost(const Date& dateStart, const Date& dateEnd) override;

    // number of days for booked room
    unsigned int calculateNumberOfDays(const Date& dateStart, const Date& dateEnd) override;

    // check for standard
    bool isCompliantWithStandard() const;

    // add reservation
    bool addReservation(Reservation* reservation) override;

    std::string getClass() override;

    // comparison of price
    bool operator<(const Room& other) const override;
    bool operator>(const Room& other) const override;
    bool operator>=(const Room& other) const override;
    bool operator<=(const Room& other) const override;
    bool operator==(const Room& other) const override;
    bool operator!=(const Room& other) const override;


private:
    unsigned int noRooms;
    unsigned int roomArea;
    unsigned int maxCapacity;
    unsigned int pricePerNight;
    RegulatoryStandard standard;
    Reservation* reservations;
};


#endif //HOTEL_ROOMLUX_H
