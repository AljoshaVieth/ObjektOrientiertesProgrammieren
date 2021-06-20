//
// Created by Aljosha on 08.06.2021.
//


#ifndef OOP_GUEST_H
#define OOP_GUEST_H


#include "Person.h"
namespace hfu {
    class Guest : public Person {
    private:
        int days;
        int room_rate;

    public:
        Guest(int id, const std::string &lastName, const std::string &firstName, int days, int roomRate);

        int getDays() const;

        int getRoomRate() const;

        int check() const;

    };
}


#endif //OOP_GUEST_H
