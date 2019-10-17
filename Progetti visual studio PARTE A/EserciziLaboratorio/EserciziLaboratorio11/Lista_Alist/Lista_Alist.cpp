// From the software distribution accompanying the textbook
// "A Practical Itemroduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Array-based list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
#define N 3

using namespace std;

// Include the array-based list template code
#include "alist.h"

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


// Main routine for array-based list driver class
int main(int argc, char** argv) {
	
	// Declare some sample lists
	AList<Item> L1;
	AList<Item> L2;
	AList<Item> L3;
	AList<Item> L4[N];

	L4[0].insert(9);
	L4[0].insert(5);
	L4[0].insert(4);
	L4[0].insert(3);
	L4[0].insert(2);
	L4[0].insert(1);
	L4[1].insert(91);
	L4[1].insert(5);
	L4[1].insert(43);
	L4[1].insert(32);
	L4[1].insert(22);
	L4[1].insert(11);
	L4[1].insert(21);
	L4[2].insert(5);
	L4[2].insert(23);
	L4[2].insert(62);
	L4[2].insert(12);
	L4[2].insert(1);
	int max = 0;
	Item g;
	int j = 0;
	for (int y = 0;y < N;y++) {
		for (L4[y].moveToStart(); L4[y].currPos() < L4[y].length(); L4[y].next())
		{
			g = L4[y].getValue();
		}
		if (g.key() > max) {
			max = g.key();
			j = y;
		}
	}
	cout << "Il valore massimo e' " << max << " e si trova nella lista di posizione " << j << " dell'array " << endl;


	 int i;
	cin >> i;
	
	return 0;
}