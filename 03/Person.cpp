//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
namespace hfu {


#include "Person.h"

    void Person::init(const std::string &_last_name, const std::string &_first_name, const Date &_birthdate) {
        if(_last_name.empty()){
            throw std::invalid_argument("Last name cannot be empty");
        }
        if(_first_name.empty()){
            throw std::invalid_argument("First name cannot be empty");
        }
        this->last_name = _last_name;
        this->first_name = _first_name;
        this->birthdate = _birthdate;
    }

    const std::string &Person::get_last_name() const {
        return last_name;
    }

    const std::string &Person::get_first_name() const {
        return first_name;
    }

    const Date &Person::get_born() const {
        return birthdate;
    }

    bool Person::compare(const Person &other) const {
        return last_name < other.get_last_name();
    }

}
