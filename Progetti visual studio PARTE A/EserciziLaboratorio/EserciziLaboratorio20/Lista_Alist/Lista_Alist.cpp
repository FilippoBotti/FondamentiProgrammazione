// From the software distribution accompanying the textbook
// "A Practical Itemroduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Array-based list class test program

#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the array-based list template code
#include "alist.h"

// Generic list test commands
#include "ListTest.h"


void selection(AList<Item>& L, int l, int r)
{
	Item min_element, it_temp;
	for (int i = l; i < L.length()-1; i++)
		{
			int min = i;
			for (int j = i + 1; j < L.length(); j++) {
				L.moveToPos(min);
				min_element = L.getValue();
				L.moveToPos(j);
				it_temp = L.getValue();
				if (it_temp<min_element)
				{
					min = j;
					min_element = it_temp;
				}
				L.next();
			}
			L.moveToPos(min);
			Item it_temp = L.remove();
			L.moveToPos(i);
			L.insert(it_temp);

		}
	}





// Main routine for array-based list driver class
int main(int argc, char** argv) {
	AList<Item> L1;
	string str1, str2, str3; string nome; string cognome; int giorno, mese, anno; Date data;
	ifstream myfile("agenda.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {

			getline(myfile, nome, ' ');
			getline(myfile, cognome, ' ');
			getline(myfile, str1, '/');
			istringstream token(str1);
			token >> giorno;
			getline(myfile, str2, '/');
			istringstream token2(str2);
			token2 >> mese;
			getline(myfile, str3);
			istringstream token3(str3);
			token3 >> anno;
			data.day = giorno;
			data.month = mese;
			data.year = anno;
			Item x(nome, cognome, data);
			L1.insert(x);

		}
	}
		myfile.close();
		lprint(L1);
		L1.moveToStart();
		Item a = L1.getValue();
		L1.next();
		Item b = L1.getValue();
		selection(L1, 0, 98);
		cout << "Lista ordinata con selectionsort: " << endl;
		lprint(L1);
		L1.moveToPos(5);
		b = L1.getValue();
		L1.moveToPos(6);
		a = L1.getValue();
		if (a < b) { cout << "ciaoo"; }
		int p;
		cin >> p;
	return 0;
}