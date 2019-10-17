// Binary Search Tree.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst.h"
#include<fstream>
#include<sstream>
#include<string>
#include"llist.h"
#include"ListTest.h"
#include <time.h>  // Used by timing functions

int find(List<Item2>& L, int K) {
	Item2 it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.number()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

int main(int argc, char *argv[])
{
	ifstream myfile("info.dat");
	BST<Item, Key> bst;
	Key id;
	string name;
	if (myfile.is_open()) { 
		while (!myfile.eof()) {
			myfile >> id >> name;
			Item it;
			it.set_element(id,name);
			bst.insert(it);
		} 
		myfile.close();
	}
	BST<Item, Key> bst2;
	
	while (id > 0) {
		cout << "Inserisci id" << endl;
		cin >> id;
		if (id > 0) {
			cout << "Inserisci la stringa " << endl;
			cin >> name;
			Item it2;
			it2.set_element(id, name);
			bst2.insert(it2);
		}
	}
	cout << "stampa primo albero albero con attraversamento pre-order prima del bilanciamento:";
	cout << endl;  bst.show(cout); cout << endl;
	cout << "stampa secondo albero albero con attraversamento pre-order prima del bilanciamento:";
	cout << endl;  bst2.show(cout); cout << endl;
	//Bilanciamenti

	bst.balance();
	bst2.balance();
	cout << "stampa primo albero albero ";
	cout << endl;  bst.show(cout); cout << endl;
	cout << "stampa secondo albero albero";
	cout << endl;  bst2.show(cout); cout << endl;

	



	LList<Item2> l;
	for (int i = 0;i < bst.peso();i++) {
		Item x = bst.select(i);
		int id = x.key();
		string f = x.name();
		l.insert(Item2(id, f));

	}
	for (int i = 0;i < bst2.peso();i++) {
		Item x = bst2.select(i);
		int id = x.key();
		string f = x.name();
		l.insert(Item2(id, f));

	}
	LList<Item2> l2;
	bool f = false;
	for (l.moveToStart();l.currPos() < l.length();l.next()) {
		int j = l.currPos();
		Item2 x = l.remove();
		int id = x.number();
		string s1 = x.name();
		for (l.moveToPos(j+1);l.currPos() < l.length();l.next()) {
			if (l.getValue().number() == id) {
				x = l.remove();
				f = true;
				string s2 = x.name();
				s1 = s1 + s2;
				l.insert(Item2(id, s1));
			}
		}
		if (f == false) {
			l.moveToPos(j);
			l.insert(x);
		}
	}
	lprint(l);

















	int fine;
	cin >> fine;
}