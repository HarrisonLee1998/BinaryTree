#pragma once
/*
	���ļ��������ڲο����ϵ�һЩ��ϰ��
*/

#include "BinaryTree.h"


//P165 �������ۺ�Ӧ���� 1 ��4��
node* connect_leaves(node* );

//P166 �������ۺ�Ӧ���� 1 ��5��
void construct_parent(node*, node*);
void print_path(node *);

//P166 �������ۺ�Ӧ���� 1 ��6��
void convert_pre_to_post(int *,int,int);
void test_convert();

//P166 �������ۺ�Ӧ���� 1 ��7��
void get_level_number(node *, int, int);

//P166 �������ۺ�Ӧ���� 1 ��8��
void create_huffman_tree();
