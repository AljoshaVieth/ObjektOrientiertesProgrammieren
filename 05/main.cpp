//
// Created by Aljosha on 25.04.2021.
//
#include <iostream>
#include <cassert>

namespace hfu {

#include "Friends.h"
#include "Date.h"
#include "Person.h"

    /**
     * Date needs no copy ctr since no pointers or references are used
     */
    void date_copy_test(){
        Date date(1998,12,02);
        Date copy = date;
        copy.setYear(2000);
        assert(date.get_year() == 1998);
        assert(copy.get_year() == 2000);
    }

    /**
     * Person needs no copy ctr since no pointers or references are directly used
     */
    void person_copy_test(){
        Date date(1998,12,02);
        Date other_date(2000,12,02);
        Person person("lastName", "firstName", date);
        Person copy = person;
        copy.set_last_name("otherLastName");
        copy.set_born(other_date);
        assert(person.get_last_name() == "lastName");
        assert(person.get_born().get_year() == 1998);
        assert(copy.get_last_name() == "otherLastName");
        assert(copy.get_born().get_year() == 2000);
    }

    void friends_copy_test() {
        std::string names[] = {"Donald", "Daisy"};
        //std::string other_names[2] = {"Fix", "Foxy"};
        Friends friends(names, 2);
        Friends other_friends = friends;
        std::cout << other_friends.get_size() << std::endl;
        std::cout << "copy created" << std::endl;
        friends.set_names(2);


        //std::cout << friends.get_names()[0] << std::endl;
       // std::cout << other_friends.get_names()[0] << std::endl;

    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::date_copy_test();
    std::cout << "date_copy_test passed" << std::endl;
    hfu::person_copy_test();
    std::cout << "person_copy_test passed" << std::endl;
    hfu::friends_copy_test();
    std::cout << "friends_copy_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

