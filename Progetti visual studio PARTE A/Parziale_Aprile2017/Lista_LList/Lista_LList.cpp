// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"
#include "lstack.h"

// Generic list test commands
#include "ListTest.h"


/*
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
*/

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.number() == it.number() && item_to_search.name() == it.name() && item_to_search.surname() == it.surname()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

/*
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

*/
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length()>0)
	{
		E popped = S.pop();
		cout << popped << " ";
		Stemp.push(popped);
	}
	while (Stemp.length()>0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}
// Main routine for linked list driver class
int main(int argc, char** argv) {
	srand(time(NULL));
	LList<Item> L1,temp;

	string str; string nome; string cognome; int biglietto;
	ifstream myfile("biglietti.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {

			getline(myfile, str, ' ');
			istringstream token(str);
			token >> biglietto;
			getline(myfile, nome, ' ');
			getline(myfile, cognome);
			Item Element(biglietto, nome, cognome);
			L1.insert(Element);
			temp.insert(Element);
		}
		myfile.close();
	}
	cout << " L1 ";
	lprint(L1);


	int k = 8;
	while (k > 7) {
		cout << "Inserisci il K " << endl;
		cin >> k;
	}
	Premio *array_ptr; 
	array_ptr = new Premio[k];
	
	string stringa; string name; int j=0; float euro;
	ifstream myfile2("premi.txt");
	if (myfile2.is_open()) {
		while (j<k) {
			myfile2 >> name >> euro;
			
			euro = euro / 100;
			Premio Award(name, euro);
			array_ptr[j] = Award;
			j++;
			
			
		}
		myfile2.close();
	}

	Premio Award = array_ptr[0];
	array_ptr[0] = array_ptr[k - 1];
	array_ptr[k - 1] = Award;
	LStack<Premio> S1;
	for (int j = 0; j < k; j++) {
		cout << array_ptr[j] << endl;
	}
	float somma_premi=0;
	for (int j = k - 1; j > -1; j--) {
		S1.push(array_ptr[j]);
		somma_premi += array_ptr[j].price();
	}
	cout << "S1: ";
	Lstackprint(S1);
	Item P;
	cout << "Somma totale: " << somma_premi << endl;
	for (int i = 0; i < k;i++) {
		
		int random_number = rand() % temp.length();
		temp.moveToPos(random_number);
		P = temp.getValue();
		cout << "Il premio va a " << temp.getValue() << endl;
		for (temp.moveToStart(); temp.currPos() < temp.length(); temp.next()) {
			
			if ( temp.getValue().name() == P.name() && temp.getValue().surname() == P.surname()) {
				temp.remove();
				temp.moveToStart();
			}
		}
	}
	lprint(temp);
	temp.~LList();
	int i;
	cin >> i;

	return 0;
}