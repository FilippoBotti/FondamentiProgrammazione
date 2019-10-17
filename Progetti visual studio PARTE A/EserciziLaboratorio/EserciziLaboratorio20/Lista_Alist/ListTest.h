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
typedef struct { int day; int month; int year; } Date;

// Your basic int type as an object.
class Item {
private:
	string nome, cognome;
	Date data;
public:
	Item() {};
	Item(string a, string b, Date c) { nome = a; cognome = b; data = c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	string name() const { return nome; }
	string surname() const { return cognome; }
	Date date() const { return data; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.name() << " " << i.surname() << " " << i.date().day << "/" << i.date().month << "/" << i.date().year << endl;
}

bool operator <(const Item& x, const Item& y) {
	if (x.surname() < y.surname()) { return true; }
	else if (x.surname() == y.surname() && x.name() < y.name()) { return true; }
	else if (x.surname() == y.surname() && x.name() == y.name() && x.date().year < y.date().year) { return true; }
	else if (x.surname() == y.surname() && x.name() == y.name() && x.date().year == y.date().year && x.date().month < y.date().month) { return true; }
	else if (x.surname() == y.surname() && x.name() == y.name() && x.date().year == y.date().year && x.date().month == y.date().month && x.date().day < y.date().day ) { return true; }
	else { return false; }
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



#endif

