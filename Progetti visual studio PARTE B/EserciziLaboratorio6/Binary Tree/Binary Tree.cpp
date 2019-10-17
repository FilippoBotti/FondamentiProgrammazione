// Binary Tree.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree.h"

int main(int argc, char** argv) {
	srand(time(NULL));

	BinaryTree<int> *myBT = new BinaryTree<int>;
	myBT->AddItem(1);
	myBT->AddItem(0);
	myBT->AddItem(5);
	myBT->AddItem(2);
	myBT->AddItem(14);
	myBT->AddItem(1);
	myBT->AddItem(10);
	myBT->AddItem(4);

	myBT->traverse();

	cout << endl << "numero di elementi in albero: " << myBT->count() << endl;
	cout << endl << "tree height: " << myBT->height() << endl;

	myBT->~BinaryTree();
	myBT->height();

	int fine;
	cin >> fine;
	return 0;
}