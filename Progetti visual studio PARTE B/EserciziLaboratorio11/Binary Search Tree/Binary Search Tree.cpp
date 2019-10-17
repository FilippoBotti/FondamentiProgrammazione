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
	
	BST<Item, Key1> bst;
	BST<Item2, Key2> bst2;
	string ufficio; string nome; int numero; string str;
	ifstream myfile("telefoni.txt"); 
	if (myfile.is_open()) { 
		while (!myfile.eof()) { 
			getline(myfile, ufficio, ',');
			getline(myfile, nome, ',');
			getline(myfile, str); 
			istringstream token(str);
			token >> numero;
			Item x;
			x.set_val(nome,ufficio);
			bst.insert(x);
			Item2 y;
			y.set_val(numero, nome);
			bst2.insert(y);
		}
		myfile.close(); 
	}
	bst.balance();
	cout << "Primo albero" << endl;
	bst.show(cout);
	cout << "Secondo albero " << endl;
	bst2.balance();
	bst2.show(cout);
	cout << endl;



	for (int i = 0;i < bst.tree_size(bst.get_head());i++) {
		Item p = bst.search(bst2.select(i).name());
		cout << bst2.select(i).key() <<  " " << bst2.select(i).name() << " "  << p.offie() << endl;
	}
	cout << endl;
	string str1;
	int number;

	cout << "Inserisci la stringa da cercare " << endl;
	getline(cin, str1);
	if (isNumber(str1)) {
		istringstream tk(str1);
		tk >> number;

		Item2 a = bst2.search(number);
		if (a.null())
			cout << "Elemento non trovato" << endl;
		else {
			Item b = bst.search(a.name());
			cout << a.key() << " " << a.name() << " " << b.offie() << endl;
		}
	}
	else {
		string name = str1;
		
		Item q = bst.search(name);
		cout << endl;
		if (!q.null()) {
			for (int y = 0; y < bst.tree_size(bst.get_head());y++) {
				Item r = bst.select(y);
				if (q.offie() == r.offie()) {
					cout << r.key() << endl;
				}
			}
		}
		else {
			cout << "Elemento non trovato " << endl;
		}
	}
	int fine;
	cin >> fine;
}