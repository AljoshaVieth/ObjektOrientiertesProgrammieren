//
// Created by Aljosha on 08.06.2021.
//


#include "Seller.h"

namespace hfu {


    Seller::Seller(int id, const std::string &lastName, const std::string &firstName, int pay, int commission)
            : Employee(id, lastName, firstName), pay(pay), commission(commission) {}

    int Seller::getPay() const {
        return pay;
    }

    int Seller::getCommission() const {
        return commission;
    }

    int Seller::salary() const{
        return commission + pay;
    }
}

