#include "Date.h"

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>=(const Date& d)
{
	/// this->operator>(d)
	return (*this > d) || (*this == d);
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp;
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp;
	*this -= 1;
	return tmp;
}

//int Date::operator-(const Date& d)
//{
//	int flag = 1;
//	Date max_date = *this;
//	Date min_date = d;
//	if (max_date < min_date)
//	{
//		min_date = *this;
//		max_date = d;
//		int flag = -1;
//	}
//	int count = 0;
//	while (max_date != min_date)
//	{
//		++min_date;
//		count++;
//	}
//	return count * flag;
//}


int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max_date = *this;
	Date min_date = d;
	if (max_date < min_date)
	{
		min_date = *this;
		max_date = d;
		flag = -1;
	}
	int count = 0;
	while (max_date != min_date)
	{
		max_date--;
		count++;
	}
	return count * flag;
}


ostream& operator<<(ostream& _out, const Date& d)
{
	_out << d._year << "/" << d._month << "/" << d._day;
	return _out;
}

istream& operator>>(istream& _in, Date& d)
{
	_in >> d._year >> d._month >> d._day;
	return _in;
}
