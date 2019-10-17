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
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include<fstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.
// Return true if "K" is in list "L", false otherwise



void bubble(LList<Ricette>& L1, int l, int r)
{
	
	Ricette it_temp;
	Ricette it_curr;
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			L1.moveToPos(j - 1);
			it_curr = L1.getValue();
			L1.moveToPos(j);
			it_temp = L1.getValue();
			if (it_temp.key() < it_curr.key())
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
	string codice, prodotto,str;
	int quantità;
	ifstream myfile("dispensa.txt");
	if (myfile.is_open()) { 
		while (!myfile.eof()) {
			getline(myfile, codice, ';'); 
			getline(myfile, prodotto, ';');
			getline(myfile, str); 
			istringstream token(str);
			token >> quantità;
			Item oggetto(codice,prodotto,quantità);
			L1.insert(oggetto);
		}
	myfile.close(); 
	}
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		Item search;
		int a = L1.currPos();
		int cont = L1.getValue().tot();
		search = L1.remove();
		if (find(L1, search) != -1) {
			cont += L1.getValue().tot();
			L1.remove();
		}
		L1.moveToPos(a);
		string f, b;
		int c;
		f = search.key();
		b = search.name();
		c = cont;
		Item search1(f, b, c);
		L1.insert(search1);

	}
	lprint(L1);

	string str2, str3, str4;
	int numero;
	string descrizione;
	string codice1;
	int quantità1;
	string codice2;
	int quantità2;
	LList<Ricette> L2;
	ifstream myfile2("ricette.txt");
	if (myfile2.is_open()) {
		while (!myfile2.eof()) {
			getline(myfile2, str2, ';');
			istringstream token(str2);
			token >> numero;
			getline(myfile2, descrizione, ';');
			getline(myfile2, codice1, ';');
			getline(myfile2, str3, ';');
			istringstream token3(str3);
			token3 >> quantità1;
			getline(myfile2, codice2, ';');
			getline(myfile2, str4);
			istringstream token4(str4);
			token4 >> quantità2;
			Ricette ogg(numero,descrizione,codice1,quantità1,codice2,quantità2);
			
			L2.insert(ogg);
		}
		myfile.close();
	}
	bubble(L2, 0, L2.length() - 1);
	lprint(L2);
	
	int n;
	int h;
	string k;
	cout << "Inserire il numero di un piatto(0-3)" << endl;
	cin >> n;
	bool ok1 = false;
	bool ok2 = false;
	L2.moveToPos(n);
	Item ingrediente1(L2.getValue().cod1(),  "ing1", L2.getValue().tot1());
	if (find(L1, ingrediente1) != -1) {
		Item app = L1.remove();
		h = app.tot();
		if(h-ingrediente1.tot()>=0){
			string  y;
			k = app.name();
			y = app.key();
			L1.insert(Item(y, k, (h - ingrediente1.tot())));
			ok1 = true;
		}
		else {
			cout << "Ingredienti insufficienti,mi spiace" << endl;
			ok1 = false;
		}
	}

	int p;
	string t;
	Item ingrediente2(L2.getValue().cod2(), "ing2", L2.getValue().tot2());
	if (find(L1, ingrediente2) != -1) {
		Item app2 = L1.remove();
		p = app2.tot();
		if (p - ingrediente2.tot() >= 0) {
			string y;
			t = app2.name();
			y = app2.key();
			L1.insert(Item(y, t, (p - ingrediente2.tot())));
			ok2 = true;
		}
		else {
			cout << "Ingredienti insufficienti,mi spiace" << endl;
			ok2 = false;
		}
	}

	
	lprint(L1);
	if (ok1 && ok2) {
		cout << "Hai deciso di mangiare " << L2.getValue().name() << " e sono rimasti " << h - ingrediente1.tot() << " di " << k << " e " << p - ingrediente2.tot() << " di " << t << endl;
	}
	int j;
	cin >> j;
	return 0;
}