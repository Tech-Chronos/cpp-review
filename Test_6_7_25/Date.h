//
// Created by 有趣的中国人 on 2025/6/7.
//
#include <iostream>
#include "queue.h"
#ifndef TEST_6_7_25_DATE_H
#define TEST_6_7_25_DATE_H
namespace dsj
{
    class Date
    {
    public:
        friend std::ostream& operator<<(std::ostream& out, Date d1);

        Date(int year = 2003, int month = 6, int day = 22)
          :_year(year)
          ,_month(month)
          ,_day(22)
        {}

        bool operator>(const Date& date) const
        {
            if (_year > date._year)
            {
                return true;
            }
            else if (_year == date._year)
            {
                if (_month > date._month)
                {
                    return true;
                }
                else if (_month == date._month)
                {
                    if (_day > date._day)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        bool operator==(const Date& date) const
        {
            return (_year == date._year) && (_month == date._month) && (_day == date._day);
        }

        bool operator!=(const Date& date) const
        {
            return !(*this == date);
        }

        bool operator>=(const Date& date) const
        {
            return (*this > date) || (*this == date);
        }

        bool operator<(const Date& date) const
        {
            return !(*this >= date);
        }

        bool operator<=(const Date& date) const
        {
            return !(*this > date);
        }
    private:
        int _year;
        int _month;
        int _day;
    };
    std::ostream& operator<<(std::ostream& out, Date d1)
    {
        out << d1._year << " " << d1._month << " " << d1._day << " ";
        return out;
    }

    // 日期升序
    class CompareDateGreater
    {
    public:
        bool operator()(const Date& d1, const Date& d2) const
        {
            return d1 < d2;
        }
    };

    // 日期降序
    class CompareDateLess
    {
    public:
        bool operator()(const Date& d1, const Date& d2)
        {
            return d1 > d2;
        }
    };

    class CompareDateGreaterPtr
    {
    public:
        bool operator()(Date* ptrd1, Date* ptrd2)
        {
            return *ptrd1 < *ptrd2;
        }
    };

    class CompareDateLessPtr
    {
    public:
        bool operator()(Date* ptrd1, Date* ptrd2)
        {
            return *ptrd1 > *ptrd2;
        }
    };
}

#endif //TEST_6_7_25_DATE_H
