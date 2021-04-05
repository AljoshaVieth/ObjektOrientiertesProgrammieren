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
public:
    void init(const std::string &_last_name, const std::string &_first_name, const Date &_birthdate);
    const std::string& get_last_name() const;
    const std::string& get_first_name() const;
    const Date& get_born() const;
    bool compare(const Person& other) const;
};


#endif //OOP_PERSON_H
