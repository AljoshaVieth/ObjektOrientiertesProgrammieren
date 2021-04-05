//
// Created by Aljosha on 30.03.2021.
//
#include <iostream>

namespace hfu {

#include "Date.h"


    int Date::get_day() const {
        return day;
    }

    int Date::get_year() const {
        return year;
    }

    int Date::get_month() const {
        return month;
    }

    void Date::init(const int _year, const int _month, const int _day) {
        date_is_valid(_year, _month, _day);
        this->year = _year;
        this->month = _month;
        this->day = _day;
    }

    void Date::date_is_valid(const int &_year, const int &_month, const int &_day) const {
        if (!year_is_valid(_year)) {
            throw std::invalid_argument("Year must be positive");
        }
        if (!month_is_valid(_month)) {
            throw std::invalid_argument("Month has to be between 1 and 12");
        }
        if (!day_is_valid(_year, _month, _day)) {
            throw std::invalid_argument("This day does not exist");
        }
    }

    bool Date::year_is_valid(const int &_year) const {
        return 0 <= _year;
    }

    bool Date::month_is_valid(const int &_month) const {
        return 0 < _month && 12 >= _month;
    }

    bool Date::day_is_valid(const int &_year, const int &_month, const int &_day) const {
        int number_of_days_in_february = 28;
        switch (_month) {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30 >= _day;
            case 2:
                if (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0)) {
                    number_of_days_in_february = 29;
                }
                return _day <= number_of_days_in_february;
            default:
                return 31 >= _day;
        }
    }


}


