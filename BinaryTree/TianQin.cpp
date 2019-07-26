#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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

bool compare_value(node* a, node* b)
{
	return a->value < b->value; //特别注意，这里是小于而不是大于，因为节点排序是按照权值的从小到大
}
void create_huffman_tree()
{
	int weight[] = { 2,5,7,9,13 };
	vector<node*>nodes;
	//开始构造哈夫曼二叉树
	node* tmp1, * tmp2, * sum;
	for (int i = 0; i < sizeof(weight) / sizeof(int); ++i)
	{
		tmp1 = new node;
		tmp1->value = weight[i];
		tmp1->lchild = NULL;
		tmp1->rchild = NULL;
		nodes.push_back(tmp1);
	}
	while (nodes.size() > 1)
	{
		sort(nodes.begin(),nodes.end(),compare_value);
		tmp1 = nodes[0];
		tmp2 = nodes[1];
		nodes.erase(nodes.begin(),nodes.begin()+2); //移除旧元素
		sum = new node;
		sum->value = tmp1->value + tmp2->value;
		sum->lchild = tmp1;
		sum->rchild = tmp2;
		tmp1->parent = sum;
		tmp2->parent = sum;
		sum->parent = NULL;
		nodes.push_back(sum);
	}

	//构造完毕，开始计算带权路径
	int WPL=0;
	stack<node*>s;
	s.push(nodes[0]);
	while (!s.empty())
	{
		tmp1 = s.top();
		s.pop();
		if (tmp1->lchild == NULL && tmp1->rchild == NULL)
		{
			int level=0;
			int value = tmp1->value;
			while (tmp1 != NULL)
			{
				tmp1 = tmp1->parent;
				++level;
			}
			WPL += (level-1)* value;
		}
		else
		{
			s.push(tmp1->lchild);
			s.push(tmp1->rchild);
		}
	}
	cout << WPL << endl;
}