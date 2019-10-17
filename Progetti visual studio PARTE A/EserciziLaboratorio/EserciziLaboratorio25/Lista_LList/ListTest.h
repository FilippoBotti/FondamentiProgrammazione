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

typedef struct {
	int anno;
	string nome;
	string nazione;
} Ciclista;
// Your basic int type as an object.
class Item {
private:
	Ciclista corridore;
public:
	Item() {}
	Item(Ciclista a) { corridore.anno = a.anno; corridore.nome = a.nome; corridore.nazione = a.nazione; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int year() const { return corridore.anno; }
	string name() const { return corridore.nome; }
	string country() const { return corridore.nazione; }
};


	// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.year() << " " << i.name() << " " << i.country() << endl;
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

class Item2
{
private:
	string nome;
	int vittorie;
public:
	Item2() {}
	Item2(string a, int b) { nome = a; vittorie = b; }
	string name() const { return nome; }
	int vittoria() const { return vittorie; }
};

ostream& operator<<(ostream& s, const Item2& i)
{
	return s << i.name() << " " << i.vittoria() << endl;
}

void bubble(LList<Item2>& L1, int l, int r)
{
	
	Item2 it_temp;
	Item2 it_curr;
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			L1.moveToPos(j - 1);
			it_curr = L1.getValue();
			L1.moveToPos(j);
			it_temp = L1.getValue();
			if (it_temp.vittoria() < it_curr.vittoria())
			{
				L1.moveToPos(j - 1);
				L1.remove();

				L1.insert(it_temp);
				L1.moveToPos(j);
				L1.remove();

				L1.insert(it_curr);
			}
		}
	}
	L1.moveToStart();


}
void bubble2(LList<Item>& L1, int l, int r)
{

	Item it_temp;
	Item it_curr;
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			L1.moveToPos(j - 1);
			it_curr = L1.getValue();
			L1.moveToPos(j);
			it_temp = L1.getValue();
			if (it_temp.year() < it_curr.year())
			{
				L1.moveToPos(j - 1);
				L1.remove();

				L1.insert(it_temp);
				L1.moveToPos(j);
				L1.remove();

				L1.insert(it_curr);
			}
		}
	}
	L1.moveToStart();


}
#endif

