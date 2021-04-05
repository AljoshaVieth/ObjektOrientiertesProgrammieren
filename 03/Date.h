//
// Created by Aljosha on 30.03.2021.
//

#ifndef OOP_DATE_H
#define OOP_DATE_H


class Date {
private:
    int year, month, day;
public:
    void init(const int year,const  int month,const int day);
    int get_year() const;
    int get_month() const;
    int get_day() const;
private:
    void date_is_valid(const int &_year, const int &_month,const int &_day) const;
    bool year_is_valid(const int &_year) const;
    bool month_is_valid(const int &_month) const;
    bool day_is_valid(const int &_year, const int &_month, const int &_day) const;
};


#endif //OOP_DATE_H

