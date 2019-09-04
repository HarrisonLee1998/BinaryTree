#include <iostream>
#include "Rebuild.h"

using namespace std;

int* rb_in, * rb_pre, * rb_post;


// 规定先输入中序遍历
void  init(int n)
{
	rb_in = (int*)malloc(sizeof(int)*n);
	rb_post = (int*)malloc(sizeof(int) * n);
	rb_pre = (int*)malloc(sizeof(int) * n);
	if (rb_in == NULL || rb_post == NULL || rb_pre == NULL) return;
	for (int i = 0; i < n; ++i)
	{
		cin >> rb_in[i];
	}
	printf("输入后序遍历(1), 输入前序遍历(2)\n");
	int flag=1;
	cin >> flag;
	if (flag == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> rb_post[i];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> rb_pre[i];
		}
	}
}
//从中序和后序构建二叉树
node* buildFromInAndPost(int inL, int inR, int postL, int postR)
{
	/*
		1. 取后序序列中的最后一位, 当前子树的头节点
		2. 在中序序列中找该到子树的头节点的下标为index( inL<=index<=inR, 当且仅当当前节点为叶子节点时等号成立)
		3. inL~index部分为左子树, index~inR部分为右子树, 注意不包含index
		4. inL>inR时结束递归, 实际上当inL==inR时, in[inL]为叶子结点
	*/
	if (inL > inR) return NULL;
	node* root=new node;
	root->value = rb_post[postR];
	// 在中序序列中找根节点
	int left = 0; //记录子树的左子树的个数
	for (int i = inL; i <=inR; ++i)
	{
		if (rb_in[i] == root->value)
			break;
		else ++left;
	}
	root->lchild = buildFromInAndPost(inL, inL+left-1, postL, postL+left-1);
	root->rchild = buildFromInAndPost( inL + left+1, inR, postL + left, postR-1);
	return root;
}

//从中序和前序构建二叉树
node* buildFromInAndPre(int inL, int inR, int preL, int preR)
{
	/*
		1. 找到pre[preL], 这是当前这颗子树的根节点
		2. 在中序序列中找到根节点的位置, 左边即为左子树, 右边即为右子树
		3. inL>inR时递归结束
	*/
	if (inL > inR) return NULL;
	node* root = new node;
	root->value = rb_pre[preL];
	int left = 0;
	for (int i = inL; i < inR; ++i)
	{
		if (rb_in[i] == root->value) break;
		else ++left;
	}
	root->lchild = buildFromInAndPre(inL, inL+left-1 , preL+1, preL+left);
	root->rchild = buildFromInAndPre(inL+left+1, inR, preL+left+1, preR);
	return root;
}