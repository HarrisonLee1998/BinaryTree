#pragma once

#include "BinaryTree.h"

void init(int);

/*
	注意下面这两种方法都必须使用正确的序列, 否则会出现异常。
*/

/*
测试用例1
10
3 4 2 6 5 7 1 9 0 8
1
4 3 6 7 5 2 0 9 8 1

测试用例2
5
1 0 4 3 2
1
0 1 2 3 4
*/
//从中序和后序构建二叉树
node* buildFromInAndPost(int inL, int inR, int postL, int postR);


/*
测试用例1
10
3 4 2 6 5 7 1 9 0 8
2
1 2 3 4 5 6 7 8 9 0

测试用例2
5
3 2 4 1 0
2
0 1 2 3 4
*/
//从中序和前序构建二叉树
node* buildFromInAndPre(int inL, int inR, int postL, int postR);