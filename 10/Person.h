//
// Created by Aljosha on 08.06.2021.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H


#include <string>

namespace hfu {
    class Person {
    private:
        int id;
        std::string last_name;
        std::string first_name;

    public:
        Person(int id, const std::string &lastName, const std::string &firstName);

        int getId() const;

        const std::string &getLastName() const;

        const std::string &getFirstName() const;
    };
}


#endif //OOP_PERSON_H
