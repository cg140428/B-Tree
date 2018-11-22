#ifndef BT_H
#define BT_H
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// Node�� ��Ÿ���� Ŭ���� - ������ ���� ���� ����Ʈ��, ������ ����Ʈ���� ����Ű�� �����ͷ� ����
class Node {
public:
	int n; // ���Ե� �������� ����
	int data[5]; // ������ ��
	Node* child[6]; // �ڽ� ����Ʈ�� ����Ű�� ������

	Node();
};

//���� Ž�� Ʈ���� �����ϴ� Ŭ����
class Tree {
public:
	Tree(); //Tree ������
	void insertBT(Node*& T, int m, int newKey);
	void inOrderBT(Node* T, int m);
	void deleteBT(Node*& T, int m, int oldKey);
};
#endif