#include<iostream>
#include "Create.h"
using namespace std;

/*
	�涨�������������ΪNULL
*/
node* create()
{
	cout << "'������ڵ��ֵ�����������������NULL��" << endl;
	int value;
	cin >> value;
	if (value <= 0)
		return NULL;
	node* root = new node;
	root->value = value;
	cout << "����"<<value<<"�����ӽڵ�" << endl;
	root->lchild = create();
	cout << "����" << value << "�����ӽڵ�" << endl;
	root->rchild = create();
	return root;
}