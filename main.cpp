#include <iostream>

#include "Functionality/Hotel/Hotel.h"
#include "Functionality/LinkedList/DoubleLinkedList.hpp"
#include "Functionality/Guest/Guest.h"
#include "Functionality/Rooms/Room.h"

int main() {
    //
    DoubleLinkedList<Hotel> hotels;

    Hotel hotel1("Rixos Luxury Resort&SPA");
    Hotel hotel2("Steinberger Hotel");
    Hotel hotel3("Hilton Hotel");

    hotels.pushBack(hotel1);
    hotels.pushBack(hotel2);
    hotels.pushBack(hotel3);


    Node<Hotel>* current = hotels.head;
    while (current != nullptr) {
        std::cout << "Hotel Name: " << current->data.name << std::endl;
        current = current->next;
    }
    hotels.sort();

    std::cout << "After sorting: " << std::endl;
    current = hotels.head;
    while (current != nullptr) {
        std::cout << "Hotel Name: " << current->data.name << std::endl;
        current = current->next;
    }

    return 0;
}
