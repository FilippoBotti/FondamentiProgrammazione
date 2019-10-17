// Binary Search Tree.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst.h"
#include<sstream>
#include<fstream>
#include <time.h>  // Used by timing functions

bool isNumber(string s) {
	if (s.size() == 0) return false;
	for (int i = 0; i<s.size(); i++) {
		if ((s[i] >= '0' && s[i] <= '9') == false) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	BST<Item, Key> bst;
	string str; string nome; string str1; Key matricola; int voto; string mail;
	ifstream myfile("parteA.txt"); 
	if (myfile.is_open()) { 
		while (!myfile.eof()) { 
			getline(myfile, str1, ',');
			istringstream tk(str1);
			tk >> matricola;
			getline(myfile, nome, ',');
			getline(myfile, str, ',');
			
			if (str == " INSUFFICIENTE") {
				voto = 0;
			}
			else {
				istringstream token(str);
				token >> voto;
			}
			getline(myfile, mail);
			Item x;
			x.set_val(matricola, nome, voto, mail);
			bst.insert(x);
		}
		myfile.close(); 
	}
	BST<Item, Key> bst2;
	ifstream myfile2("parteB.txt");
	if (myfile2.is_open()) {
		while (!myfile2.eof()) {
			getline(myfile2, str1, ',');
			istringstream tk(str1);
			tk >> matricola;
			getline(myfile2, nome, ',');
			getline(myfile2, str, ',');

			if (str == " INSUFFICIENTE") {
				voto = 0;
			}
			else {
				istringstream token(str);
				token >> voto;
			}
			getline(myfile2, mail);
			Item x;
			x.set_val(matricola, nome, voto, mail);
			bst2.insert(x);
		}
		myfile2.close();
	}
	cout << "PARTE A " << endl;

	bst.show(cout);

	cout << endl << "PARTE B " << endl;
	bst2.show(cout);

	for (int i = 0; i < bst.tree_size(bst.get_head());i++) {
		Item z = bst.select(i);
		float voto = 0;
		voto = voto + z.mark();
		Item y = bst2.search(z.key());
		voto += y.mark();
		if (voto / 2.0 >= 18) {
			cout << "La media dell'alunno " << z.name() << " e' " << voto / 2.0 << endl;
		}
		else {
			cout << "La media dell'alunno " << z.name() << " e' " << "INS" << endl;
		}
	}

	int count = 0;
	float vote = 0;
	for (int i = 0; i < bst.tree_size(bst.get_head());i++) {
		Item z = bst.select(i);
		
		if (z.mark()>= 18) {
			vote = vote + z.mark();
			count += 1;

		}
	}
	cout << "La media dei voti sufficienti della prima prova risulta: " << vote/count << endl;
	count = 0;
	vote = 0;
	for (int i = 0; i < bst2.tree_size(bst.get_head());i++) {
		Item z = bst2.select(i);
		
		if (z.mark() >= 18) {
			vote = vote + z.mark();
			count += 1;

		}
	}
	cout << "La media dei voti sufficienti della seconda prova risulta: " << vote / count << endl;
	int fine;
	cin >> fine;
}