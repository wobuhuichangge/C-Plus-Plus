#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace bite
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(size_t n, char c)
			:_str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, c, _size);
			_str[_size] = '\0';
		}

		string(const char* pstr, size_t n)
		{
			size_t length = strlen(pstr);
			_size = length > n ? n : length;
			_capacity = _size;
			_str = new char[_capacity + 1];
			for (size_t i = 0; i < _size; ++i)
			{
				_str[i] = pstr[i];
				_str[_size] = '\0';
			}
		}

		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;

				_str = nullptr;
			}

		}

		//Iterator

		iterator begin()
		{
			return _str;
		}
		
		iterator end()
		{
			return _str + _size;
		}

		iterator rbegin()
		{
			return _str + _size;
		}

		iterator rend()
		{
			return _str;
		}

		//capacity

		size_t size()const
		{
			return _size;
		}

		size_t length()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		void resize(size_t newSize, char ch = char())
		{
			size_t oldSize = size();
			if (newSize < oldSize)
			{
				_size = newSize;
				_str[newSize] = '\0';
			}
			else
			{
				if (newSize > capacity())
				{
					size_t newCapacity = capacity() * 2;
					reserve(newCapacity);
				}

				memset(_str + _size, ch, newSize - oldSize);
				_size = newSize;
				_str[_size] = '\0';
			}
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > capacity())
			{
				char* pStr = new char[newCapacity + 1];
				strcpy(pStr, _str);
				delete[] _str;
				_str = pStr;
				_capacity = newCapacity;
			}
		}

		//Element access:

		char& operator[](size_t index)
		{
			assert(index < size());
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < size());
			return _str[index];
		}

		//Modifiers:

		string& operator+=(const string& s)
		{
			size_t leftByte = _capacity - _size;
			size_t totalByte = s.size();
			if (totalByte > leftByte)
			{
				reserve(totalByte + _size);
			}
			strcpy(_str + _size, s._str);
			_size += totalByte;
			return *this;
		}

		void append(size_t n, char ch)
		{
			size_t leftBytes = _capacity - _size;
			if (n > leftBytes)
			{
				reserve(n + _size);
			}
			memset(_str + _size, ch, n);
			_size += n;
			_str[_size] = '\0';

		}

		void push_back(char ch)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}



		//String operations:

		const char* c_str()const
		{
			return _str;
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;
			for (int i = pos; i >= 0; --i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}

		string strsub(size_t pos = 0, size_t n = npos)const
		{
			return string(_str + pos, n);
		}

		friend ostream& operator<<(ostream& _cout, const string& s)
		{
			_cout << s._str;
			return _cout;
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static const size_t npos;
	};
	const size_t string:: npos = -1;


}

void TestString()
{
	bite::string s1("hello");
	bite::string s2(10, 'a');
	bite::string s3("world", 5);
	bite::string s4(s3);

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	//cout << s1 << endl;

	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	s1.push_back(' ');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1 += s3;
	cout << s1.strsub(s1.rfind(' ') + 1) << endl;
	s1.resize(20, '!');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.resize(5);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.resize(10, '6');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.clear();
}

