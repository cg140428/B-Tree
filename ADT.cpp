#ifndef ADT_CPP
#define ADT_CPP
#include "BT.h"

Node::Node() 
	:n(0)
{
	for (int i = 0; i < 6; i++)
	{
		child[i] = NULL;
	}
}

//Tree 생성자
Tree::Tree() {}

void Tree::insertBT(Node*& T, int m, int newKey) {
	if (T == NULL) {
		T = new Node();
		T->data[0] = newKey;
		T->n = 1;
		return;
	}
	Node* x = T;
	stack<Node*> nodeTrace; //노드의 주소를 스택에 저장하면서 newKey가 삽입될 위치를 탐색한다.
	int i;
	//nodeTrace.push(숫자);
	//nodeTrace.pop();
	//nodeTrace.size();
	do {
		i = 0;
		//한 노드 안에서 몇번째로 들어가야 하는지 셈(sorting)
		while (i < x->n && i < m-1 && x->data[i] < newKey) {
			i++;
		}
		//중복되는 값이 있으면 멈춤
		if (i < x->n && i < m-1 && newKey == x->data[i])
			return;
		nodeTrace.push(x);
		x = x->child[i];
	} while (x != NULL);

	bool finished = false;

	x = nodeTrace.top();
	nodeTrace.pop();

	do {
		//오버플로우 안날 때 처리
		int newKeyIndex = 0;
		if (x -> n < m-1) {

			// 여기 아줌마 
			while (newKeyIndex < x->n && newKeyIndex < m && x->data[i] < newKeyIndex) {
				newKeyIndex++;
			}

			for (int i = x->n; i >= newKeyIndex; i--) {
				x->data[i] = x->data[i - 1];
			}


			x->data[newKeyIndex] = newKey;
			x->n += 1;
			finished = true;
		}
		//오버플로우 날 때 처리
		else {
			//임시의 칸을 하나 늘려 줌
			while (newKeyIndex < x->n && newKeyIndex < m && x->data[i] < newKeyIndex) {
				newKeyIndex++;
			}
			for (int i = x->n; i > newKeyIndex; i--) {
				x->data[i] = x->data[i - 1];
				// 갓태진 : 포인터 옮기세요.
				x->child[i + 1] = x->child[i];
				//x->child[i] = x->child[i - 1];
			}
			x->data[newKeyIndex] = newKey;
			x->n += 1;

			Node* tempNode;
			Node* y;
			tempNode = new Node();
			y = new Node();
			tempNode->n = x->n;
			int j = 0;
			for (j = 0; j < x->n; j++) {
				tempNode->child[j] = x->child[j];
				tempNode->data[j] = x->data[j];
			}
			tempNode->child[j] = x->child[j];

			//x노드 초기화
			x->n = 0;
			for (int j = 0; j < m; j++) {
				x->child[j] = NULL;
				x->data[j] = NULL;
			}

			int mid; //분할 노드의 중간지점
			mid = tempNode->n / 2;
			newKey = tempNode->data[mid];
			//x노드, y노드 설정
			x->n = mid;
			y->n = tempNode->n - (mid + 1);
			for (j = 0; j < m / 2; j++) {
				x->child[j] = tempNode->child[j];
				x->data[j] = tempNode->data[j];

				y->child[j] = tempNode->child[m / 2 + j + 1];
				y->data[j] = tempNode->data[m / 2 + j + 1];
			}
			x->child[j] = tempNode->child[j];
			y->child[j] = tempNode->child[m / 2 + j + 1];

			if (nodeTrace.size() != 0) {
				x = nodeTrace.top();
				x->child[x->n + 1] = y;	// 추후 수정,,
				nodeTrace.pop();
			}
			else {
				Node* t;
				t = new Node();
				t->data[0] = newKey;
				t->child[0] = x;
				t->child[1] = y;
				t->n = 1;
				T = t;
				finished = true;
			}
		}
		
	} while (!finished);

}

void Tree::inOrderBT(Node* T, int m) {
	if (T == NULL)
		return;
	int i;

	cout << endl;
	cout << T << endl;
	for (i = 0; i < T->n; i++) {
		cout << T->child[i] << ", ";
		cout << T->data[i] << ", ";
	}
	cout << T->child[i] << endl;


	for (i = 0; i < T->n; i++) {
		Tree::inOrderBT(T->child[i], m);
		cout << T->data[i] << " ";
	}
	Tree::inOrderBT(T->child[i], m);
}
#endif