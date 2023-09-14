//
// Created by Anhelina Modenko on 14.09.2023.
//

#ifndef HOTEL_DATE_H
#define HOTEL_DATE_H


class Date {
public:
    Date(int year, int month, int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;


private:
    int year;
    int month;
    int day;
};


#endif //HOTEL_DATE_H
