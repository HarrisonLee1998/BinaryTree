// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Create.h"
#include "Traverse_Rec.h"
#include "Traverse_Not_Rec.h"

using namespace std;

void test_traverse();

int main()
{
	test_traverse();
	return 0;
}

/*
测试二叉树的各种遍历算法
包括：前序、中序、后序、层序的递归和非递归实现方案
*/
void test_traverse()
{
	node* root = create();
	cout << "递归前序遍历为：" << endl;
	preorder_rec(root);
	cout << endl;
	cout << "递归中序遍历为：" << endl;
	inorder_rec(root);
	cout << endl;
	cout << "递归后序遍历为：" << endl;
	postorder_rec(root);
	cout << endl;
	cout << "非递归前序遍历为：" << endl;
	preorder_not_rec(root);
	cout << endl;
	cout << "非递归中序遍历为：" << endl;
	inorder_not_rec(root);
	cout << endl;
	cout << "非递归后序遍历为：" << endl;
	postorder_not_rec(root);

	cout << endl;
	cout << "层序遍历为：" << endl;
	level_traverse(root);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
