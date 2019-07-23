#include <iostream>
#include "Traverse_Rec.h"
using namespace std;

//递归前序遍历
void preorder_rec(node* root)
{
	if (root == NULL)
		return;
	cout << root->value;
	preorder_rec(root->lchild);
	preorder_rec(root->rchild);
}
//递归前序遍历
void inorder_rec(node* root)
{
	if (root == NULL)
		return;
	inorder_rec(root->lchild);
	cout << root->value;
	inorder_rec(root->rchild);
}
//递归后序遍历
void postorder_rec(node* root)
{
	if (root == NULL)
		return;
	postorder_rec(root->lchild);
	postorder_rec(root->rchild);
	cout << root->value;
}