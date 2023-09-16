//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_ROOMSTANDARD_H
#define HOTEL_ROOMSTANDARD_H

#include "Room.h"
#include <vector>
#include <string>

class RoomStandard : public Room {
public:
    RoomStandard(unsigned int noRooms,
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

    // add comfortability
    bool addAmenity(const std::string& amenity);

    // add reservation
    bool addReservation(Reservation* reservation) override;

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
    std::vector<std::string> amenities;
    Reservation* reservations;
};


#endif //HOTEL_ROOMSTANDARD_H
