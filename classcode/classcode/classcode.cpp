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
