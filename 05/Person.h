//
// Created by Aljosha on 03.04.2021.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H

#include <string>
#include "Date.h"

class Person {
private:
    std::string last_name, first_name;
    Date birthdate;

    std::string check_last_name(const std::string &_last_name) const;

    std::string check_first_name(const std::string &_first_name) const;

public:
    Person(const std::string &lastName, const std::string &firstName, const Date &birthdate);

    Person();

    std::string get_last_name() const;

    std::string get_first_name() const;

    Date get_born() const;

    bool compare(const Person &other) const;

    void set_last_name(const std::string &_last_name); //just to test copy

    void set_born(const Date &_date); //just to test copy

};


#endif //OOP_PERSON_H