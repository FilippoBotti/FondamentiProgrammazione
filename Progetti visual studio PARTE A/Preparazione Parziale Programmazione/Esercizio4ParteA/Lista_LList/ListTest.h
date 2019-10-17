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
	int mese1, mese2, tot;
public:
	Item() {}
	Item(int a, int b, int c) { mese1 = a;mese2 = b;tot=c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key1() const { return mese1; }
	int key2() const { return mese2; }
	int spesa() const { return tot; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key1() << " " << i.key2() << " " << i.spesa() << endl;
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

class Item2 {
private:
	int mese1,  tot;
public:
	Item2() {}
	Item2(int a,  int c) { mese1 = a;tot = c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key1() const { return mese1; }
	
	int spesa() const { return tot; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item2& i)
{
	return s << i.key1() << " "  << i.spesa() << endl;
}


#endif

