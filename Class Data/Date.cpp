#include"Date.h"

Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
	cout << "Date(int,int,int)" << this << endl;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	cout << "Date(const Date&)" << this << endl;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date:: operator=(const Date&)" << this << endl;
	}
	return *this;
}
Date Date::operator+(int days)
{
	_day = _day + days;
	return *this;
}
Date Date:: operator-(int days)
{
	_day = _day - days;
	return *this;
}
Date &Date:: operator++()
{
	_day = _day + 1;
	return *this;
}
//ºóÖÃ
Date Date:: operator++(int)
{
	Date temp = *this;
	_day = _day + 1;
	return temp;
}
Date &Date:: operator--()
{
	_day = _day - 1;
	return *this;
}
Date Date:: operator--(int)
{
	Date temp = *this;
	_day = _day - 1;
	return temp;
}
bool Date:: operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	if ((_year == d._year) && (_month > d._month))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day > d._day))
		return true;
	return false;

}
bool Date:: operator>=(const Date& d)const
{
	if (_year > d._year)
		return true;
	if ((_year == d._year) && (_month > d._month))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day > d._day))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		return true;
	return false;
}
bool Date::operator<(const Date& d)const
{
	if (_year < d._year)
		return true;
	if ((_year == d._year) && (_month < d._month))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day < d._day))
		return true;
	return false;
}
bool Date::operator<=(const Date& d)const
{
	if (_year < d._year)
		return true;
	if ((_year == d._year) && (_month < d._month))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day < d._day))
		return true;
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		return true;
	return false;
}
bool Date::operator==(const Date& d)const
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
bool Date::operator!=(const Date& d)const
{
	return (!Date::operator==(d));
}
void Date::_Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
void Test()
{
	
	Date d1(2019, 4, 1);
	Date d2(d1);
	Date d3(2018, 4, 2);
	d3._Print();
	d3 = d1;
	d3._Print();
	d3 = d3 + 5;
	d3._Print();
	bool ret = d3 > d2;
	cout << ret << endl;
}
#include<stdlib.h>
int main()
{
	Test();
	system("pause");
	return 0;
}