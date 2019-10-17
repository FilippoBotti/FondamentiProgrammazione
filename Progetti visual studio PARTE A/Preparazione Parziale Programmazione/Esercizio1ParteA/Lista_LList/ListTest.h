// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"

// Your basic int type as an object.
class Item {
private:
	string codice;
	string nome;
	int quantità;
public:
	Item() {}
	Item(string a, string b, int c) { codice = a; nome = b;quantità = c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	string key() const { return codice; }
	string name() const { return nome; }
	int tot() const { return quantità; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key() << " " << i.name() << " " << i.tot() << endl;
}

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i<currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos()<L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}



class Ricette {
private:
	int numero;
	string descrizione;
	string codice1;
	int quantità1;
	string codice2;
	int quantità2;
public:
	Ricette() {}
	Ricette(int a, string b, string c, int d, string e, int f) { numero = a; descrizione = b; codice1 = c; quantità1 = d; codice2 = e; quantità2 = f; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return numero; }
	string name() const { return descrizione; }
	string cod1() const { return codice1; }
	int tot1() const { return quantità1;  }
	string cod2() const { return codice2;  }
	int tot2() const { return quantità2; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Ricette& i)
{
	return s << i.key() << " " << i.name() << " " << i.cod1() << " " <<  i.tot1() << " " << i.cod2() << " " << i.tot2() << endl;
}


#endif

