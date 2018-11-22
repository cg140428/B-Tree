#ifndef BT_H
#define BT_H
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// Node를 나타내는 클래스 - 데이터 값과 왼쪽 서브트리, 오른쪽 서브트리를 가리키는 포인터로 구성
class Node {
public:
	int n; // 삽입된 데이터의 개수
	int data[5]; // 데이터 값
	Node* child[6]; // 자식 서브트리 가리키는 포인터

	Node();
};

//이진 탐색 트리를 구성하는 클래스
class Tree {
public:
	Tree(); //Tree 생성자
	void insertBT(Node*& T, int m, int newKey);
	void inOrderBT(Node* T, int m);
	void deleteBT(Node*& T, int m, int oldKey);
};
#endif