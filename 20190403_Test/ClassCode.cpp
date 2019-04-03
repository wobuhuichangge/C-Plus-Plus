
#include<string.h>
#include <crtdbg.h>
#include<stdlib.h>
#include"ClassCode.h"

#if 0
//�������Ͳ��漰��Դ����
class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};


void TestFunc()
{
	//û��
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//delete p1;
    // ����
	//Test* p2 = (Test*)malloc(sizeof(Test));
	//delete[] p2;
	


	//Test* p3 = new Test;
	//free(p3);
	

	// ����
	//Test* p4 = new Test;
	//delete[] p4;

	//// �ڴ�й©+����
	//Test* p5 = new Test[10];
	//free(p5);

	// ����+�ڴ�й©
	Test* p6 = new Test[10];
	delete p6;
}

int main()
{
	TestFunc();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
#endif

#if 0
//���������漰��Դ����
class Test
{
public:
	Test()
	{
		_ptr = new int[10];
	}

	~Test()
	{
		delete[] _ptr;
		_ptr = nullptr;
	}

private:
	int* _ptr;
};

void TestFunc()
{
	// ����
/*	 	Test* p1 = (Test*)malloc(sizeof(Test));
	 	delete p1;*///û�д����ö���ֻ���������ڴ棬����������delete������������ʱ thisָ��Ϊ���ֵ�����б���

	// ����
	 	//Test* p2 = (Test*)malloc(sizeof(Test));
	 	//delete[] p2;

	// �ڴ�й©
	 	//Test* p3 = new Test;
	 	//free(p3);
	 	//_CrtDumpMemoryLeaks();

	// ����
	 	//Test* p4 = new Test;
	 	//delete[] p4;

	// �ڴ�й©+����
	// 	Test* p5 = new Test[10];
	// 	free(p5);

	// ����+�ڴ�й©
	// 	Test* p6 = new Test[10];
	// 	delete p6;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

//class Test
//{
//public:
//	Test()
//	{
//		cout << "Test():" << this << endl;
//	}
//
//	 	~Test()
//	 	{
//	 		cout << "~Test():" << this << endl;
//	 	}
//
//private:
//	int _data;
//};
//
//int main()
//{
//	Test* pt = new Test;
//	delete pt;
//
//	Test* pt = new Test;
//	delete[] pt;
//
//	return 0;
//}

#if 0
// ����ģʽ����������ʱ�����󴴽���
// 
class Singleton
{
public:
	static Singleton& GetInstrance()
	{
		return m_ins;
	}

private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton m_ins;
};

Singleton Singleton::m_ins;



int main()
{
	Singleton& s = Singleton::GetInstrance();
	cout << &s << endl;

	s = Singleton::GetInstrance();
	cout << &s << endl;

	s = Singleton::GetInstrance();
	cout << &s << endl;

	s = Singleton::GetInstrance();
	cout << &s << endl;
	system("pause");
	return 0;
}
#endif


#if 1
#include <mutex>
#include <thread>

// ����ģʽ: ��һ��ʹ��ʱ�������ӳټ���
// �����̰߳�ȫ��---���ܱ�ֻ֤�ܴ���һ������
// ��������߳�����----˫���
class Singleton
{
public:
	static volatile Singleton* GetInstrance()
	{
		if (nullptr == m_pIns)
		{
			m_mutex.lock();
			if (nullptr == m_pIns)
				m_pIns = new Singleton;
			m_mutex.unlock();
		}

		return m_pIns;
	}

	class GC
	{
	public:
		~GC()
		{
			if (m_pIns)
			{
				delete m_pIns;
				m_pIns = nullptr;
			}
		}
	};

private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;
	static volatile Singleton* m_pIns;
	static mutex m_mutex;
	static GC m_gc;
};

volatile Singleton* Singleton::m_pIns = nullptr;
mutex Singleton::m_mutex;
Singleton::GC m_gc;



void ThreadFunc()
{
	cout << Singleton::GetInstrance() << endl;
}

void TestSingleton()
{
	thread  t1(ThreadFunc);
	thread  t2(ThreadFunc);
	thread  t3(ThreadFunc);
	thread  t4(ThreadFunc);
	thread  t5(ThreadFunc);
	thread  t6(ThreadFunc);
	thread  t7(ThreadFunc);
	thread  t8(ThreadFunc);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();

}

int main()
{
	TestSingleton();
	system("pause");
	return 0;
}
#endif
