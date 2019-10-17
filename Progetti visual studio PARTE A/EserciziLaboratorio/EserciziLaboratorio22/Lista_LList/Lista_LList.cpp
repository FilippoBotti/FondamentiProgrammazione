// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include<sstream>
#include<fstream>
#include <string>

#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


void exch(Item &A, Item &B)
{
	Item t = A; A = B; B = t;
}



int comp(Item &A, Item &B)
{
	if (B < A ) return 1;
	else
		return 0;
}


void insertion(Item a[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
		for (int j = i; ((j > l) && comp(a[j ], a[j-1])); j--)
			exch(a[j - 1], a[j]);
}


// Main routine for linked list driver class
int main(int argc, char** argv) {
	int N;
	LList<Item> lista_stud;
	Item* studenti = nullptr;
	Studente st;
	float eta_max;
	int num_scelti;

	
	ifstream myfile("studenti.txt");
	if (myfile.is_open()) {
		myfile >> N;
		studenti = new Item[N];
		for (int i = 0; i < N; i++) {
			myfile >> st.cognome >> st.età >> st.media;
			Item item_tmp(st);
			studenti[i] = item_tmp;
		}
		myfile.close();
	}

	
	for (int i = 0;i < N;i++) {
		cout << studenti[i];
	}
	cout << "Array ordinato in  maniera decrescente " << endl;
	insertion(studenti, 0, N - 1);
	for (int i = 0;i < N;i++) {
		cout << studenti[i];
	}
	int a;
	cin >> a;
	return 0;
}