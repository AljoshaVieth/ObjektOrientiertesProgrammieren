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

    void end_friendship_test(){
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2); //implicit dtor, called when } is reached
        Friends *other_friends = new Friends(names, 2);
        other_friends->add("another one"); // adding another friend, hence friends and other_friends having different sizes which helps showing which gets destroyed first
        delete other_friends; //explicit dtor, called now (before implicit dtor)
    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::friends_add_test();
    std::cout << "friends_copy_test passed" << std::endl;
    hfu::end_friendship_test();
    std::cout << "end_friendship_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

