//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
#include <cassert>

namespace hfu {

#include "Date.h"
#include "Person.h"

    void date_test() {
        Date xmas;
        xmas.init(2021, 12, 24);
        assert(xmas.get_day() == 24);
        assert(xmas.get_month() == 12);
        assert(xmas.get_year() == 2021);
        Date last_day_in_february_in_leap_year;
        last_day_in_february_in_leap_year.init(2024, 2, 29);
        assert(last_day_in_february_in_leap_year.get_day() == 29);
        try {
            Date invalidDay;
            invalidDay.init(2021, 4, 31);
            assert(false);
        }
        catch (...) {}
        try {
            Date invalidYear;
            invalidYear.init(-1234, 12, 2);
            assert(false);
        }
        catch (...) {}
        try {
            Date last_day_in_february_in_normal_year;
            last_day_in_february_in_normal_year.init(2022, 2, 29);
            assert(false);
        }
        catch (...) {}
    }

    void person_test() {
        Date birthdate;
        birthdate.init(1998, 12, 2);
        Person author;
        author.init("Vieth", "Aljosha", birthdate);
        assert(author.get_last_name() == "Vieth");
        assert(author.get_first_name() == "Aljosha");
        assert(author.get_born().get_year() == 1998);
        assert(author.get_born().get_month() == 12);
        assert(author.get_born().get_day() == 2);
        try {
            Person nameless_guy;
            nameless_guy.init("", "", birthdate);
            assert(false);
        }
        catch (...) {}

        Person other_person;
        other_person.init("Walker", "Paul", birthdate);
        assert(author.compare(other_person));
        other_person.init("Müller", "Thomas", birthdate);
        assert(!author.compare(other_person));
        other_person.init("Vieti", "Jane", birthdate);
        assert(author.compare(other_person));
        other_person.init("Vietha", "Harry", birthdate);
        assert(author.compare(other_person));
        other_person.init("Viet", "Ron", birthdate);
        assert(!author.compare(other_person));
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
        Date birthdate;
        birthdate.init(2021, 12, 2);
        Person thirst, second, third, fourth, fifth, sixth;

        thirst.init("Smith", "First Name", birthdate);
        second.init("Johnson", "First Name", birthdate);
        third.init("Williams", "First Name", birthdate);
        fourth.init("Brown", "First Name", birthdate);
        fifth.init("Jones", "First Name", birthdate);
        sixth.init("Davis", "First Name", birthdate);

        Person people[6] = {thirst, second, third, fourth, fifth, sixth};
        sort(people, 6);
        std::string correct_order = "Brown|Davis|Johnson|Jones|Smith|Williams";
        assert(correct_order == people_array_to_string(people, 6));
    }

}

int main() {
    std::cout << "starting" << std::endl;
    hfu::date_test();
    std::cout << "date_test passed" << std::endl;
    hfu::person_test();
    std::cout << "person_test passed" << std::endl;
    hfu::sort_test();
    std::cout << "sort_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

