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
//BUBBLE SORT
void Bubble(LList<Item>& L) {
	for (int i = L.length() - 1;i > 0;i--) {
		for (L.moveToStart(); L.currPos() < i;L.next()) {
			Item primonumero;
			int j;
			j = L.currPos();
			primonumero = L.getValue();
			L.next();
			if (primonumero.key() > L.getValue().key()) {
				Item secondonumero;
				secondonumero = L.getValue();
				L.prev();
				L.remove();
				L.next();
				L.insert(primonumero);
			}
			L.moveToPos(j);
		}
	}
	L.moveToEnd();
	
}
 //MERGE
void merge(LList<Item>& Lm, LList<Item>& La, LList<Item>& Lb) {
La.moveToStart();
Lb.moveToStart();
Item removed;
int N = La.length();
int M = Lb.length();
for (int k = 0; k < N + M; k++)
{
	if (La.length() == 0)
	{
		removed = Lb.remove();
		Lm.append(removed);
		continue;
	}
	if (Lb.length() == 0)
	{
		removed = La.remove();
		Lm.append(removed);
		continue;
	}
	if (La.getValue().key()<Lb.getValue().key())
		removed = La.remove();
	else
		removed = Lb.remove();
	Lm.append(removed);
}
}
//MERGESORT
void mergesort(LList<Item>& Lm)
{
	Lm.moveToStart();
	if (Lm.length() < 2) return;
	LList<Item> La, Lb;
	Item removed;
	int N = Lm.length();
	for (int k = 0; k<N; k++) {
		removed = Lm.remove();
		if (k % 2) La.append(removed);
		else Lb.append(removed);
	}
	mergesort(La);
	mergesort(Lb);
	merge(Lm, La, Lb);
}


//SELECTION SORT
void Selection(LList<Item>& L) {
	for (int i = 0; i < L.length();i++) {
		int min = i;
		for (L.moveToPos(i + 1); L.currPos() < L.length(); L.next()) {
			int a = L.currPos();
			Item primonumero;
			primonumero = L.getValue();
			L.moveToPos(min);
			Item secondonumero;
			secondonumero = L.getValue();
			if (primonumero.key() < secondonumero.key()) {
				min = a;

			}
			int y = L.currPos();
			L.moveToPos(min);
			secondonumero = L.remove();
			L.moveToPos(i);
			L.insert(secondonumero);
			
			primonumero = L.remove();
			L.moveToPos(y);
			L.insert(primonumero);
			L.moveToPos(a);
		}
	}
	
}

//PARTITION
int partition(LList<Item>& L ,int p, int r) {
	int j;
	Item temp,x;
	L.moveToEnd();
	x = L.getValue();
	int i = p -1;
	
	for (L.moveToPos(p);L.currPos()< r;L.next()) {
		int j = L.currPos();
		if (L.getValue().key() < x.key()) {
			temp = L.remove();
			i++;
			Item temp2;
			L.moveToPos(i);
			temp2 = L.remove();
			L.insert(temp);
			L.moveToPos(j);
			L.insert(temp2);
			}
		L.moveToPos(j);
	}
	L.moveToEnd();
	temp = L.remove();
	i++;
	L.moveToPos(i);
	Item temp2 = L.remove();
	L.insert(temp);
	L.moveToEnd();
	L.insert(temp2);

	return i;
}

//QUICK SORT
void Quick(LList<Item>& L, int l,int  r) {
	int q;
	if (l < r) {
		q = partition(L,l, r);
		Quick(L, l, q - 1);
		Quick(L, q + 1, r);
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
	int a[10] = { 7,3,6,5,23,45,3,22,12,4 };
	//Quick(a,0, 9);
	for (int i = 0;i < 10;i++) {
		cout << a[i] << endl;
	}
	L1.insert(Item(43));
	L1.insert(Item(5));
	L1.append(Item(21));
	L1.append(Item(25));
	L1.append(Item(98));
	L1.append(Item(1));
	cout << "22) L1: "; lprint(L1);
	mergesort(L1);
	lprint(L1);
	cout << "That is all.\n";
	int p;
	cin >> p;
	return 0;
}