//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
#include <cassert>

namespace hfu {

#include "Friends.h"
#include "Date.h"
#include "Person.h"


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
        assert(friends.get_names()[1] == "abc"); // why does cassert not print an error? It just exits with an error code
    }


    void friends_constructor_altered_names_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(friends.name(0) == "Donald");
        names[0] = "Mickey";
        assert(friends.name(0) == "Donald");
    }

    void name_at_position_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(friends.name(0) == "Donald");
        assert(friends.name(1) == "Daisy");
        try {
            friends.name(2);
            assert(false);
        }
        catch (...) {}
        try {
            friends.name(-1);
            assert(false);
        }
        catch (...) {}
    }

    void date_test() {
        Date xmas(2021, 12, 24);
        assert(xmas.get_day() == 24);
        assert(xmas.get_month() == 12);
        assert(xmas.get_year() == 2021);
        Date last_day_in_february_in_leap_year(2024, 2, 29);
        assert(last_day_in_february_in_leap_year.get_day() == 29);
        try {
            Date invalidDay(2021, 4, 31);
            assert(false);
        }
        catch (...) {}
        try {
            Date invalidYear(-1234, 12, 2);
            assert(false);
        }
        catch (...) {}
        try {
            Date last_day_in_february_in_normal_year(2022, 2, 29);
            assert(false);
        }
        catch (...) {}
    }

    void person_test() {
        Date birthdate(1998, 12, 2);
        Person author("Vieth", "Aljosha", birthdate);
        assert(author.get_last_name() == "Vieth");
        assert(author.get_first_name() == "Aljosha");
        assert(author.get_born().get_year() == 1998);
        assert(author.get_born().get_month() == 12);
        assert(author.get_born().get_day() == 2);
        try {
            Person nameless_guy("", "", birthdate);
            assert(false);
        }
        catch (...) {}

        Person other_person("Walker", "Paul", birthdate);
        assert(author.compare(other_person));
        Person other_person_2("Müller", "Thomas", birthdate);
        assert(!author.compare(other_person_2));
        Person other_person_3("Vieti", "Jane", birthdate);
        assert(author.compare(other_person_3));
        Person other_person_4("Vietha", "Harry", birthdate);
        assert(author.compare(other_person_4));
        Person other_person_5("Viet", "Ron", birthdate);
        assert(!author.compare(other_person_5));
    }

    // helper function to check sort
    std::string people_array_to_string(Person *people, const int &amount) {
        std::string people_as_string;
        for (int i = 0; i < amount; i++) {
            people_as_string += "|" + people[i].get_last_name();
        }
        return people_as_string.substr(1);
    }

    void sort(Person *people, const int &amount) {
        Person temp;
        bool changed;
        for (int i = 0; i < amount - 1; i++) {
            changed = false;
            //visualize sort: std::cout << people_array_to_string(people, 6) << std::endl;
            for (int j = 0; j < amount - i - 1; j++) {
                if (!people[j].compare(people[j + 1])) {
                    temp = people[j];
                    people[j] = people[j + 1];
                    people[j + 1] = temp;
                    changed = true;
                }
            }
            if (!changed) {
                return;
            }
        }
    }

    void sort_test() {
        Date birthdate(2021, 12, 2);
        Person thirst("Smith", "First Name", birthdate), second("Johnson", "First Name", birthdate), third("Williams",
                                                                                                           "First Name",
                                                                                                           birthdate), fourth(
                "Brown", "First Name", birthdate), fifth("Jones", "First Name", birthdate), sixth("Davis", "First Name",
                                                                                                  birthdate);


        Person people[6] = {thirst, second, third, fourth, fifth, sixth};
        sort(people, 6);
        std::string correct_order = "Brown|Davis|Johnson|Jones|Smith|Williams";
        assert(correct_order == people_array_to_string(people, 6));
    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::friends_constructor_test();
    std::cout << "friends_constructor_test passed" << std::endl;
    hfu::friends_empty_constructor_test();
    std::cout << "friends_empty_constructor_test passed" << std::endl;
    hfu::name_at_position_test();
    std::cout << "name_at_position_test passed" << std::endl;
    hfu::friends_constructor_altered_names_test();
    std::cout << "friends_constructor_altered_names_test passed" << std::endl;
    hfu::date_test();
    std::cout << "date_test passed" << std::endl;
    hfu::person_test();
    std::cout << "person_test passed" << std::endl;
    hfu::sort_test();
    std::cout << "sort_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

