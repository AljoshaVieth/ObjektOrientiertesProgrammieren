//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>

namespace hfu {


#include "Person.h"

    Person::Person(const std::string &lastName, const std::string &firstName, const Date &birthdate) : last_name(
            check_last_name(lastName)), first_name(check_first_name(firstName)), birthdate(birthdate) {}

    Person::Person() : Person("-", "-", Date(1970, 1, 1)) {}

    std::string Person::check_last_name(const std::string &_last_name) const {
        if (_last_name.empty()) {
            throw std::invalid_argument("Last name cannot be empty");
        }
        return _last_name;
    }

    std::string Person::check_first_name(const std::string &_first_name) const {
        if (_first_name.empty()) {
            throw std::invalid_argument("First name cannot be empty");
        }
        return _first_name;
    }

    std::string Person::get_last_name() const {
        return last_name;
    }

    std::string Person::get_first_name() const {
        return first_name;
    }

    Date Person::get_born() const {
        return birthdate;
    }

    bool Person::compare(const Person &other) const {
        return last_name < other.get_last_name();
    }

    void Person::set_last_name(const std::string &_last_name) {
        last_name = _last_name;
    }

    void Person::set_born(const Date &_date) {
        birthdate = _date;
    }


}