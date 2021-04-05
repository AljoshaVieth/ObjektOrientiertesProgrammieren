//
// Created by Aljosha on 23.03.2021.
//
#include <iostream>
#include <cassert>

namespace hfu {

    bool is_digit(char c) {
        return (c >= '0' && c <= '9');
    }

    void is_digit_test() {
        assert(is_digit('1'));
        assert(is_digit('9'));
        assert(is_digit('0'));
        assert(is_digit('a') == false);
        assert(is_digit('$') == false);
    }

    bool is_sign(char c, int *sign) {
        bool c_is_sign = (c == '+' || c == '-');
        if (c_is_sign) {
            if (c == '+') {
                (*sign) = +1;
            } else {
                (*sign) = -1;
            }
        }
        return c_is_sign;
    }

    void is_sign_test() {
        int sign = 23;
        assert(is_sign('-', &sign));
        assert(sign == -1);
        sign -= 23;
        assert(is_sign('+', &sign));
        assert(sign == 1);
        assert(!is_sign('x', &sign));
    }


    int parse_int(const std::string &text) {
        int result = 0;
        int sign = 1;
        int digit_area = 1;
        for (int i = text.length() - 1; i >= 0; i--) {
            if (i != 0) {
                if (!is_digit(text[i])) {
                    throw std::invalid_argument("char at pos " + std::to_string(i) + " is not a digit!");
                }
                result = result + (text[i] - '0') * digit_area;
            } else if (is_digit(text[0])) {
                result = result + (text[i] - '0') * digit_area;
            } else if (!is_sign(text[0], &sign)) {
                throw std::invalid_argument("string has to start with a number or a sign!");
            }
            digit_area = digit_area * 10;
        }

        result = result * sign;
        return result;
    }

    void parse_int_test() {
        std::string text = "1234";
        assert(parse_int(text) == 1234);
        text = "-1234";
        assert(parse_int(text) == -1234);
        text = "00056";
        assert(parse_int(text) == 56);
        try {
            text = "a56";
            parse_int(text);
            assert(false);
        }
        catch (...) {}
        try {
            text = "5-6";
            parse_int(text);
            assert(false);
        } catch (...) {}
        try {
            text = "5b6";
            parse_int(text);
            assert(false);
        } catch (...) {}
    }


    int parse_int(std::string *text) {
        return parse_int(*text);
    }

    void parse_int_with_pointer_test() {
        std::string text = "1234";
        assert(parse_int(&text) == 1234);
        try {
            text = "a56";
            parse_int(&text);
            assert(false);
        } catch (...){}
    }


}

int main() {
    std::cout << "starting" << std::endl;
    hfu::is_digit_test();
    std::cout << "is_digit_test passed" << std::endl;
    hfu::is_sign_test();
    std::cout << "is_sign_test passed" << std::endl;
    hfu::parse_int_test();
    std::cout << "parse_int_test passed" << std::endl;
    hfu::parse_int_with_pointer_test();
    std::cout << "parse_int_with_pointer_test passed" << std::endl;
    std::cout << "terminating" << std::endl;

}

