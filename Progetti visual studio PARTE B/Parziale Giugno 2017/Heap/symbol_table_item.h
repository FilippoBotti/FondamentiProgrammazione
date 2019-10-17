#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKey = 1000;

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key;

class Item
{
private:
	float info;
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
	void random_element()
	{
		keyval = 1000 * (1.0*rand() / RAND_MAX);
		info = 1.0*(1.0*rand() / RAND_MAX);
	}

	// legge da tastiera i dati (chiave, valore) di un elemento
	int scan(istream& is = cin)
	{
		is >> keyval >> info;
		return !(cin.fail());
	}
	void show(ostream& os = cout)
	{
		os << keyval << " " << info << endl;
	}
};
ostream& operator<<(ostream& os, Item& x)
{
	x.show(os); return os;
}


#endif