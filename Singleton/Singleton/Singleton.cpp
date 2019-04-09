#include"Singleton.h"
#include<stdlib.h>


//单例模式

//饿汉模式 程序运行时就创建对象
#if 0
class Singleton
{
public:
	static Singleton& GetInstrance()
	{
		return m_ins;
	}

private:
	Singleton()
	{};
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

//懒汉模式 用的时候在创建对象

#include<mutex>
class Singleton
{
public:
	static volatile Singleton* GetInstrance()
	{
		if (nullptr == m_Pins)//防止线程堵塞
		{
			m_mutex.lock();
			if (nullptr == m_Pins)
			{
				m_Pins = new Singleton;
			}
			m_mutex.unlock();
		}

		return m_Pins;
	}
	class GC
	{
	public:
		~GC()
		{
			if (m_Pins == nullptr)
			{
				delete m_Pins;

			}
			m_Pins = nullptr;
		}
	};
private:
	Singleton()
	{};
	Singleton(const Singleton&) = delete;
	static volatile Singleton* m_Pins;//volatile 保证编译器不会进行优化 
	static mutex m_mutex;//保证线程安全
	static GC m_gc;//程序开始时生成对象，程序退出时销毁对象
};
 volatile Singleton* Singleton::m_Pins = nullptr;
 mutex Singleton::m_mutex;
Singleton::GC m_gc;

int main()
{
	
	Singleton::GetInstrance();
	Singleton::GetInstrance();
	system("pause");
	return 0;
}