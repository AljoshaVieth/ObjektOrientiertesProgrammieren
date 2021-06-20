
//
// Created by Aljosha on 03.04.2021.
//
#ifndef OOP_ARRAYLIST_H
#define OOP_ARRAYLIST_H

#include <ostream>

namespace hfu {
    template<typename T>
    class ArrayList {
    private:
        T *data; // tried to use unique_prt, however problems occurred when including <memory> to use std::unique_ptr. Another option would be to use ArrayList<T data, int size>, however the size could not be validated
        int size;

        int validate_size(const int size);

        bool arrayLists_are_equal(const ArrayList &list_to_compare_with) const;

    public:
        ArrayList(const T *data, int _size);

        ArrayList();

        ArrayList(const ArrayList &other);

        virtual ~ArrayList();

        const T *get_data() const;

        int get_size() const;

        const T &name(int v);

        T *set_data(const T *_data, const int &_size);

        void copy_array(const T *original, const int &original_size, T *copy);

        void add(const T &name);

        void alter_data(const T *_data, const int &_size);

        bool operator==(const ArrayList &other) const;

        bool operator!=(const ArrayList &other) const;

        ArrayList &operator=(const ArrayList &other);


        T &operator[](const int index);
    };

    template
    class ArrayList<std::string>;

    typedef ArrayList<std::string> Friends;

}


// Using getter methods instead of friend because they exist already.
template<typename T>
std::ostream &operator<<(std::ostream &out, const hfu::ArrayList<T> &list);


#endif //OOP_ARRAYLIST_H