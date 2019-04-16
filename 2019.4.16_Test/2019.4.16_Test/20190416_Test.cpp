#include"20190416_Test.h"
#include <string>

#if 0
int main()
{
	string s("hello");
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	//s.resize(10, '#');
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	//s.resize(13);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	//s.resize(20, '$');
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	//s.resize(18);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	//s.resize(13);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//cout << s << endl;
	
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello");
	cout << s.capacity() << endl;
	s.reserve(100);
	cout << s.capacity() << endl;
	s.reserve(50);
	cout << s.capacity() << endl;

	s[0] = 'H';
	
	cout << s.at(4)<<endl;
	cout << s << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	//string s1("hello");
	//s1 += ' ';
	//s1 += "world";
	//cout << s1 << endl;

	//string s2("!!!");
	//s1 += s2;
	//cout << s1 << endl;

	system("pause");
	return 0;
}
#endif

#if 0
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	s.reserve(100);
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

int main()
{
	TestPushBack();
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	//string s("hello");
	//s.assign("world!");
	//cout << s << endl;
	//string s1 = s.substr(0, 5);
	//cout << s1 << endl;


	//string s("F:\\test\\20190416Test.cpp");
	//string strFilePostFix;
	//size_t pos = s.rfind('.');
	//strFilePostFix = s.substr(pos, s.size() - pos);
	//cout << strFilePostFix << endl;

	string s;
	getline(cin, s);
	cout << s << endl;
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t pos = url.find("://") + 3;
	string str = url.substr(pos, url.find('/', pos) - pos);
	cout << str << endl;

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello world");
	reverse(s.begin(), s.end());
	cout << s << endl;
	system("pause");
	return 0;
}
#endif
