// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;


static string maxKey = "";

// Your basic int type as an object.
class Item {
private:
	string nome; 
	string citt�;
	int valore;
public:
	Item() { nome = maxKey; }
	Item(string a, string b, int c) { nome = a;citt� = b;valore = c; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	string key() const { return nome; }
	string city() const {
		return citt�;
	}
	int null()
	{
		return nome == maxKey;
	}
	int priorit�() { return valore; }
	bool operator<( Item &other) const{
		if (valore < other.priorit�()) {
			return true;
		}
		else { return false; }
	}
	void show(ostream& os = cout)
	{
		os << nome << " " << valore << " " << citt� << endl;
	}
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key() << " " << i.city();
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



#endif

