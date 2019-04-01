#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	void _Print();
private:
	int _year;
	int _month;
	int _day;
};