#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	~Date() = default;
	inline int GetMonthDay(int year, int month)
	{
		static int month_arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) && (((year % 4 == 0) && (year % 100 != 0)) 
										|| (year % 400 == 0)))
		{
			return 29;
		}
		return month_arr[month];
	}

	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);

	void print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	friend ostream& operator<<(ostream& _out, const Date& d);
	friend istream& operator>>(istream& _in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};