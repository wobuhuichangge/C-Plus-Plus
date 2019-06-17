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
			//不能在此处标记双亲
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
		//data不在二叉搜索树中，无法删除
		if (nullptr == pCur)
			return false;
		//只有右孩子
		if (nullptr == pCur->_pLeft)
		{
			//待删除节点为根节点
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
		//只有左孩子
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
		//左右孩子均存在
		//找一个替代节点（左右都可以，在这里我们找右子树中的替代节点(找最左侧)）
		else
		{
			pNode pFirstOfIn = pCur->_pRight;

			//parent标记pFirstOfIn的双亲， 可能为空 
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
	void _Destroy(pNode& pRoot)//改变指针的指向
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