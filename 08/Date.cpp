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
    Date::Date(int year, int month, int day) : year(year_is_valid(year)), month(month_is_valid(month)), day(day_is_valid(year, month,day)) {}


    int Date::year_is_valid(const int &_year) const {
        if (_year < 0){
            throw std::invalid_argument("Year must be positive");
        }
        return _year;
    }

    int Date::month_is_valid(const int &_month) const {
        if (_month < 0 || _month > 12) {
            throw std::invalid_argument("Month has to be between 1 and 12");
        }
        return _month;
    }

    int Date::day_is_valid(const int &_year, const int &_month, const int &_day) const {
        bool is_valid = true;
        int number_of_days_in_february = 28;
        switch (_month) {
            case 4:
            case 6:
            case 9:
            case 11:
                is_valid =  30 >= _day;
                break;
            case 2:
                if (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0)) {
                    number_of_days_in_february = 29;
                }
                is_valid= _day <= number_of_days_in_february;
                break;
            default:
                is_valid =  31 >= _day;
                break;
        }
        if(!is_valid){
            throw std::invalid_argument("This day does not exist");
        }
        return _day;
    }

    void Date::setYear(const int _year) {
        year = _year;
    }


    bool Date::operator==(const Date &other) const {
        return (this->year == other.get_year() && this->month == other.get_month() && this->day == other.get_day());
    }





}

