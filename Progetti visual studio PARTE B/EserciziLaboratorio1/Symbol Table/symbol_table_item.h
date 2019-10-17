#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions
#include<string>
#include <iostream>
using namespace std;

static int maxKey = 1000;

// la classe ST � predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key;

class Item
{
private:
	string nome;
	int anni;
public:
	Key keyval;
	
	Item()
	{
		keyval = maxKey;
	}
	Key key()
	{
		return keyval;
	}
	int null()
	{
		return keyval == maxKey;
	}

	// genera casualmente i dati (chiave, valore) di un elemento
	void set_element(Key k, string n, int a)
	{
		keyval = k;
		nome = n;
		anni = a;
	}

	// legge da tastiera i dati (chiave, valore) di un elemento
	int scan(istream& is = cin)
	{
		is >> keyval >> nome >> anni;
		return !(cin.fail());
	}
	void show(ostream& os = cout)
	{
		os << keyval << " " << nome << " " << anni << endl;
	}
};
ostream& operator<<(ostream& os, Item& x)
{
	x.show(os); return os;
}


#endif