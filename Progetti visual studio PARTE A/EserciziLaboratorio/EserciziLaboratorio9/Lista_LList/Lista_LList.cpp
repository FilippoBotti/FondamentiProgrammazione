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

void fondliste(List<Item>& L1, List<Item>& L2, List<Item>& L3) {



	for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next()) {
		Item element = L1.getValue();
		insert_ordered(L3, element);
	}
	for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next()) {
		Item element = L2.getValue();
		insert_ordered(L3, element);
	}
}

// Main routine for linked list driver class
int main(int argc, char** argv) {

	
	LList<Item> L5;
	LList<Item> L6;
	LList<Item> L7;
	L6.insert(4);
	L6.insert(23);
	L6.insert(18);
	L6.insert(5);
	L5.insert(44);
	L5.insert(1);
	L5.insert(47);
	L5.insert(8);
	fondliste(L5, L6, L7);
	L7.moveToEnd();
	cout << " 1) "; lprint(L5);
	cout << " 2) "; lprint(L6);
	cout << " 3) "; lprint(L7);

	cout << "That is all.\n";

	int i;
	cin >> i;
	return 0;
}