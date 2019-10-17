#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
#include <string>
using namespace std;

static int maxKey = 1000;

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key;

class Item
{
private:
	string info;
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
	string name()
	{
		return info;
	}
	int null()
	{
		return keyval == maxKey;
	}

	// genera casualmente i dati (chiave, valore) di un elemento
	
	void set_element(Key b,string a)
	{
		info = a;
		keyval = b;
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