//
// Created by Aljosha on 03.04.2021.
//
#include <iostream>
#include <stdexcept>
#include "ArrayList.h"
#include <ostream>

namespace hfu {


    // https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp

    template <typename T>
    ArrayList<T>::ArrayList(const T *data, int _size) : data(set_data(data, _size)), size(validate_size(_size)) {}

    template <typename T>
    ArrayList<T>::ArrayList() : ArrayList(nullptr, 0) {}

    template <typename T>
    ArrayList<T>::ArrayList(const ArrayList &other) : ArrayList(other.get_data(), other.get_size()) {

    }
    template <typename T>
    ArrayList<T>::~ArrayList() {
        std::cout << "in dtor... removing data array with " << this->size << " data from heap" << std::endl;
        delete[] data;
    }

    template <typename T>
    const T *ArrayList<T>::get_data() const {
        return data;
    }

    template <typename T>
    int ArrayList<T>::get_size() const {
        return size;
    }

    template <typename T>
    const T &ArrayList<T>::name(int v) {
        if (v >= size || v < 0) {
            throw std::invalid_argument("This position does not exist!");
        }
        return data[v];
    }

    template <typename T>
    int ArrayList<T>::validate_size(const int _size) {
        if (_size < 0) {
            throw std::invalid_argument("Size cannot be less than 0!");
        }
        return _size;
    }

    template <typename T>
    T *ArrayList<T>::set_data(const T *_data, const int &_size) {
        if (_size > 0) {
            T *copy = new T[_size];
            copy_array(_data, _size, copy);
            return copy;
        }
        return nullptr;
    }


    template <typename T>
    void ArrayList<T>::add(const T &name) {
        T *new_data = new T[this->size + 1];
        copy_array(this->data, this->size, new_data);
        new_data[this->size] = name;
        delete[] data;
        this->data = new_data;
        this->size++;
    }

    template <typename T>
    void ArrayList<T>::alter_data(const T *_data, const int &_size) {
        this->data = set_data(_data, _size);
        this->size = _size;
    }


    template <typename T>
    bool ArrayList<T>::arrayLists_are_equal(const ArrayList &list_to_compare_with) const {
        if (this->size != list_to_compare_with.get_size()) {
            return false;
        }
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] != list_to_compare_with.get_data()[i]) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    bool ArrayList<T>::operator==(const ArrayList &other) const {
        return arrayLists_are_equal(other);
    }

    template <typename T>
    bool ArrayList<T>::operator!=(const ArrayList &other) const {
        return !arrayLists_are_equal(other);
    }

    template <typename T>
    void ArrayList<T>::copy_array(const T *original, const int &original_size, T *copy) {
        for (int i = 0; i < original_size; i++) {
            copy[i] = original[i];
        }
    }

    template <typename T>
    ArrayList<T> &ArrayList<T>::operator=(const ArrayList &other) {
        set_data(other.data, other.size);
        return *this;
    }

    template <typename T>
    T &ArrayList<T>::operator[](const int index) {
        if (index < 0 || index >= size) {
            throw std::invalid_argument("index not found");
        }
        return data[index];
    }


    // Using getter methods instead of friend because they exist already.
    template <typename T>
    std::ostream &operator<<(std::ostream &out, const ArrayList<T> &list) {
        std::string friendsAsString = "ArrayList(";
        for (int i = 0; i < list.get_size(); ++i) {
            friendsAsString = friendsAsString + list.get_data()[i] + ", ";
        }
        friendsAsString = friendsAsString.substr(0, friendsAsString.size() - 2) + ")";
        out << friendsAsString;
        return out;
    }
}
