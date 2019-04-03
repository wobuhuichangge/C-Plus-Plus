
#include<string.h>
#include <crtdbg.h>
#include<stdlib.h>
#include"ClassCode.h"

#if 0
//内置类型不涉及资源管理
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
	//没事
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//delete p1;
    // 崩溃
	//Test* p2 = (Test*)malloc(sizeof(Test));
	//delete[] p2;
	


	//Test* p3 = new Test;
	//free(p3);
	

	// 崩溃
	//Test* p4 = new Test;
	//delete[] p4;

	//// 内存泄漏+崩溃
	//Test* p5 = new Test[10];
	//free(p5);

	// 崩溃+内存泄漏
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
//内置类型涉及资源管理
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
	// 崩溃
/*	 	Test* p1 = (Test*)malloc(sizeof(Test));
	 	delete p1;*///没有创建好对象，只是申请了内存，所有这里用delete调用析构函数时 this指针为随机值，所有崩溃

	// 崩溃
	 	//Test* p2 = (Test*)malloc(sizeof(Test));
	 	//delete[] p2;

	// 内存泄漏
	 	//Test* p3 = new Test;
	 	//free(p3);
	 	//_CrtDumpMemoryLeaks();

	// 崩溃
	 	//Test* p4 = new Test;
	 	//delete[] p4;

	// 内存泄漏+崩溃
	// 	Test* p5 = new Test[10];
	// 	free(p5);

	// 崩溃+内存泄漏
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
// 饿汉模式：程序启动时将对象创建好
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

// 懒汉模式: 第一次使用时创建，延迟加载
// 不是线程安全的---不能保证只能创建一个对象
// 容易造成线程阻塞----双检测
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
