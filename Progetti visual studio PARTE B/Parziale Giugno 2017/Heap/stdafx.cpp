// stdafx.cpp : file di origine che include solo le inclusioni standard
// Heap.pch sarà l'intestazione precompilata
// stdafx.obj conterrà le informazioni sui tipi precompilati

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap.h"
#include"Item.h"
#include<fstream>
#include<sstream>
#include<ostream>
#include "bst.h"
#define M 1
#define H 0
#define L 2

int number(string s) {
	
	
		if (s == "M") {
			return 1;
		}
		if (s == "L") {
			return 2;
		}
		if (s == "H") {
			return 0;
		}
	
	
}
int main(int argc, char** argv) {
	

	PQ<Item> Code[3];
	string str; string nome; string code; string città;  int priorità;
	ifstream myfile("spettatori.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, nome, ';');
			getline(myfile, code, ';');
			getline(myfile, città, ';');
			getline(myfile, str);
			istringstream token(str);
			token >> priorità; 
			Item x(nome, città, priorità);
			int y = number(code);
			Code[y].insert(x);

		}
		myfile.close();
	}
	for (int i = 0; i < 2;i++) {
		cout << "Primi spettatori " << endl;
		for (int l = 0;l < 3;l++) {
			if (Code[0].length() > 0) {
				cout << Code[0].getmax() << endl;
			}
		}
		cout << endl << endl;
		cout << "Secondi spettatori " << endl;
		for (int l = 0;l < 2;l++) {
			if (Code[1].length() > 0) {
				cout << Code[1].getmax() << endl;
			}
		}
		cout << endl << endl;
		cout << "Terzi spettatori " << endl;
		if (Code[2].length() > 0) {
			cout << Code[2].getmax() << endl;
		}
		cout << endl << endl;
	}

	BST<Item, string> bst;
	for (int p = 0;p < 3;p++) {
		while (Code[p].length() > 0) {
			bst.insert(Code[p].getmax());
		}
	}
	cout << "Albero persone mancanti " << endl;
	bst.balance();
	cout << bst.stamp("Parma",cout);
	bst.trova_padre("Giuseppe Longo");
	int fine;
	cin >> fine;
	return 0;
}
