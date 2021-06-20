//
// Created by Aljosha on 08.06.2021.
//
#include <iostream>
#include <cassert>
#include "Guest.h"
#include "Employee.h"
#include "Worker.h"
#include "Seller.h"

namespace hfu {


    void test(){
        auto employee= new Employee(4, "Duck", "Tick");
        std::cout << employee->salary() << std::endl;
        assert(employee->salary()==0);
        auto worker= new Worker(4, "Duck", "Tick", 9, 40);
        employee=worker;
        assert(employee->salary()==9*40);
        auto seller= new Seller(5, "Duck", "Trick", 1000, 2000);
        employee=seller;
        assert(employee->salary()==1000+2000);
    }
}


int main() {
    std::cout << "starting" << std::endl;
    hfu::test();
    std::cout << "test passed" << std::endl;
    std::cout << "terminating" << std::endl;
    return 0;
}