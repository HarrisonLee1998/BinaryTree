#include <iostream>
#include "Rebuild.h"

using namespace std;

int* rb_in, * rb_pre, * rb_post;


// �涨�������������
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
	printf("����������(1), ����ǰ�����(2)\n");
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
//������ͺ��򹹽�������
node* buildFromInAndPost(int inL, int inR, int postL, int postR)
{
	/*
		1. ȡ���������е����һλ, ��ǰ������ͷ�ڵ�
		2. �������������Ҹõ�������ͷ�ڵ���±�Ϊindex( inL<=index<=inR, ���ҽ�����ǰ�ڵ�ΪҶ�ӽڵ�ʱ�Ⱥų���)
		3. inL~index����Ϊ������, index~inR����Ϊ������, ע�ⲻ����index
		4. inL>inRʱ�����ݹ�, ʵ���ϵ�inL==inRʱ, in[inL]ΪҶ�ӽ��
	*/
	if (inL > inR) return NULL;
	node* root=new node;
	root->value = rb_post[postR];
	// �������������Ҹ��ڵ�
	int left = 0; //��¼�������������ĸ���
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

//�������ǰ�򹹽�������
node* buildFromInAndPre(int inL, int inR, int preL, int preR)
{
	/*
		1. �ҵ�pre[preL], ���ǵ�ǰ��������ĸ��ڵ�
		2. �������������ҵ����ڵ��λ��, ��߼�Ϊ������, �ұ߼�Ϊ������
		3. inL>inRʱ�ݹ����
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