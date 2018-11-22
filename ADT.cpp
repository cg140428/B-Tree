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

//Tree ������
Tree::Tree() {}

void Tree::insertBT(Node*& T, int m, int newKey) {
	if (T == NULL) {
		T = new Node();
		T->data[0] = newKey;
		T->n = 1;
		return;
	}
	Node* x = T;
	stack<Node*> nodeTrace; //����� �ּҸ� ���ÿ� �����ϸ鼭 newKey�� ���Ե� ��ġ�� Ž���Ѵ�.
	int i;
	//nodeTrace.push(����);
	//nodeTrace.pop();
	//nodeTrace.size();
	do {
		i = 0;
		//�� ��� �ȿ��� ���°�� ���� �ϴ��� ��(sorting)
		while (i < x->n && i < m-1 && x->data[i] < newKey) {
			i++;
		}
		//�ߺ��Ǵ� ���� ������ ����
		if (i < x->n && i < m-1 && newKey == x->data[i])
			return;
		nodeTrace.push(x);
		x = x->child[i];
	} while (x != NULL);

	bool finished = false;

	x = nodeTrace.top();
	nodeTrace.pop();

	do {
		//�����÷ο� �ȳ� �� ó��
		int newKeyIndex = 0;
		if (x -> n < m-1) {

			// ���� ���ܸ� 
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
		//�����÷ο� �� �� ó��
		else {
			//�ӽ��� ĭ�� �ϳ� �÷� ��
			while (newKeyIndex < x->n && newKeyIndex < m && x->data[i] < newKeyIndex) {
				newKeyIndex++;
			}
			for (int i = x->n; i > newKeyIndex; i--) {
				x->data[i] = x->data[i - 1];
				// ������ : ������ �ű⼼��.
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

			//x��� �ʱ�ȭ
			x->n = 0;
			for (int j = 0; j < m; j++) {
				x->child[j] = NULL;
				x->data[j] = NULL;
			}

			int mid; //���� ����� �߰�����
			mid = tempNode->n / 2;
			newKey = tempNode->data[mid];
			//x���, y��� ����
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
				x->child[x->n + 1] = y;	// ���� ����,,
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