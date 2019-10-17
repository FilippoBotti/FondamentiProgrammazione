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
void Reverse_Stack(LStack<E>& S) {
	LStack<E> temp,temp2;
	while(S.length()>0) {
		E popped = S.pop();
		temp.push(popped);
	}
	while (temp.length()>0) {
		E popped = temp.pop();
		temp2.push(popped);
	}
	while(temp2.length()>0) {
		E popped = temp2.pop();
		S.push(popped);
	}
}
template <typename E> 
void Scambio_primo_ultimo(LStack<E>& S1) {
	LStack<E> appoggio;

	while (S1.length() > 0) {

		E popped = S1.pop();
		appoggio.push(popped);

	}
	E pop1 = appoggio.pop();


	while (appoggio.length() > 0) {
		E popped = appoggio.pop();
		S1.push(popped);
	}

	E pop2 = S1.pop();

	S1.push(pop1);
	Reverse_Stack(S1);
	S1.push(pop2);
	Reverse_Stack(S1);

}
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length()>0)
	{
		E popped = S.pop();
		cout << popped << endl;
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
			myfile >> biglietto >> nome >> cognome;
			Item A(biglietto, nome, cognome);
			L1.insert(A);
			temp.insert(A);
		}
		
	}

	myfile.close();
	lprint(L1);
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) {
		int count = 0;
		Item name = L1.getValue();
		for (temp.moveToStart();temp.currPos() < temp.length();temp.next()) {
			if (temp.getValue().name() == name.name() && temp.getValue().surname() == name.surname()) {
				count++;
			}
			if (count != 1 && temp.getValue().name() == name.name() && temp.getValue().surname() == name.surname()) {
				temp.remove();
			}
			
		}
	}
	for (temp.moveToStart();temp.currPos() < temp.length();temp.next()) {
		cout << "Primo biglietto acquistato da " << temp.getValue().name() << " " << temp.getValue().surname() << ": " << temp.getValue().number() << endl;
	}
	temp.~LList();
	
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) {
		if (L1.getValue().number() % 2 != 0) {
			L1.remove();
			L1.prev();
		}
	}
	cout << "I biglietti pari sono: " << endl;
	lprint(L1);
	LStack<Item> S1;

	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		
		S1.push(L1.getValue());
	}
	
	cout << "Stack normale " << endl;
	Lstackprint(S1);
	Scambio_primo_ultimo(S1);
	
	cout << "Scambio" << endl;
	Lstackprint(S1);
	int i;
	cin >> i ;

	return 0;
}