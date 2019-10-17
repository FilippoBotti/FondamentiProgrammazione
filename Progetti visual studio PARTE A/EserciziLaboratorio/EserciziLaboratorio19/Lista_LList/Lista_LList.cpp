// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
#define N 7
using namespace std;

// Include the linked list template class
#include "llist.h"
#include "bubble.h"
#include "comp.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.
// Return true if "K" is in list "L", false otherwise
int find(List<Item>& L, int K) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key() == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// Insert "it" at current position
void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		if (it.key() <= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}


// Main routine for linked list driver class
int main(int argc, char** argv) {
	srand(time(NULL));
	int MINVAL,MAXVAL;
	LList<Item> L1,L2;
	cout << "Inserisci il valore minimo " << endl;
	cin >> MINVAL;
	cout << "Inserisci il valore massimo " << endl;
	cin >> MAXVAL;
	for (int i = 0;i < N;i++) {
		int num;
		num = rand() % (-MINVAL + MAXVAL) +MINVAL;
		L2.insert(Item(num));
	}
	lprint(L2);
	for (L2.moveToStart();L2.currPos() < L2.length();L2.next()) {
		Item a;
		a = L2.getValue();
		L1.insert(a);
	}
	bubble(L1, 0, N - 1);
	cout << "La lista ordinata tramite bubblesort risulta " << endl;
	lprint(L1);
	
	
	int h;
	cin >> h;
	return 0;
}