#include<iostream>
#include<stack>
#include "TianQin.h"

using namespace std;

/*
本题采用非递归遍历，然后判断是否为叶子节点，如果是的话就把有孩子使用起来
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
	将给定的--满二叉树--的前序遍历的结果转化为后序遍历
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
	int count = (end - begin) / 2; //左右子树分别的节点数
	convert_pre_to_post(seq, begin, begin+count-1);
	convert_pre_to_post(seq,begin+count,end-1);
}

//上面方法的测试方法
void test_convert()
{
	//为了方便，这里将前序遍历的结果写死
	int seq[] = { 1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}; //假设的前序遍历结果
	convert_pre_to_post(seq,0,sizeof(seq)/sizeof(int)-1);
	for (int i = 0; i < sizeof(seq) / sizeof(int); ++i)
	{
		cout << seq[i] << ' ';
	}
}

/*
	在root为根节点的二叉树中，寻找值为value的节点所在层号
	我的思路是在遍历的过程中，加一个参数为层数
	最开始，传入的root为整个二叉树的根节点，value为目标值，level==0
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