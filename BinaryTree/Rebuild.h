#pragma once

#include "BinaryTree.h"

void init(int);

/*
	ע�����������ַ���������ʹ����ȷ������, ���������쳣��
*/

/*
��������1
10
3 4 2 6 5 7 1 9 0 8
1
4 3 6 7 5 2 0 9 8 1

��������2
5
1 0 4 3 2
1
0 1 2 3 4
*/
//������ͺ��򹹽�������
node* buildFromInAndPost(int inL, int inR, int postL, int postR);


/*
��������1
10
3 4 2 6 5 7 1 9 0 8
2
1 2 3 4 5 6 7 8 9 0

��������2
5
3 2 4 1 0
2
0 1 2 3 4
*/
//�������ǰ�򹹽�������
node* buildFromInAndPre(int inL, int inR, int postL, int postR);