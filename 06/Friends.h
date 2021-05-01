//
// Created by Aljosha on 03.04.2021.
//

#ifndef OOP_FRIENDS_H
#define OOP_FRIENDS_H

#include <string>


class Friends {
private:
    std::string *names;
    int size;

    int validate_size(const int _size);

    bool friends_are_equal(const Friends &friends_to_compare_with) const;

public:

public:
    Friends(const std::string *names, int size);

    Friends();

    Friends(const Friends &other);

    virtual ~Friends();

    const std::string *get_names() const;


    int get_size() const;

    const std::string &name(int v);

    std::string *set_names(const std::string *_names, const int &_size);

    void copy_array(const std::string *original, const int &original_size, std::string *copy);

    void add(const std::string &name);

    void alter_names(const std::string *_names, const int &_size);

    bool operator==(const Friends &other) const;

    bool operator!=(const Friends &other) const;




};


#endif //OOP_FRIENDS_H