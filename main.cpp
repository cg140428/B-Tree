/************************************************************************
*Name: ¿Ã¥Ÿ¿∫
*Student ID: 20171661
*HomeWork #2
*date 2018-11-22
*/

#ifndef MAIN_CPP
#define MAIN_CPP
#include "BT.h"

int main(void) {
	int num[40] = { 30, 20, 62, 110, 140, 15, 65, 136, 150, 120,
		40, 132, 19, 128, 138, 100, 16, 145, 70, 42,
		69, 43, 26, 60, 130, 50, 18, 7, 36, 58,
		22, 41, 59, 57, 54, 33, 75, 124, 122, 123 };

	Node* T = NULL;
	Tree t;

	cout << "******m=3 B-Tree ª¿‘******" << endl;
	// for (int i = 0; i < sizeof(num) / sizeof(int); i++) {
	for(int i = 0; i < 10; i++) {
		t.insertBT(T, 3, num[i]);
		t.inOrderBT(T, 3);
		cout << endl;
	}
	cout << endl;

	//T = NULL;

//	cout << "******m=4 B-Tree ª¿‘******" << endl;
//	for (int i = 0; i < sizeof(num)/sizeof(int); i++) {
		//t.insertBT(T, 4, num[i]);
		//t.inOrderBT(T, 4);
		//cout << endl;
	//}
//	cout << endl;

	return 0;
}

#endif