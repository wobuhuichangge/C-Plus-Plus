#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;
#if 0
struct Student
{
	void InitStudent(char* name, int age, char* gender)
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_gender, gender);
	}
	void PrintStudent()
	{
		cout << _name << "-" << _age << "-" << _gender << endl;
	}

	char _name[20];
	int _age;
	char _gender[3];
};

int main()
{
	Student s1, s2;
	s1.InitStudent("Peter", 30, "��");
	s1.PrintStudent();

	s2.InitStudent("Ross", 21, "Ů");
	s2.PrintStudent();
	system("pause");
	return 0;
}
#endif
//������ֶ��巽ʽ

//��һ�� �������Ͷ���ȫ������������
//�ڶ��� �������Ͷ���ֿ� �������������ַ�����

#if 0
class Student
{
public:
	void InitStudent(char* name, int age, char* gender)
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_gender, gender);
	}
	void PrintStudent()
	{
		cout << _name << "-" << _age << "-" << _gender << endl;
	}

	char _name[20];
	int _age;
	char _gender[3];
};

int main()
{
	Student s1, s2;
	s1.InitStudent("Peter", 30, "��");
	s1.PrintStudent();

	s2.InitStudent("Ross", 21, "Ů");
	s2.PrintStudent();

	cout << sizeof(s1) << endl;//28
	system("pause");
	return 0;
}
#endif

#if 0
class A
{
public:
	void TestFunc()
	{}


	int _a;
	char _b;
};

class B
{
public:
	void TestFunc()
	{}
};

// ����
class C
{};


// ���С�ļ��㷽ʽ�����Ա���������� + �ڴ����
// ��ṹ���Сһģһ��

// �����û�����Ա��������Ĵ�СΪһ���ֽ�
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	system("pause");
	//C c1, c2, c3;
	//cout << offsetof(A, _b) << endl;
	return 0;
}
#endif

//this ָ�� ������Ϊ��Student* const 
//���� this ָ���ָ���ܱ��޸�

//void Display()---->void Display(Date* this)
//{
//	cout << _year << endl;// ---->cout << this->_year << endl;
//}

#if 0
class Test
{
public:
	void TestFunc()
	{
		//cout << &this << endl;
		Test* const& p = this;
		cout << &p << endl;
	}

public:
	int _t;
};

int main()
{
	int* p = nullptr;
	int*& q = p;

	cout << &q << endl;
	cout << &p << endl;

	Test t;
	t.TestFunc();
	cout << &t << endl;
	system("pause");
	return 0;
}
#endif
#if 0
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = NULL;
	p->PrintA();
	p->Show();
	system("pause");
	return 0;
}
#endif
#if 0
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
};
void Test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
}
int main()
{
	Test();
	system("pause");
	return 0;
}
#endif
//���������
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

//Date(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//	cout << "Date(Date&):" << this << endl;
//}
////d1 = d2 = d3
Date& operator=(const Date& d)//�����ָ��Ļ����Ͳ���ʹ��d.+��Ա�Ĳ���
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//�����������this ����ֵ����ҪΪDate* 
}
Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	cout << "Date(Date&):" << this << endl;
}


// *this + day
// ���⣺����֮��Ľ�������ǷǷ����ڣ�����
Date operator+(int day)
{
	Date temp(*this);
	temp._day += day;
	return temp;
}



// ���ȷ�������
// ���������Ƿ����---->������Ϊ�����ķ���ֵ���ͣ����ܷ��غ���ջ�ϵĿռ�
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
//ǰ��++
//d2 = ++d1
Date& operator++()
{
	_day += 1;
	return *this;
}
//d2 = d1++ ����++
Date operator++(int)//������һ��int������ǰ��++
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

// �������طǷ������----
// Date operator@(int a)
// {
// 	Date d;
// 	return d;
// }

#endif


#if 0

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
	d3 = d1;//d3.operator=(d1);
	d1 = d2 = d3;//d1.operator=(d2.operator=(d3));
	if (d3 == d1);

	Date& d4 = d3;

	d4 = d3;
}

int main()
{
	TestDate();
	system("pause");
	return 0;
}
#endif


