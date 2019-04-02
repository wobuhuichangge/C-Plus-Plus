#define _CRT_SECURE_NO_WARNINGS 1
#include"20190402_Test.h"

#if 0
//针对链表的节点ListNode通过重载类专属 operator new/ operator delete，实现链表节
//点使用内存池申请和释放内存，提高效率。
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
// 定位new：在已经存在的空间上执行构造函数
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
	// new(空间地址) Test;
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

	//C++98中 
	//1.只声明，不实现。因为实现可能会很麻烦，而本身不需要实现
	//2.声明成私有 类外禁止访问
	HeapOnly(const HeapOnly&);

	//C++11中
	// 告诉编译器：删除拷贝构造函数
	HeapOnly(const HeapOnly&) = delete;
};
int main()
{
	//HeapOnly d1; 无法访问。
	HeapOnly* p = HeapOnly::GetObject();

	//HeapOnly o(*p);
	return 0;
}
#endif

#if 0
class StackOnly
{
public:
	// 可能会在返回值
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
	//StackOnly* ps = new StackOnly; //出错。无法访问构造函数 
	StackOnly s1(StackOnly::GetObject());
	StackOnly s2(s1);
	return 0;
}
#endif

#if 0
//使不能在堆上申请空间
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

//StackOnly s;但是可以在数据段创建对象

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