// fdjskz.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include<fstream>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"
#include"lstack.h"

// Generic list test commands
#include "ListTest.h"


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
		if (item_to_search.name() == it.name() && item_to_search.surname() == it.surname()) return L.currPos();  // Found K
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
void selectionsort(List<Item>& L) {
	int min_pos;
	int min_value;
	Item it_curr;
	Item it_temp;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<L.length() - 1; i++) {
		L.moveToPos(i);
		it_curr = L.getValue();
		min_pos = i;
		min_value = it_curr.key();
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			it_temp = L.getValue();
			if (it_temp.key() > min_value)
			{
				min_pos = L.currPos();
				min_value = it_temp.key();
			}
			L.next();
		}
		L.moveToPos(min_pos);
		it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}

}

void bubblesort(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key()>it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}




// Main routine for linked list driver class
int main(int argc, char** argv) {

	LList<Item> L1,L2;
	
	int biglietto;
	string nome, cognome;
	ifstream myfile("biglietti.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> biglietto >> nome >> cognome;
			Item persona(biglietto, cognome, nome);
			L1.insert(persona);
		}
		myfile.close();
	}
	selectionsort(L1);
	lprint(L1);
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		Item search = L1.getValue();
		if (find(L2, search) == -1) {
			L2.insert(search);
		}
	}
	lprint(L2);
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		int j = L1.currPos();
		if (L1.getValue().key() % 2 == 1) {
			L1.remove();
			L1.prev();

		}
		
	}
	lprint(L1);
	LStack<Item> S1;
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		S1.push(L1.getValue());
	}
	Lstackprint(S1);
	LStack<Item> S2;
	Item a;
	a = S1.pop();
	
	while (S1.length() > 0) {
		Item popped = S1.pop();
		S2.push(popped);
	}
	
	Item b = S2.pop();
	
	S1.push(a);
	
	while (S2.length() > 0) {
		Item popped = S2.pop();
		S1.push(popped);
	}
	cout << "finishhhh " << endl;
	S1.push(b);
	Lstackprint(S1);
	int g;
	cin >> g;
	return 0;
}