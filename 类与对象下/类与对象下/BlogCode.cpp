#include"BlogCode.h"

#if 0
// 空类--->
class Date
{
public:
	Date()
	{
		cout << "Date():" << this << endl;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void InitDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{

	Date d1, d2, d3;
	// Date d4(); 不是创建了一个对象，而是一个函数声明(没有参数，返回一个日期类型对象的函数声明)
	Date d5(2019, 3, 19);

	d1.InitDate(2019, 3, 19);
	d1.PrintDate();

	d2.InitDate(2019, 3, 20);
	d2.PrintDate();

	d3.InitDate(2019, 3, 18);
	d3.PrintDate();

	return 0;
}
#endif
#if 0
// 用户没有显式定义，编译器生成的构造函数：默认的构造函数，一定是无参的
// 
class Date
{
public:
	// 默认构造函数
	// 无参构造函数
	 	Date()
	 	{
	 		cout << "Date():" << this << endl;
	 	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	// 默认的构造函数只能存在一个
	Date d1;
	//Date d2(2019, 3, 19);
	return 0;
}
#endif
#if 0
// 什么情况下，编译器才会生成？
// 如果编译器感觉自己需要的时候就会生成---->什么才是编译器需要的时候
// 四个场景：

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		cout << this->_hour << endl;
	}

	Time(Time&)
	{}

	Time& operator=(Time& t)
	{
		return *this;
	}

	~Time()
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	// 	Date()
	// 	{}

	/*
	Date(Date& d)
	: _t(d._t)
	{}

	*/

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1; // 日期类的构造函数 // Time()
	Date d2(d1);  // Time(Time&)--->找个调用位置--->Date类的拷贝构造函数中
	Date d3;
	d3 = d1;



	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	// 	Date(const Date& d)
	// 	{
	// 		_year = d._year;
	// 		_month = d._month;
	// 		_day = d._day;
	// 		cout << "Date(Date&):" << this << endl;
	// 	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}


private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{
	Date d1(2019, 3, 22);
	Date d2(d1);

	Date d3(2018, 3, 22);
	d3 = d1;
}

int main()
{
	TestDate();
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		cout << "String(const char* ):" << this << endl;
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	// 拷贝构造函数必须显式提供

	~String()
	{
		cout << "~String():" << this << endl;
		free(_str);
		_str = nullptr;
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	
}

int main()
{
	TestString();
	system("pause");
	return 0;
}
#endif

#if 0
// 什么是运算符重载
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}


	// *this + day
	Date operator+(int day)
	{
		Date temp(*this);
		temp._day += day;
		return temp;
	}


	Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// 前置++
	// d2 = ++d1
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// 后置++
	// d2 = d1++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{

	Date d1(2019, 3, 22);
	d1.DateAdd(3);
	d1 = d1 + 3;


	Date d2(d1);
	d2 = d1++;
	d2 = ++d1;

	Date d3(2018, 3, 22);
	d3 = d3;
	d3 = d1;
	//d3.operator=(d1);
	d1 = d2 = d3;
	//d1.operator=(d2.operator=(d3));
	if (d3 == d1);
	Date& d4 = d3;
	d4 = d3;
}

int main()
{
	TestDate();
	return 0;
}
#endif

#if 0
// const类成员
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}

	// d1 = d2 = d3;
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	// 可读可写
	// Date* const  this
	void TestFunc1()
	{
		//this = nullptr;
		this->_day++;
	}

	// 在该函数中不能修改当前对象的成员变量
	// const修饰this指针
	// const Date* const this;
	void TestFunc2()const
	{
		this->_day++;
		//_year++;
		//_month++;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

	Date* operator&()
	{
		return this;
	}

	// Date* p = &d2;
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	mutable int _day;
};

int main()
{
	Date d1(2019, 3, 24);
	const Date d2(2019, 3, 25); // 常量：d2中的内容不允许被修改
	cout << &d2 << endl;
	//d2.TestFunc1();  // TestFunc1成员函数：普通的成员函数，在函数中可以修改当前对象的成员
	d1.TestFunc1();
	d1.TestFunc2();
	system("pause");
	return 0;
}
#endif

//class Date
//{
//public:
//	void TestFunc2()const
//	{
//		this->_day++;
//		//_year++;
//		//_month++;
//	}
//	void TestFunc2()
//	{
//		this->_day++;
//		//_year++;
//		//_month++;
//	}
//private:
//	int _year;
//	int _month;
//	mutable int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.TestFunc2();
//	system("pause");
//	return 0;
//}

#if 0
// 类总共创建了多少个对象？
// 计数的变量----不能包含在每个对象中，应该是所有对象共享
// 1. 使用全局变量---->可以---缺陷：不安全
//int g_count = 0;

// 普通成员变量                static成员变量
// 可以在初始化列表中初始化         不行
// 每个对象中都包含             只有一份，没有包含在具体的对象中，是所有对象共享的
// 必须通过对象访问             可以通过对象直接访问 || 也可以通过类名加作用域直接访问
class Test
{
public:
	Test()
		: _b(0)
	{
		_count++;
	}

	Test(Test& t)
	{
		_count++;
	}

	static int GetCount()
	{
		return _count;
	}

	~Test()
	{
		_count--;
	}

private:
	int _b;
	static int _count;   
};

int Test::_count = 0;

void TestCount()
{
	Test t1, t2;
	//cout << g_count << endl;
	cout << t1.GetCount() << endl;
}

int main()
{
	Test::GetCount();
	Test t1, t2;
	cout << Test::GetCount() << endl;
	// 	cout << sizeof(t1) << endl;
	// 	cout << &t1._count << "=" << &t2._count << endl;
	// 	cout << Test::_count << endl;
	// 
	// 	int a = 10;
	// 	a = t1._count;
	// 	a = Test::_count;  //

	//g_count = 0;
	TestCount();
	//cout << g_count << endl;
	cout << Test::GetCount() << endl;
	system("pause");
	return 0;
}
#endif

//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//	A(const A& t)
//	{
//		++_count;
//	}
//
//	static int GetCount()
//	{
//		return _count;
//	}
//private:
//	static int _count;
//};
//int A::_count = 0;
//
//void Test()
//{
//	cout << A::GetCount() << endl;// 0
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetCount() << endl;//3
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//
//class Time
//{
//	friend void TestFriend();
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{
//		cout << this->_hour << endl;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};

#if 0
class Date
{
	// 友元函数
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	// _cout<<d.GetYear()<<"-"<<d.GetMonth()<<"-"<<d.GetDay();
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}


int main()
{
	Date d(2019, 3, 24);
	d.PrintDate();
	cout << 10 << endl; 
	// cout<<10  cout<<endl;

	cout << d << endl;
	//cout << 10;
	//cout << d;

	//d.operator<<(cout);
	//d << cout;
	system("pause");
	return 0;
}
#endif

//
//
//
//class Date
//{
//	friend class Time;//声明时间类为日期类的友元类，则在时间类中就可以直接访问日期类中的私有成员变量
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Time
//{
//
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{
//		cout << this->_hour << endl;
//	}
//
//	void TestFriendClass()
//	{
//		Date d;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//void Test()
//{
//	Time t;
//	t.TestFriendClass();
//
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}