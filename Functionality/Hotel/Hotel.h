//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../Date/Date.h"
#include "../Rooms/Room.h"

class RoomLux;
class RoomStandard;

class Hotel {
public:
    Hotel();
    Hotel(const std::string& name);

    void loadFromFile(const std::string& file);
    Room* findAvailableRooms(const Date& dateStart, const Date& dateEnd, unsigned int capacity);
    void displayRoomsByClass(std::string roomClass);
    Room findBestRoomByPrice(const Date& dateStart, const Date& dateEnd, unsigned int capacity);
    void addReservation(Guest& guest, Room& room, const Date& dateStart, const Date& dateEnd, unsigned int capacity);
    void removeReservation(Guest& guest, Room& room);

    /*
     * Overload operators
     */

    // comparison of price
    bool operator<(const Hotel& other) const;
    bool operator>(const Hotel& other) const;
    bool operator>=(const Hotel& other) const;
    bool operator<=(const Hotel& other) const;
    bool operator==(const Hotel& other) const;
    bool operator!=(const Hotel& other) const;

    // overload operator =
    Hotel& operator=(const Hotel& other);

    // overload streams
    friend std::ostream& operator<<(std::ostream& os, const Hotel& hotel);
    friend std::ostream& operator>>(std::ostream& is, const Hotel& hotel);



    std::string name;
private:
    Room* rooms;
};


#endif //HOTEL_HOTEL_H