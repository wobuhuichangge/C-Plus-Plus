#include"BlogCode.h"

#if 0
// ����--->
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
	// Date d4(); ���Ǵ�����һ�����󣬶���һ����������(û�в���������һ���������Ͷ���ĺ�������)
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
// �û�û����ʽ���壬���������ɵĹ��캯����Ĭ�ϵĹ��캯����һ�����޲ε�
// 
class Date
{
public:
	// Ĭ�Ϲ��캯��
	// �޲ι��캯��
	 	Date()
	 	{
	 		cout << "Date():" << this << endl;
	 	}

	// ȫȱʡ�Ĺ��캯��
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
	// Ĭ�ϵĹ��캯��ֻ�ܴ���һ��
	Date d1;
	//Date d2(2019, 3, 19);
	return 0;
}
#endif
#if 0
// ʲô����£��������Ż����ɣ�
// ����������о��Լ���Ҫ��ʱ��ͻ�����---->ʲô���Ǳ�������Ҫ��ʱ��
// �ĸ�������

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
	Date d1; // ������Ĺ��캯�� // Time()
	Date d2(d1);  // Time(Time&)--->�Ҹ�����λ��--->Date��Ŀ������캯����
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

	// �������캯��������ʽ�ṩ

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
// ʲô�����������
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

	// ǰ��++
	// d2 = ++d1
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// ����++
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
// const���Ա
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

	// �ɶ���д
	// Date* const  this
	void TestFunc1()
	{
		//this = nullptr;
		this->_day++;
	}

	// �ڸú����в����޸ĵ�ǰ����ĳ�Ա����
	// const����thisָ��
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
	const Date d2(2019, 3, 25); // ������d2�е����ݲ������޸�
	cout << &d2 << endl;
	//d2.TestFunc1();  // TestFunc1��Ա��������ͨ�ĳ�Ա�������ں����п����޸ĵ�ǰ����ĳ�Ա
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
// ���ܹ������˶��ٸ�����
// �����ı���----���ܰ�����ÿ�������У�Ӧ�������ж�����
// 1. ʹ��ȫ�ֱ���---->����---ȱ�ݣ�����ȫ
//int g_count = 0;

// ��ͨ��Ա����                static��Ա����
// �����ڳ�ʼ���б��г�ʼ��         ����
// ÿ�������ж�����             ֻ��һ�ݣ�û�а����ھ���Ķ����У������ж������
// ����ͨ���������             ����ͨ������ֱ�ӷ��� || Ҳ����ͨ��������������ֱ�ӷ���
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
	// ��Ԫ����
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
//	friend class Time;//����ʱ����Ϊ���������Ԫ�࣬����ʱ�����оͿ���ֱ�ӷ����������е�˽�г�Ա����
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