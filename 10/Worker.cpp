//
// Created by Aljosha on 08.06.2021.
//

#include "Worker.h"

namespace hfu {
    int Worker::salary()const {
        return hourly_rate * hours_worked;

    }

    Worker::Worker(int id, const std::string &lastName, const std::string &firstName, int hourlyRate, int hoursWorked)
            : Employee(id, lastName, firstName), hourly_rate(hourlyRate), hours_worked(hoursWorked) {}

    int Worker::getHourlyRate() const {
        return hourly_rate;
    }

    int Worker::getHoursWorked() const {
        return hours_worked;
    }
}

