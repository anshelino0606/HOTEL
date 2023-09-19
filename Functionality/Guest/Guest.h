//
// Created by Anhelina Modenko on 15.09.2023.
//

#ifndef HOTEL_GUEST_H
#define HOTEL_GUEST_H

#include <string>

class Guest {

private:
    int ID;
    std::string name;

public:
    Guest();
    Guest(std::string name, int ID);

    int getID() const;

};


#endif //HOTEL_GUEST_H
