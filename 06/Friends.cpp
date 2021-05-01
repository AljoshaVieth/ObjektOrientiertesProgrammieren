//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>

namespace hfu {


#include "Friends.h"

    Friends::Friends(const std::string *names, int size) : names(set_names(names, size)), size(validate_size(size)) {}

    Friends::Friends() : Friends(nullptr, 0) {}

    Friends::Friends(const Friends &other) : Friends(other.get_names(), other.get_size()) {

    }

    Friends::~Friends() {
        std::cout << "in dtor... removing " << size << " names" << std::endl;
        delete[] names;
    }

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

    std::string *Friends::set_names(const std::string *_names, const int &_size) {
        if (_size > 0) {
            std::string *copy = new std::string[_size];
            for (int i = 0; i < _size; i++) {
                copy[i] = _names[i];
            }
            return copy;
        }
        return nullptr;
    }

    void Friends::add(const std::string &name) {
        std::string *new_names = new std::string[size + 1];
        for (int i = 0; i < size; i++) {
            new_names[i] = names[i];
        }
        new_names[size] = name;
        delete[] names;
        this->names = new_names;
        this->size++;
    }

    void Friends::alter_names(const std::string *_names, const int &_size) {
        this->names = set_names(_names, _size);
        this->size = _size;
    }


}
