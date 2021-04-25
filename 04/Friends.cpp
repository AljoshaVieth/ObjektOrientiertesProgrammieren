//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>

namespace hfu {


#include "Friends.h"

    Friends::Friends(const std::string *names, int size) : names(set_names(names, size)), size(validate_size(size)) {}

    Friends::Friends() : Friends(nullptr, 0) {}

    const std::string *Friends::get_names() const {
        return names;
    }

    int Friends::get_size() const {
        return size;
    }

    const std::string &Friends::name(int v) {
        if (v >= size || v < 0) {
            throw std::invalid_argument("This position does not exist!");
        }
        return names[v];
    }

    int Friends::validate_size(const int _size) {
        if (_size < 0) {
            throw std::invalid_argument("Size cannot be less than 0!");
        }
        return _size;
    }

    std::string *Friends::set_names(const std::string *_names, int _size) {

        if (_size > 0) {
            std::string *copy = new std::string[_size];
            for (int i = 0; i <= size; i++) {
                copy[i] = _names[i];
            }
            return copy;
        }
        return nullptr;
    }


}

