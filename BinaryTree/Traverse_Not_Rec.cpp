#include <iostream>
#include<stack>
#include<queue>
#include "Traverse_Not_Rec.h"
using namespace std;

//�ǵݹ�ǰ�����
void preorder_not_rec(node* root)
{
	stack<node*>s;
	s.push(root);
	node* temp;
	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		cout << temp->value;
		if (temp->rchild != NULL)
		{
			s.push(temp->rchild);
		}
		if (temp->lchild != NULL)
		{
			s.push(temp->lchild);
		}
	}
}

//�ǵݹ��������
void inorder_not_rec(node* root)
{
	stack<node*>s;
	s.push(root);
	node* temp=root->lchild;
	/*
	ע�⣬�����һ��temp!=NULL������
	�ڱ�������ڵ���������󣬾ͻ�������ڵ㣬��ʱջ�о�Ϊ���ˣ�������ʱ����������ֹ����
	����һ��temp!=NULL�����������������ڵ�ʱ����ʱtemp��ֵΪ���ڵ�����ӽڵ�
	�͸����Ƿ�������������ж��Ƿ��������
	*/
	while (!s.empty()||temp!=NULL)
	{
		while (temp != NULL)
		{
			s.push(temp);
			temp = temp->lchild;
		}
		temp = s.top();
		cout << temp->value;
		s.pop();
		temp = temp->rchild;
	}
}

//�ǵݹ�������
void postorder_not_rec(node* root)
{
	stack<node*>s1;
	stack<node*>s2;
	node* temp;
	s1.push(root);
	while (!s1.empty())
	{
		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if (temp->lchild != NULL)
		{
			s1.push(temp->lchild);
		}
		if (temp->rchild != NULL)
		{
			s1.push(temp->rchild);
		}
	}
	while (!s2.empty())
	{
		temp = s2.top();
		s2.pop();
		cout << temp->value;
	}
}

//�������

void level_traverse(node* root)
{
	queue<node*>q;
	q.push(root);
	node* temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->value;
		if (temp->lchild != NULL)
			q.push(temp->lchild);
		if (temp->rchild != NULL)
			q.push(temp->rchild);
	}
}