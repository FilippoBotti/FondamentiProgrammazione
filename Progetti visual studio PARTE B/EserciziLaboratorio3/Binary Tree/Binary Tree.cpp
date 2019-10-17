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
	

	BinaryTree<Item> *myBT = new BinaryTree<Item>;

	myBT->AddItem(Item("Parma"));
	myBT->AddItem(Item("Roma"));
	myBT->AddItem(Item("Genova"));
	myBT->AddItem(Item("Milano"));
	myBT->AddItem(Item("Spezia"));
	myBT->AddItem(Item("Bari"));
	myBT->AddItem(Item("Ravenna"));
	myBT->AddItem(Item("Cesena"));
	myBT->traverse();

	cout << endl << "numero di elementi in albero: " << myBT->count() << endl;
	cout << endl << "tree height: " << myBT->height() << endl;

	BinaryTree<Item> myBT1;
	Item it("pippo");
	myBT1.AddItem(it);

	Item it2("topolino");
	myBT1.AddItem(it2);

	Item it3("paperino");
	myBT1.AddItem(it3);

	myBT1.traverse();


	cout << endl << "numero di elementi in albero: " << myBT1.count() << endl;
	cout << endl << "tree height: " << myBT1.height() << endl;



	int fine;
	cin >> fine;
	return 0;
}