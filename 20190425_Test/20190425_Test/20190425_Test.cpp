#include<stdlib.h>
#include"20190425_Test.h"

int main()
{
#if 0
	//vector()
	vector<int> v1;
	//vector(size_type n,const value_type& val = value_type()
	vector<int> v2(10, 5);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//vector(InputIterator first,InputIterator last)
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	vector<int> v4(v3);
	v1 = v2;

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	for (auto e : v)//范围for
		cout << e << " ";
	cout << endl;

	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.resize(20, 9);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)//范围for
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)//范围for
		cout << e << " ";
	cout << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)//范围for
		cout << e << " ";
	cout << endl;

	v.reserve(10); //如果新容量小于原来的容量 
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
#endif

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.front() << endl;
	cout << v.back() << endl;

	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.begin(), 0);
	cout << v[5] << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.assign(10, 5);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	string s("hello bit");
	vector<char> vv;
	vv.assign(s.begin(), s.end());
	for (auto e : vv)
		cout << e << " ";
	cout << endl;

	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	foo.reserve(100);
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	system("pause");
	return 0;
}
