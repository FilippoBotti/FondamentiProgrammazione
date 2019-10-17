// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<sstream>
#include<fstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.


// find function for Items.
// Return true if "item" is in list "L", false otherwise

bool find(List<Item2>& L, const Item2& item_to_search) {
	Item2 it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.name() == it.name()) return true;  // Found K
	}
	return false;                // K not found
}




// Main routine for linked list driver class
int main(int argc, char** argv) {

	LList<Item> L1;
	string str1, str3;
	Ciclista atleta;
	ifstream myfile("giro_italia.txt"); 
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, str1, ';');
			istringstream token(str1);
			token >> atleta.anno;
			getline(myfile, atleta.nome, ';');
			getline(myfile, str3);
			istringstream token3(str3);
			token3 >> atleta.nazione;
			Item oggetto(atleta);
			L1.insert(oggetto);

		}
		myfile.close(); 
	}
	bubble2(L1, 0, L1.length() - 1);
	lprint(L1);
	LList<Item2> L2;
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		int n = 0;
		int j = L1.currPos();
		string atleta = L1.getValue().name();
		for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
			if (atleta == L1.getValue().name()) {
				n++;
			}
		}
		L1.moveToPos(j);
		Item2 object(atleta, n);
		if (find(L2, object) == false) {
			L2.insert(object);
		}
	}
	int difference1,diff=0;
	LList<Item2> L3;
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		int min_anno = 0;
		int max_anno = 0;
		min_anno = L1.getValue().year();
		int j = L1.currPos();
		string atleta = L1.getValue().name();
		for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
			if (atleta == L1.getValue().name()) {
				if (L1.getValue().year() > max_anno) {
					max_anno = L1.getValue().year();
				}
			}
		}
		L1.moveToPos(j);
		difference1=(max_anno - min_anno);
		Item2 object(atleta, difference1);
		if (find(L3, object) == false) {
			L3.insert(object);
		}
		if (difference1 > diff) {
			diff = difference1;
		}
	}
	
		
	
	
	lprint(L2);
	
	bubble(L2,0,L2.length()-1);
	cout << "La lista ordinata risulta: " << endl;
	lprint(L2);
	cout << "La differenza piu' lunga tra una vittoria ed un altra per ogni atleta risulta: " << endl;
	lprint(L3);
	int a;
	cin >> a;
	return 0;
}