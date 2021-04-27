//
// Created by Aljosha on 30.03.2021.
//

#ifndef OOP_DATE_H
#define OOP_DATE_H


class Date {
private:
    int year, month, day;

    int year_is_valid(const int &_year) const;

    int month_is_valid(const int &_month) const;

    int day_is_valid(const int &_year, const int &_month, const int &_day) const;

public:
    Date(const int year, const int month, const int day);

    int get_year() const;

    int get_month() const;

    int get_day() const;

    void setYear(const int _year); //just to test copy

};


#endif //OOP_DATE_H

