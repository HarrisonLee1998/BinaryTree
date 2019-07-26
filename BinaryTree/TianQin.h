#pragma once
/*
	此文件包含天勤参考书上的一些练习题
*/

#include "BinaryTree.h"


//P165 （二）综合应用题 1 （4）
node* connect_leaves(node* );

//P166 （二）综合应用题 1 （5）
void construct_parent(node*, node*);
void print_path(node *);

//P166 （二）综合应用题 1 （6）
void convert_pre_to_post(int *,int,int);
void test_convert();

//P166 （二）综合应用题 1 （7）
void get_level_number(node *, int, int);

//P166 （二）综合应用题 1 （8）
void create_huffman_tree();
