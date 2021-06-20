//
// Created by Aljosha on 08.06.2021.
//


#include "Person.h"

namespace hfu {
    Person::Person(int id, const std::string &lastName, const std::string &firstName)
            : id(id), last_name(lastName), first_name(firstName) {}

    int Person::getId() const {
        return id;
    }

    const std::string &Person::getLastName() const {
        return last_name;
    }

    const std::string &Person::getFirstName() const {
        return first_name;
    }
}


