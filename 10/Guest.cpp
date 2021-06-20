//
// Created by Aljosha on 08.06.2021.
//


#include "Guest.h"

namespace hfu {
    Guest::Guest(int id, const std::string &lastName, const std::string &firstName, int days, int roomRate) :
            Person(id, lastName, firstName), days(days), room_rate(roomRate) {}

    int Guest::getDays() const {
        return days;
    }

    int Guest::getRoomRate() const {
        return room_rate;
    }

    int Guest::check() const {
        return days * room_rate;
    }
}
