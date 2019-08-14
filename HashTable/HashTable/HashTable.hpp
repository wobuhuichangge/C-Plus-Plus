#pragma once

#include<iostream>

#include<vector>

//EMPTY表示此位置为空,EXIST表示此位置已经有元素,DELETE表示此位置元素已经删除
enum State{EMPTY,EXIST,DELETE};
template<class T>
class HashTable
{
	struct Elem
	{
		T _val;
		State _state;
	};

public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		, _size(0)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			_ht[i]._state = EMPTY;
		}
	}

	bool Insert(const T& val)
	{
		//检测底层空间是否充足
		//_CheckCapacity();

		size_t hashAddr = HashFunc(val);

		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val == val)
			{
				return false;
			}

			hashAddr++;
			//有可能会越界
			if (hashAddr == _ht.capacity())
			{
				hashAddr = 0;
			}
		}

		//插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}

	int Find(const T& val)
	{
		size_t hashAddr = HashFunc(val);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val == val)
				return hashAddr;

			hashAddr++;

			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}

		return -1;
	}

	bool Erase(const T& val)
	{
		int pos = Find(key);
		if (-1 != pos)
		{
			_ht[pos]._state = DELETE;
			_size--;
			return true;
		}

		return false;
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size
	}

	void Swap(HashTable<T>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
private:
	size_t HashFunc(const T& val)
	{
		return val% _ht.capacity();
	}
	
	void CheckCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)
		{
			HashTable<T, HF> newHt(GetNextPrime(ht.capacity()));
			for (size_t i = 0; i < _ht.capacity(); i++)
			{
				if (_ht[i]._state == EXIST)
					newHt.Insert(_ht[i]._val);
			}
		}
	}
private:
	vector<Elem> _ht;
	size_t _size;
};

template <class T>
void Test()
{
	HashTable<T> ht;
	ht.Insert(2); 
	ht.Insert(14);
	ht.Insert(5);
	ht.Insert(25);
	ht.Find(14);
	ht.Find(7);
	ht.Erase(5);
}