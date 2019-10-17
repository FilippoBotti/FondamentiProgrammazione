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




int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key() == it.key() && item_to_search.get_name() == it.get_name())
		{
			return 0;
		}
		else if (item_to_search.key() == it.key() && item_to_search.get_name() != it.get_name()) {
			L.remove();
			L.insert(Item(it.key(), item_to_search.get_name()));
			return 2;
		}
	}
	L.append(item_to_search);
	return 1;                // K not found
}

// Main routine for linked list driver class
int main(int argc, char** argv) {
	
	LList<Item> L9;
	L9.clear();
	Item K("TO", "Torino");
	L9.insert(Item("TO", "Torino"));
	L9.insert(Item("RO" , "Roma"));
	L9.insert(Item("PA" , "Padova"));
	L9.insert(Item("SA", "Sassari"));
	
	cout <<  "0 = Item trovato; " << endl << "1 = Item non trovato(aggiunto in coda); " << endl << "2 = Abbr trovata, nome diverso " << endl << find(L9, K) << endl;
	L9.moveToEnd();
	cout << "27) "; lprint(L9);
	Item f;
	
	int h;
	cin >> h;
	return 0;
	
}