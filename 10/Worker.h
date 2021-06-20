//
// Created by Aljosha on 08.06.2021.
//
#include "Employee.h"



#ifndef OOP_WORKER_H
#define OOP_WORKER_H

namespace hfu {
    class Worker : public Employee {
    private:
        int hourly_rate, hours_worked;
    public:
        Worker(int id, const std::string &lastName, const std::string &firstName, int hourlyRate, int hoursWorked);

        int salary();

        int getHourlyRate() const;

        int getHoursWorked() const;


    };
}


#endif //OOP_WORKER_H
