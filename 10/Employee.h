//
// Created by Aljosha on 08.06.2021.
//
#include "Person.h"



#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H

namespace hfu {
    class Employee : public Person {
    public:
        Employee(int id, const std::string &lastName, const std::string &firstName);

        int salary();


    };
}


#endif //OOP_EMPLOYEE_H
