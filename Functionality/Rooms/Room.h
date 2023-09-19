//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_ROOM_H
#define HOTEL_ROOM_H

#include "../Date/Date.h"
#include "../Reservation/Reservation.h"

static const unsigned int MAX_NUMBER = 100;

class Reservation;

class Room {

public:
    Room();

    Room(unsigned int noRooms,
        unsigned int roomArea,
        unsigned int maxCapacity,
        Reservation* reservations,
        unsigned int pricePerNight);

    Room(unsigned int noRooms,
         unsigned int roomArea,
         unsigned int maxCapacity,
         Reservation* reservations,
         unsigned int pricePerNight);

    Room(const Room& other);

    Room(Room&& other) noexcept;

    virtual void loadFromFile(const std::string& fileName);

    // is number available at certain date for certain amount of people
    virtual bool isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);
    virtual bool isNumberAvailableAt(const Date& dateStart, const Date& dateEnd, unsigned int number);

    // cost for range of dates
    virtual unsigned int calculateCost(const Date& dateStart, const Date& dateEnd);

    // number of days for booked room
    virtual unsigned int calculateNumberOfDays(const Date& dateStart, const Date& dateEnd);

    // add reservation
    virtual bool addReservation(Reservation* reservation);

    virtual std::string getClass();

    // comparison of price
    virtual bool operator<(const Room& other) const;
    virtual bool operator>(const Room& other) const;
    virtual bool operator>=(const Room& other) const;
    virtual bool operator<=(const Room& other) const;
    virtual bool operator==(const Room& other) const;
    virtual bool operator!=(const Room& other) const;

    // operators of streams
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
    friend std::istream& operator>>(std::istream& is, Room& room);

    // swap for move constructor
    friend void swap(Room& first, Room& second) noexcept;

    // getters:
    virtual unsigned int getNoRooms() const;
    virtual unsigned int getRoomArea() const;
    virtual unsigned int getMaxCapacity() const;
    virtual unsigned int getPricePerNight() const;

    virtual ~Room();

private:
    unsigned int noRooms;
    unsigned int roomArea;
    unsigned int maxCapacity;
    unsigned int pricePerNight;
    unsigned int numReservations;
    unsigned int roomNumber;
    Reservation* reservations;
};


#endif //HOTEL_ROOM_H
