#include <iostream>
#include<stack>
#include<queue>
#include "Traverse_Not_Rec.h"
using namespace std;

//非递归前序遍历
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

//非递归中序遍历
void inorder_not_rec(node* root)
{
	stack<node*>s;
	s.push(root);
	node* temp=root->lchild;
	/*
	注意，这里加一个temp!=NULL的条件
	在遍历完根节点的左子树后，就会遍历根节点，此时栈中就为空了，但是这时还不能种终止遍历
	即加一个temp!=NULL的条件，遍历到根节点时，此时temp的值为根节点的右子节点
	就根据是否存在右子树来判断是否继续遍历
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

//非递归后序遍历
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

//层序遍历

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