// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ostream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"




// Main routine for linked list driver class
int main(int argc, char** argv) {

	LList<Item> L1;
	string nome,str1,str2,str3;
	int minuti, secondi,centesimi;
	float tempo;
	Atleta player;
	ifstream myfile("50rn.txt"); 
	if (myfile.is_open()) {
		while (!myfile.eof()) { 
			getline(myfile, player.identità, ';');
			getline(myfile, str1, ' ');
			istringstream token(str1);
			token >> player.minuti;
			getline(myfile, str2, ' ');
			istringstream token2(str2);
			token2 >> player.secondi;
			getline(myfile, str3);
			istringstream token3(str3);
			token3 >> centesimi;
			player.tempo = ((player.minuti * 60 * 100) + (player.secondi * 100) + centesimi) / 100.00;
			Item oggetto(player);
			L1.insert(oggetto);
		}
		myfile.close(); }
	lprint(L1);
	bubble(L1, 0, L1.length()-1);
	cout << "Lista ordinata " << endl;
	lprint(L1);
	cout << "I dieci migliori atleti sono: " << endl;
	
	for (L1.moveToStart();L1.currPos() < 10;L1.next()) {
		cout << L1.getValue();
		
	}

	ofstream myfile1("example.txt"); 
	if (myfile1.is_open()) {
		for (L1.moveToStart();L1.currPos() < 10;L1.next()) {
			myfile1 << L1.getValue() << endl;
			
		}
		
	} 
	myfile1.close();

	L1.clear();

	int a;
	cin >> a;
	return 0;
}