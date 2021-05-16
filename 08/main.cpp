//
// Created by Aljosha on 16.05.2021.
//
#include <cassert>

#include "ArrayList.h"
#include "ArrayList.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include "ostream"
namespace hfu {
#include "Date.h"


    template<typename T>
    bool find(const T *array, const int &length, const T &key) {
        if (length <= 0) {
            throw std::invalid_argument("Length has to be more than 0");
        }
        for (int i = 0; i < length; i++) {
            if (array[i] == key) {
                return true;
            }
        }
        return false;
    }

    void find_test() {
        // int array
        int array[5] = {1, 2, 3, 4, 5};
        assert(find(array, 5, 3));
        assert(!find(array, 5, 89));
        try {
            find(array, 0, 23);
            assert(false);
        }
        catch (...) {
        }
        // string array
        std::string names[2] = {"Donald", "Daisy"};
        std::string key = "Donald";
        assert(find(names, 2, key));
        assert(!find(names, 2, key + "x"));
        // double
        double numbers[3] = {3.141, 2.12, 4.20000000005};
        assert(find(numbers, 3, 2.12));
        assert(find(numbers, 3, 4.20000000005));
        assert(!find(numbers, 3, 4.20000000007));
    }

    void date_test() {
        Date date1(2021, 1, 1);
        Date date2(2020, 12, 31);
        Date date3(2019, 12, 24);
        Date date4(1989, 11, 9);
        Date dates[] = {date1, date2, date3};

        for (int i = 0; i < 3; i++) {
            assert(find(dates, 3, dates[i]));
        }
        assert(!find(dates, 3, date4));
    }

    void friends_as_text_test() {
        // Other as suspected, no problems occurred when switching from class to template. Maybe because of how the operator gets overloaded?
        // if it would not work, one has to overload the operator several times, something like this: std::ostream &operator<<(std::ostream &out, const ArrayList<T> &list) + std::ostream &operator<<(std::ostream &out, const string* &list) {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        std::ostringstream out;
        out << friends << std::endl;
        std::string text = out.str();
        std::cout << friends << std::endl;
        assert(text == "entries(Donald, Daisy)\n"); // don´t forget the new line control character caused by std::endl
    }

    void friends_assignment_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        Friends some_more_friends;
        some_more_friends = friends;
        /*
         * Since the pointer get´s copied, problems occur when dtor is called, because the second dtor cannot delete something,
         * which is already deleted.Sadly, these problems cannot be caught because the program just exits with an error code.
         * All params are private and the getters are const, hence it´s difficult to write a test which displays the alteration of names which would affect original and copy
         */
    }

    void friends_index_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        assert(names[1] == "Daisy");
        try {
            friends[-222];
            assert(false);
        }
        catch (...) {
        }
    }
}


int main() {
    std::cout << "starting" << std::endl;
    hfu::find_test();
    std::cout << "find_test passed" << std::endl;
    hfu::date_test();
    std::cout << "date_test passed" << std::endl;
    hfu::friends_assignment_test();
    std::cout << "friends_assignment_test passed"<< std::endl;
    hfu::friends_as_text_test();
    std::cout << "friends_as_text_test passed"<< std::endl;
    hfu::friends_index_test();
    std::cout << "friends_indey_test passed"<< std::endl;
    std::cout << "terminating" << std::endl;
    return 0;
}

