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

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

bool Date::operator<=(const Date& other) const {
    return !(other < *this);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}