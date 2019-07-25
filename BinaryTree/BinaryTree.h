#pragma once

/*
	注意：下面有些属性可能只在某些例子中用到，而不是全部都会用到
*/
struct node
{
	int value;
	node* lchild;
	node* rchild;
	node* parent;
};