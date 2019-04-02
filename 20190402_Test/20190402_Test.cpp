#define _CRT_SECURE_NO_WARNINGS 1
#include"20190402_Test.h"

#if 0
//�������Ľڵ�ListNodeͨ��������ר�� operator new/ operator delete��ʵ�������
//��ʹ���ڴ��������ͷ��ڴ棬���Ч�ʡ�
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	ListNode(int data = 0)
		: _next(nullptr)
		, _prev(nullptr)
		, _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode(int):" << this << endl;
	}

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

int main()
{
	List l;
	return 0;
}
#endif

#if 0
void* operator new(size_t size, char* fileName, char* funcName, int lineNo)
{
	cout << fileName << "-" << funcName << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCTION__, __LINE__) 

int main()
{
	int* p = new int;
	delete p;

	return 0;
}
#endif

#if 0
// ��λnew�����Ѿ����ڵĿռ���ִ�й��캯��
class Test
{
public:
	Test(int data)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	// new(�ռ��ַ) Test;
	new(pt)Test(10);

	delete pt;

	int array[10];
	array[0] = 0;

	new(array + 3) int(3);
	return 0;
}
#endif

#if 0
class HeapOnly
{
public:
static HeapOnly* GetObject()
	{
		return new HeapOnly;
	}
	
private:
	HeapOnly()
	{}

	//C++98�� 
	//1.ֻ��������ʵ�֡���Ϊʵ�ֿ��ܻ���鷳����������Ҫʵ��
	//2.������˽�� �����ֹ����
	HeapOnly(const HeapOnly&);

	//C++11��
	// ���߱�������ɾ���������캯��
	HeapOnly(const HeapOnly&) = delete;
};
int main()
{
	//HeapOnly d1; �޷����ʡ�
	HeapOnly* p = HeapOnly::GetObject();

	//HeapOnly o(*p);
	return 0;
}
#endif

#if 0
class StackOnly
{
public:
	// ���ܻ��ڷ���ֵ
	static StackOnly GetObject()
	{
		//StackOnly s;
		return StackOnly();
	}

	StackOnly(const StackOnly&)
	{
		cout << "StackOnly(StackOnly&)" << endl;
	}

private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};




int main()
{
	//StackOnly* ps = new StackOnly; //�����޷����ʹ��캯�� 
	StackOnly s1(StackOnly::GetObject());
	StackOnly s2(s1);
	return 0;
}
#endif

#if 0
//ʹ�����ڶ�������ռ�
class StackOnly
{
public:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}

	StackOnly(const StackOnly&)
	{
		cout << "StackOnly(StackOnly&)" << endl;
	}

private:
	void* operator new(size_t size);
};

//StackOnly s;���ǿ��������ݶδ�������

int main()
{
	//StackOnly* ps = new StackOnly;
	StackOnly* ps = (StackOnly*)malloc(sizeof(StackOnly));
	new(ps)StackOnly;

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{}

private:
	Test(Test& t);
	Test& operator=(const Test&);

	//C++11
	//Test(Test& t) = delete;
	//Test& operator=(const Test&) = delete;
};


int main()
{
	Test t1;
	Test t2(t1);
	return 0;
}
#endif