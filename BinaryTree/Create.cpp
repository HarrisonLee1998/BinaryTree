#include<iostream>
#include "Create.h"
using namespace std;

/*
	规定输入非正整数即为NULL
*/
node* create()
{
	cout << "'请输入节点的值（输入非正整数代表NULL）" << endl;
	int value;
	cin >> value;
	if (value <= 0)
		return NULL;
	node* root = new node;
	root->value = value;
	cout << "创建"<<value<<"的左子节点" << endl;
	root->lchild = create();
	cout << "创建" << value << "的右子节点" << endl;
	root->rchild = create();
	return root;
}