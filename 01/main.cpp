//
// Created by Aljosha on 16.03.2021.
//
#include <cassert>
#include <iostream>

namespace hfu {

    bool in_tolerance(double v, double w) {
        double difference = v - w;
        return abs(difference) < 0.000000001;
    }

    double to_double(int integer, int fractional) {
        if (fractional < 0) {
            throw std::invalid_argument("fractional cannot be less then 0");
        }

        int divisor = 10;
        // find matching divisor
        while (fractional / divisor > 1) {
            divisor = divisor * 10;
        }

        // define decimal_place of result
        double decimal_place = (double) fractional / divisor;

        double result;

        // check if integer is less than 0, if so, make int positive, add decimal_place and then invert result to enable
        // correct negative results
        if (integer < 0) {
            integer = abs(integer);
            result = integer + decimal_place;
            result = result * -1;
        } else {
            result = integer + decimal_place;
        }
        return result;
    }

    void to_double_test() {
        assert(in_tolerance(to_double(4, 243), 4.243));
        assert(in_tolerance(to_double(456, 243), 456.243));
        assert(in_tolerance(to_double(456, 24367897), 456.24367897));
        assert(in_tolerance(to_double(4, 0), 4.0));
        assert(in_tolerance(to_double(0, 243), 0.243));
        assert(in_tolerance(to_double(-1, 243), -1.243));
        assert(in_tolerance(to_double(0, 0), 0.0));
        try {
            to_double(4, -243);
            assert(false);
        }
        catch (...) {
        }
    }
}

int main() {
    std::cout << "starting" << std::endl;
    hfu::to_double_test();
    std::cout << "to_double_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}
