//
// Created by Aljosha on 01.05.2021.
//
#include <iostream>
#include <cassert>

namespace hfu {

#include "Friends.h"



    void friends_add_test(){
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        friends.add("Gustav");
        assert(friends.name(2) == "Gustav");
    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::friends_add_test();
    std::cout << "friends_copy_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

