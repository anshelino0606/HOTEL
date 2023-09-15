//
// Created by Anhelina Modenko on 14.09.2023.
//

#include "Date.h"

Date::Date(int year, int month, int day)
        : year(year), month(month), day(day) {}

int Date::getYear() const {
    return this->year;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getDay() const {
    return this->day;
}