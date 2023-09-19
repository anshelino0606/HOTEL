//
// Created by Anhelina Modenko on 15.09.2023.
//

#include "Guest.h"

int Guest::getID() const {
    return this->ID;
}

Guest::Guest()
    : name(" "), ID(0) {}


Guest::Guest(std::string name, int ID) : name(name), ID(ID) {}