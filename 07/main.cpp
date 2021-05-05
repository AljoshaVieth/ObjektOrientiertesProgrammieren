//
// Created by Aljosha on 04.05.2021.
//
#include <iostream>


#include <cassert>

namespace hfu {

#include "Vector3D.h"

    /**
     * Copy ctor and dtor are not needed since all values are primitive and on stack
     * Assignment isn´t helpful, since all values are const and therefore cannot be reassigned
     */

    // Using getter methods instead of friend because they are needed anyway. A vector is useless hen it´s values are inaccessible
    std::ostream &operator<<(std::ostream &out, const Vector3D vector3D) {
        out << "(" << vector3D.get_x() << "," << vector3D.get_y() << "," << vector3D.get_z() << ")";
        return out;
    }

    Vector3D operator*(const float &multiplier, const Vector3D &vector3D){
        return Vector3D(vector3D.get_x() * multiplier, vector3D.get_y() * multiplier, vector3D.get_z() * multiplier);
    }
    Vector3D operator*(const Vector3D &vector3D, const float &multiplier){
        return operator*(multiplier, vector3D);
    }


    void vector3D_operator_test() {
        Vector3D vector3D(1, 2, 3);
        Vector3D another_vector3D(5, 6, 7);

        // test + operator
        Vector3D sum = vector3D + another_vector3D;
        assert(sum.get_x() == 6);
        assert(sum.get_y() == 8);
        assert(sum.get_z() == 10);

        // test - operator
        Vector3D difference = another_vector3D - vector3D;
        assert(difference.get_x() == 4);
        assert(difference.get_y() == 4);
        assert(difference.get_z() == 4);

        // test negation ¬
        Vector3D negated_sum = -sum;
        assert(negated_sum.get_x() == -6);
        assert(negated_sum.get_y() == -8);
        assert(negated_sum.get_z() == -10);

        // test product
        float multiplier = 5;
        Vector3D product = multiplier * sum;
        assert(product.get_x() == 30);
        assert(product.get_y() == 40);
        assert(product.get_z() == 50);

        multiplier = -multiplier;
        Vector3D another_multiplication = difference * multiplier;
        assert(another_multiplication.get_x() == -20);
        assert(another_multiplication.get_y() == -20);
        assert(another_multiplication.get_z() == -20);

        // test << operator
        std::cout << "sum: " << sum << "\ndifference: " << difference << "\nnegated sum:" << negated_sum << std::endl;
        std::cout << "product: " << product << std::endl;
        std::cout << "reverse_multiplication: " << another_multiplication << std::endl;
    }

    void dot_product_test(){
        Vector3D vector3D(22, 33, 44);
        Vector3D another_vector3D(55, 66, 77);
        float dot_product = vector3D * another_vector3D;
        assert(dot_product == 6776);
    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::vector3D_operator_test();
    std::cout << "vector3D_operator_test passed" << std::endl;
    hfu::dot_product_test();
    std::cout << "dot_product_test passed" << std::endl;
    std::cout << "terminating" << std::endl;
    return 0;
}

