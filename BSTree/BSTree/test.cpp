#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"BSTree.hpp"

using namespace std;

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : a)
		t.Insert(e);
	t.InOrder();

	BSTNode<int>* pCur = t.Find(2);
	if (pCur)
		cout << "2 is in" << endl;
	else
		cout << "2 is not in" << endl;
	t.InOrder();

	//ֻ���Һ��ӣ�����˫�׵��Һ���
	t.Erase(8);
	t.InOrder();

	t.Erase(0);
	//ֻ���Һ��� ������˫�׵�����
	t.Erase(1);
	t.InOrder();

	t.Erase(5);
	t.InOrder();
}

int main()
{
	TestBSTree();
	system("pause");
	return 0;
}