//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_DATE_H
#define HOTEL_DATE_H

#include <string>

class Date {
public:
    // Default constructor
    Date();

    // Parameterized constructor
    Date(int year, int month, int day);

    // Copy constructor
    Date(const Date& other);

    // Move constructor
    Date(Date&& other) noexcept;

    // load from file
    void loadFromFile(const std::string& fileName);

    // Easily moving objects
    friend void swap(Date& first, Date& second) noexcept;

    // operator of copy
    Date& operator=(const Date& other);

    // operators of streams
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    friend std::istream& operator>>(std::istream& is, Date& date);


    // Destructor
    ~Date() = default;


    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

private:
    int year;
    int month;
    int day;
};






#endif //HOTEL_DATE_H
