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
	int biglietto;
	string cognome, nome;
public:
	Item() {}
	Item(int b, string n, string c ) { biglietto = b; nome = n; cognome = c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int number() const { return biglietto; }
	string surname() const  { return cognome; }
	string name() const { return nome;  }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const  Item& i)
{
	return s << i.number() << " " << i.name() << " " << i.surname();
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
		cout << L.getValue() << endl;
		L.next();
	}
	cout << "| ";
	while (L.currPos()<L.length()) {
		cout << L.getValue() << endl;
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}


class Premio {
private:
	string premio;
	float euro;
public:
	Premio() {}
	Premio(string p, float e) { premio = p; euro = e; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	float price() const { return euro; }
	string premium() const { return premio; }
	
};
ostream& operator<<(ostream& s, Premio& i )
{
	return s << i.premium() << " " << i.price() << endl;
}

#endif

