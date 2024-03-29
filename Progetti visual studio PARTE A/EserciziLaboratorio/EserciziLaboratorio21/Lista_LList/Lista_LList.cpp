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

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

int comp(Item &A, Item &B)
{
	if (B.key() < A.key()) return 1;
	else
		return 0;
}

void insertion(LList<Item>& L, int l, int r)
{
	for (int i = l + 1; i < L.length(); i++) {
		
		
		for (int j = i; (j > l); j--) {
			L.moveToPos(j - 1);
			Item a;
			a = L.getValue();
			L.next();
			Item b = L.getValue();
			if ((j > l) && comp(b,a)) {

				L.moveToPos(j - 1);
				L.remove();
				L.insert(b);
				L.next();
				L.remove();
				L.insert(a);
			}
		}
	}
	L.moveToStart();
}


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

	LList<Item> L1;
	L1.insert(Item(8));
	L1.insert(Item(11));
	L1.insert(Item(12));
	L1.insert(Item(2));
	cout << "Lista " << endl;
	lprint(L1);
	insertion(L1, 0, L1.length());
	cout << "Lista ordinata in modo decrescente con insertionsort: " << endl;
	lprint(L1);
	int a;
	cin >> a;
	return 0;
}