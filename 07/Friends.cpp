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
        std::cout << "in dtor... removing names array with " << size << " names from heap" << std::endl;
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
            copy_array(_names, _size, copy);
            return copy;
        }
        return nullptr;
    }


    void Friends::add(const std::string &name) {
        std::string *new_names = new std::string[this->size + 1];
        copy_array(this->names, this->size, new_names);
        new_names[this->size] = name;
        delete[] names;
        this->names = new_names;
        this->size++;
    }

    void Friends::alter_names(const std::string *_names, const int &_size) {
        this->names = set_names(_names, _size);
        this->size = _size;
    }


    bool Friends::friends_are_equal(const Friends &friends_to_compare_with) const {
        if (this->size != friends_to_compare_with.get_size()) {
            return false;
        }
        for (int i = 0; i < this->size; i++) {
            if (this->names[i] != friends_to_compare_with.get_names()[i]) {
                return false;
            }
        }
        return true;
    }

    bool Friends::operator==(const Friends &other) const {
        return friends_are_equal(other);
    }

    bool Friends::operator!=(const Friends &other) const {
        return !friends_are_equal(other);
    }


    void Friends::copy_array(const std::string *original, const int &original_size, std::string *copy) {
        for (int i = 0; i < original_size; i++) {
            copy[i] = original[i];
        }
    }

    Friends &Friends::operator=(const Friends &other) {
        set_names(other.names, other.size);
        return *this;
    }

    std::string &Friends::operator[](const int index) {
        if (index < 0 || index >= size) {
            throw std::invalid_argument("index not found");
        }
        return names[index];
    }


    // Using getter methods instead of friend because they exist already.
    std::ostream &operator<<(std::ostream &out, const Friends &friends) {
        std::string friendsAsString = "Friends(";
        for (int i = 0; i < friends.get_size(); ++i) {
            friendsAsString = friendsAsString + friends.get_names()[i] + ", ";
        }
        friendsAsString = friendsAsString.substr(0, friendsAsString.size() - 2) + ")";
        out << friendsAsString;
        return out;
    }
}
