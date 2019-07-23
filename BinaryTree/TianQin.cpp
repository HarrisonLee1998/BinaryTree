#include<iostream>
#include<stack>
#include "TianQin.h"

using namespace std;

/*
������÷ǵݹ������Ȼ���ж��Ƿ�ΪҶ�ӽڵ㣬����ǵĻ��Ͱ��к���ʹ������
*/
node* connect_leaves(node *root)
{
	node* head = NULL;
	node* tail = NULL;
	node * temp;
	stack<node*>s;
	bool isFirst=true;
	s.push(root);
	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		if (temp->lchild == NULL && temp->rchild == NULL)
		{
			if (isFirst)
			{
				head = temp;
				tail = temp;
				isFirst = false;
			}
			else
			{
				tail->rchild = temp;
				tail = temp;
			}
		}
		if (temp->rchild != NULL)
			s.push(temp->rchild);
		if (temp->lchild != NULL)
			s.push(temp->lchild);
	}
	return head;
}