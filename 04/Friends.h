//
// Created by Aljosha on 03.04.2021.
//

#ifndef OOP_FRIENDS_H
#define OOP_FRIENDS_H

#include <string>


class Friends {
private:
    const std::string* names;
    int size;
    int validate_size(const int _size);

public:

public:
    Friends(const std::string *names, int size);
    Friends();
    const std::string *get_names() const;
    int get_size() const;
    const std::string& name(int v);


    std::string *set_names(const std::string *_names, int _size);
};


#endif //OOP_FRIENDS_H
