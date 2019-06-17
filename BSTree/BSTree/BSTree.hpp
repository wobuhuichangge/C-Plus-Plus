#pragma once

#include<iostream>

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};


template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* pNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree()
	{
		_Destroy(_pRoot);
	}

	BSTNode<T>* Find(const T& data)
	{
		pNode pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				pCur = pCur->_pLeft;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		pNode pCur = _pRoot;
		pNode parent = nullptr;
		while (pCur)
		{
			parent = pCur;
			if (data > pCur->_data)
				pCur = pCur->_pRight;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				return false;
		}

		pCur = new Node(data);
		if (data < parent->_data)
			parent->_pLeft = pCur;
		else
			parent->_pRight = pCur;

		return true;
	}

	bool Erase(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		pNode pCur = _pRoot;
		pNode parent = nullptr;
		while (pCur)
		{
			//�����ڴ˴����˫��
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				parent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				parent = pCur;
				pCur = pCur->_pRight;
			}
		}
		//data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		//ֻ���Һ���
		if (nullptr == pCur->_pLeft)
		{
			//��ɾ���ڵ�Ϊ���ڵ�
			if (pCur == _pRoot)
				_pRoot = pCur->_pRight;
			else
			{
				if (pCur == parent->_pLeft)
					parent->_pLeft = pCur->_pRight;
				else
					parent->_pRight = pCur->_pRight;
			}
		}
		//ֻ������
		else if (nullptr == pCur->_pRight)
		{
			if (pCur == _pRoot)
				_pRoot = pCur->_pLeft;
			else
			{
				if (pCur == parent->_pLeft)
					parent->_pLeft = pCur->_pLeft;
				else
					parent->_pRight = pCur->_pLeft;
			}
		}
		//���Һ��Ӿ�����
		//��һ������ڵ㣨���Ҷ����ԣ��������������������е�����ڵ�(�������)��
		else
		{
			pNode pFirstOfIn = pCur->_pRight;

			//parent���pFirstOfIn��˫�ף� ����Ϊ�� 
			parent = pCur;

			while (pFirstOfIn->_pLeft)
			{
				parent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->_pLeft;
			}

			pCur->_data = pFirstOfIn->_data;
			if (pFirstOfIn == parent->_pLeft)
			{
				parent->_pLeft = pFirstOfIn->_pRight;
			}
			else
				parent->_pRight = pFirstOfIn->_pRight;
			
			pCur = pFirstOfIn;
		}

		delete pCur;
		return true;
	}

	

	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}
private:
	void _InOrder(BSTNode<T>* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);

		}
		
	}

private:
	void _Destroy(pNode& pRoot)//�ı�ָ���ָ��
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			pRoot = nullptr;
		}
	}
	pNode _pRoot;
};