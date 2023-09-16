//
// Created by Anhelina Modenko on 15.09.2023.
//

#ifndef HOTEL_RESERVATION_H
#define HOTEL_RESERVATION_H

#include "../Rooms/Room.h"
#include "../Guest/Guest.h"

#include <string>

class Room;

class Reservation {
public:

    Reservation(Room* room, const Date& dateStart, const Date& dateEnd, const unsigned int& userID);

    static unsigned int costPerStay;

    const Room* getRoom() const;
    Date getDateStart() const;
    Date getDateEnd() const;
    unsigned int getGuestID() const;

    unsigned int getDurationInDays() const;

    // Check-in and check-out operations
//    void checkIn();
//    void checkOut();

    // Update reservation details (room or date)
    void updateReservation(Room* newRoom, const Date& newDateStart, const Date& newDateEnd);

    // Cancel the reservation
    void cancelReservation();

    // Generate a confirmation or receipt
//    std::string generateConfirmation() const;

    // Validate the reservation (e.g., check for conflicts with other reservations)
    bool isValid() const;

    // Export reservation data (e.g., to a file or email)
//    void exportData() const;

    /*
     * // Process payment for the reservation
     * void processPayment();

     * // Send notification to the guest
     * void sendNotification(const std::string& message);

     * // Leave a review or rating
     * void leaveReview(const std::string& review);

     */

private:
    Room* room;
    Date dateStart;
    Date dateEnd;
    unsigned int userID;
    bool isCheckedIn;
};


#endif //HOTEL_RESERVATION_H
