#include"Singleton.h"
#include<stdlib.h>


//����ģʽ

//����ģʽ ��������ʱ�ʹ�������
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

//����ģʽ �õ�ʱ���ڴ�������

#include<mutex>
class Singleton
{
public:
	static volatile Singleton* GetInstrance()
	{
		if (nullptr == m_Pins)//��ֹ�̶߳���
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
	static volatile Singleton* m_Pins;//volatile ��֤��������������Ż� 
	static mutex m_mutex;//��֤�̰߳�ȫ
	static GC m_gc;//����ʼʱ���ɶ��󣬳����˳�ʱ���ٶ���
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