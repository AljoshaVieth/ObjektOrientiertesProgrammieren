//
// Created by Aljosha on 04.05.2021.
//
#include <iostream>


#include <cassert>
#include <sstream>

namespace hfu {

#include "Vector3D.h"
#include "Friends.h"

    /**
     * Copy ctor and dtor are not needed since all values are primitive and on stack
     * Assignment isn´t helpful, since all values are const and therefore cannot be reassigned
     */


    // test + operator
    void sum_test() {
        Vector3D vector3D(1, 2, 3);
        Vector3D another_vector3D(5, 6, 7);
        Vector3D sum = vector3D + another_vector3D;
        assert(sum.get_x() == 6);
        assert(sum.get_y() == 8);
        assert(sum.get_z() == 10);
    }

    // test - operator
    void subtract_test() {
        Vector3D vector3D(10, 20, 30);
        Vector3D another_vector3D(50, 60, -70);
        Vector3D difference = another_vector3D - vector3D;
        assert(difference.get_x() == 40);
        assert(difference.get_y() == 40);
        assert(difference.get_z() == -100);
    }

    // test negation with - operator
    void negation_test() {
        Vector3D vector3D(40, 60, -80);
        Vector3D negated_sum = -vector3D;
        assert(negated_sum.get_x() == -40);
        assert(negated_sum.get_y() == -60);
        assert(negated_sum.get_z() == 80);
    }

    // test * operator
    void product_test() {
        // (float * Vector3D)
        Vector3D vector3D(33, 55, -77);
        float multiplier = 5;
        Vector3D product = multiplier * vector3D;
        assert(product.get_x() == 165);
        assert(product.get_y() == 275);
        assert(product.get_z() == -385);

        // (Vector3D * float)
        Vector3D another_vector3D(11, 22, -33);
        multiplier = -multiplier;
        Vector3D another_multiplication = another_vector3D * multiplier;
        assert(another_multiplication.get_x() == -55);
        assert(another_multiplication.get_y() == -110);
        assert(another_multiplication.get_z() == 165);
    }

    // test << operator
    void vector3D_as_text_test() {
        Vector3D vector3D(123, 456, 789);
        std::cout << vector3D << std::endl;

    }

    void dot_product_test() {
        Vector3D vector3D(22, 33, 44);
        Vector3D another_vector3D(55, 66, 77);
        float dot_product = vector3D * another_vector3D;
        assert(dot_product == 6776);
    }


    void friends_as_text_test() {
        std::string names[2] = {"Donald", "Daisy"};
        Friends friends(names, 2);
        std::ostringstream out;
        out << friends << std::endl;
        std::string text = out.str();
        assert(text == "Friends(Donald, Daisy)\n"); // don´t forget the new line control character caused by std::endl
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
    hfu::sum_test();
    std::cout << "sum_test passed" << std::endl;
    hfu::subtract_test();
    std::cout << "subtract_test passed" << std::endl;
    hfu::negation_test();
    std::cout << "negation_test passed" << std::endl;
    hfu::product_test();
    std::cout << "product_test passed" << std::endl;
    hfu::dot_product_test();
    std::cout << "dot_product_test passed" << std::endl;
    hfu::vector3D_as_text_test();
    std::cout << "vector3D_as_text_test passed" << std::endl;
    hfu::friends_as_text_test();
    std::cout << "friends_as_text_test passed" << std::endl;
    hfu::friends_assignment_test();
    std::cout << "friends_assignment_test passed" << std::endl;
    hfu::friends_index_test();
    std::cout << "terminating" << std::endl;
    return 0;
}

