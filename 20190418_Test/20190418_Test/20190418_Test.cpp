#include"20190418_Test.h"

//翻转字符串
#if 0
class Solution
{
public:
	string reverseString(string s)
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
};

int main()
{
	Solution S;
	string s("hello");
	s = S.reverseString(s);
	cout << s << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello!");
	reverse(s.begin(), s.end());
	cout << s << endl;
	system("pause");
	return 0;
}
#endif

//找字符串中第一个只出现一次的字符
#if 0
class Solution
{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i < size; i++)
		{
			if (1 == count[s[i]])
				return i;
		}
		return -1;
	}

};

int main()
{
	Solution S;
	string s("jgweudanvoiqwruhfalkjsdiuhge");
	int i = S.firstUniqChar(s);
	cout << i << endl;
	system("pause");
	return 0;
}
#endif

//字符串里面最后一个单词的长度
#if 0
int main()
{
	string s;
	getline(cin, s);
	size_t pos = s.rfind(' ')+1;
	cout << s.size() - pos << endl;
	system("pause");
	return 0;
}
#endif

//验证一个字符串是否是回文(只考虑数字字符或字母)
#if 0
class Solution
{
public:
	bool IsNumberOrLetter(char c)
	{
		if (c >= '0'&&c <= '9' ||
			c >= 'a'&&c <= 'z' ||
			c >= 'A'&&c <= 'Z')
			return true;
		return false;
	}
	bool isPalindrome(string s)
	{
		if (s.empty())
			return true;
		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();//转化为char
		while (begin < end)
		{
			while (begin != end)
			{
				if (IsNumberOrLetter(s[begin]))
					break;
				++begin;
			}
			while (begin < end)
			{
				if (IsNumberOrLetter(s[end]))
					break;
				--end;
			}
			if (begin < end)
			{
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				++begin;
				--end;
			}
		}
		return true;
		
	}

};

int main()
{
	string s("A man,a plan,a canal:Panama");
	Solution S;
	cout << S.isPalindrome(s) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
class Solution
{
public:
	string addStrings(string s1, string s2)
	{
		int LSize = s1.size();
		int RSize = s2.size();
		if (LSize < RSize)
		{
			s1.swap(s2);
			swap(LSize, RSize);
		}
		string strRet;
		strRet.reserve(LSize + 1);

		char cRet = 0;
		char cstep = 0;
		for (int i = 0; i < LSize; ++i)
		{
			cRet = s1[LSize - i - 1] - '0' + cstep;
			cstep = 0;

			if (i < RSize)
			{
				cRet += s2[RSize - i - 1] - '0';
			}
			if (cRet >= 10)
			{
				cRet -= 10;
				cstep = 1;
			}
			strRet += cRet + '0';
		}
		if (cstep)
		{
			strRet += '1';

		}
		reverse(strRet.begin(), strRet.end());
		return strRet;
	}
};

int main()
{
	string s1("867");
	string s2("427");
	Solution S;
	cout << S.addStrings(s1, s2) << endl;
	system("pause");
	return 0;
}
#endif