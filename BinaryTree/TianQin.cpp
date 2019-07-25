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

void construct_parent(node* root, node*parent)
{
	if (root == NULL)
		return;
	root->parent = parent;
	construct_parent(root->lchild, root);
	construct_parent(root->rchild,root);
}
void print_path(node* root)
{
	if (root == NULL)
		return;
	node* temp;
	temp = root;
	int  i = 0;
	while (temp != NULL)
	{
		if (i != 0)
			cout << "->";
		cout << temp->value;
		temp = temp->parent;
		++i;
	}
	cout << endl;
	print_path(root->lchild);
	print_path(root->rchild);
}

/*
	��������--��������--��ǰ������Ľ��ת��Ϊ�������
*/
void convert_pre_to_post(int * seq,int begin,int end)
{
	if (end ==begin)
		return;
	int head = seq[begin];
	for (int i = begin; i <end; ++i)
	{
		seq[i] = seq[i + 1];
	}
	seq[end] = head;
	int count = (end - begin) / 2; //���������ֱ�Ľڵ���
	convert_pre_to_post(seq, begin, begin+count-1);
	convert_pre_to_post(seq,begin+count,end-1);
}

//���淽���Ĳ��Է���
void test_convert()
{
	//Ϊ�˷��㣬���ｫǰ������Ľ��д��
	int seq[] = { 1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}; //�����ǰ��������
	convert_pre_to_post(seq,0,sizeof(seq)/sizeof(int)-1);
	for (int i = 0; i < sizeof(seq) / sizeof(int); ++i)
	{
		cout << seq[i] << ' ';
	}
}

/*
	��rootΪ���ڵ�Ķ������У�Ѱ��ֵΪvalue�Ľڵ����ڲ��
	�ҵ�˼·���ڱ����Ĺ����У���һ������Ϊ����
	�ʼ�������rootΪ�����������ĸ��ڵ㣬valueΪĿ��ֵ��level==0
*/
void get_level_number(node* root, int value, int level)
{
	if (root == NULL)
		return;
	if (root->value == value)
	{
		cout << level << endl;
	}
	get_level_number(root->lchild,value,level+1);
	get_level_number(root->rchild,value,level+1);
}