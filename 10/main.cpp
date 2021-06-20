//
// Created by Aljosha on 08.06.2021.
//
#include <iostream>
#include <cassert>
#include "Guest.h"
#include "Employee.h"
#include "Worker.h"
#include "Seller.h"

namespace hfu {
    void guest_test() {
        Guest guest(1, "lastName", "firstName", 5, 20);
        assert(guest.getId() == 1);
        assert(guest.getLastName() == "lastName");
        assert(guest.getFirstName() == "firstName");
        assert(guest.getDays() == 5);
        assert(guest.getRoomRate() == 20);
        assert(guest.check() == 100);
        Person p = guest;
    }

    /**
     * It´s impossible to assign an object of type Guest to a variable of type Person because Guest inherits from Person
     * and Person does not have all fields needed in Guest.
     *
     * It´s not bad to let Guest inherit from Person since normally any Guest is a Person, unless it´s a hotel for animals
     */


    void employee_test() {
        Employee employee(1, "lastName", "firstName");
        assert(employee.salary() == 0);
    }

    void worker_test() {
        Worker worker(1, "lastName", "firstName", 10, 8);
        assert(worker.getId() == 1);
        assert(worker.getLastName() == "lastName");
        assert(worker.getFirstName() == "firstName");
        assert(worker.getHourlyRate() == 10);
        assert(worker.getHoursWorked() == 8);
        assert(worker.salary() == 80);
    }

    void seller_test() {
        Seller seller(1, "lastName", "firstName", 2000, 745);
        assert(seller.getId() == 1);
        assert(seller.getLastName() == "lastName");
        assert(seller.getFirstName() == "firstName");
        assert(seller.getPay() == 2000);
        assert(seller.getCommission() == 745);
        assert(seller.salary() == 2745);
    }

    /**
     * It is not recommended to define the class hierarchy in this way because the method 'salary' in class 'Worker' and 'Seller' hides the 'salary' method from class 'Employee'
     */

    void combination_test() {
        Person person(1, "personLast", "personFirst");
        Employee employee(2, "employeeLast", "employeeFirst");
        Worker worker(3, "workerLast", "workerFirst", 10, 8);
        Seller seller(4, "sellerLast", "sellerFirst", 2000, 745);
        /*
         * Impossible to assign (since base/parent is assigned to sub/child)
         * Employee employeePerson = person;
         * Worker workerPerson = person;
         * Seller sellerPerson = person;
         * Worker workerEmployee = employee;
         * Seller sellerEmployee = employee;
         * Worker workerSeller = seller;
         * Seller sellerWorker = worker;
        * Seller sellerWorker = worker;
         */

        /*
         * Possible to assign (since sub/child is assigned to base/parent)
         */
        Person personEmployee = employee;
        Person personWorker = worker;
        Person personSeller = seller;
        Employee employeeWorker = worker;
        Employee employeeSeller = seller;

        /**
         * Since c++ standard is not polymorphic, the method of the object type on the left is used rather than on the right.
         */
        assert(employeeWorker.salary() == 0);
        assert(employeeSeller.salary() == 0);
    }
}


int main() {
    std::cout << "starting" << std::endl;
    hfu::guest_test();
    std::cout << "guest_test passed" << std::endl;
    hfu::employee_test();
    std::cout << "employee_test passed" << std::endl;
    hfu::worker_test();
    std::cout << "worker_test passed" << std::endl;
    hfu::seller_test();
    std::cout << "seller_test passed" << std::endl;
    hfu::combination_test();
    std::cout << "combination_test passed" << std::endl;
    std::cout << "terminating" << std::endl;
    return 0;
}