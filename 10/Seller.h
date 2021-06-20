//
// Created by Aljosha on 08.06.2021.
//


#include "Employee.h"


#ifndef OOP_SELLER_H
#define OOP_SELLER_H
namespace hfu {

    class Seller : public Employee {
    private:
        int pay, commission;
    public:
        Seller(int id, const std::string &lastName, const std::string &firstName, int pay, int commission);

        int salary();

        int getPay() const;

        int getCommission() const;

    };
}
#endif //OOP_SELLER_H
