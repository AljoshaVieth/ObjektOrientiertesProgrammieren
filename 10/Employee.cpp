//
// Created by Aljosha on 08.06.2021.
//


#include "Employee.h"

namespace hfu {
    int Employee::salary() {
        return 0;
    }

    Employee::Employee(int id, const std::string &lastName, const std::string &firstName)
            : Person(id, lastName, firstName) {}
}
