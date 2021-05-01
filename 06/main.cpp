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

    void equality_of_friends_test(){
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        Friends other_friends(names, 2);
        assert(friends == other_friends);
        other_friends.add("another one");
        assert(friends != other_friends);
        std::string other_names[2] = {"Fix", "Foxy"};
        Friends some_other_friends(other_names, 2);
        assert(friends != some_other_friends);
        std::string some_more_names[2] = {"Donald", "Daisi"};
        some_other_friends.alter_names(some_more_names, 2);
        assert(friends != some_other_friends);

    }


    /**
     * Since the original ctor has changed, the old tests are here again to ensure it still works
     * However, to better display the results from this task, these tests are disabled
     */
     /*
    void friends_constructor_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(friends.get_size() == 2);
        assert(friends.get_names()[0] == "Donald");
        assert(friends.get_names()[1] == "Daisy");
        try {
            Friends no_friends(names, -1);
            assert(false);
        }
        catch (...) {}
    }


    void friends_empty_constructor_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends;
        assert(friends.get_size() == 0);
        assert(friends.get_names() != names);
    }


    void friends_constructor_altered_names_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(friends.name(0) == "Donald");
        names[0] = "Mickey";
        assert(friends.name(0) == "Donald");
    }
      */



}

int main() {
    std::cout << "starting" << std::endl;
    hfu::friends_add_test();
    std::cout << "friends_copy_test passed" << std::endl;
    hfu::end_friendship_test();
    std::cout << "end_friendship_test passed" << std::endl;
    hfu::equality_of_friends_test();
    std::cout << "equality_of_friends_test passed" << std::endl;
    /*
    std::cout << "testing altered ctr" << std::endl;
    hfu::friends_constructor_test();
    std::cout << "friends_constructor_test passed" << std::endl;
    hfu::friends_empty_constructor_test();
    std::cout << "friends_empty_constructor_test passed" << std::endl;
    hfu::friends_constructor_altered_names_test();
    std::cout << "friends_constructor_altered_names_test passed" << std::endl;
     */
    std::cout << "terminating" << std::endl;

}

