// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


void bubble(LList<Item2>& L1, int l, int r)
{

	Item2 it_temp;
	Item2 it_curr;
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			L1.moveToPos(j - 1);
			it_curr = L1.getValue();
			L1.moveToPos(j);
			it_temp = L1.getValue();
			if (it_temp.spesa() > it_curr.spesa())
			{
				L1.moveToPos(j - 1);
				L1.remove();

				L1.insert(it_temp);
				L1.moveToPos(j);
				L1.remove();

				L1.insert(it_curr);
			}
		}
	}
	L1.moveToStart();


}


// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key1() == it.key1()) return L.currPos();  // Found K
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
		if (it.key1() <= L.getValue().key1())
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
	int mese1, mese2, tot;
	ifstream myfile("spese.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> mese1 >> mese2 >> tot;
			Item obj(mese1, mese2, tot);
			L1.insert(obj);
		}
		myfile.close();
	}
	lprint(L1);
	LList<Item2>L2;
	int contributo;
	int a=0, b;
	bool ok = false;
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		b = L1.currPos();
		contributo = L1.getValue().spesa() / (L1.getValue().key2() - L1.getValue().key1() + 1);
		for (int j = L1.getValue().key1(); j < L1.getValue().key2()+1; j++) {
			
			for (L2.moveToStart();L2.currPos() < L2.length();L2.next()) {
				
			
			if(L2.getValue().key1()==j){
				Item2 app = L2.remove();
				int f = app.key1();
				ok = true;
				int cont = app.spesa();
				cont += contributo;
				L2.insert(Item2(f, cont));
			}
			
		}
			if(ok == false) {
				L2.insert(Item2(j, contributo));
			}
		}
		L1.moveToPos(b);
	}
	cout << "Seconda lista " << endl;
	bubble(L2, 0,L2.length() - 1);
	lprint(L2);
	int j;
	cin >> j;
	return 0;
}