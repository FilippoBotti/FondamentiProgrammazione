#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
#include<string>
using namespace std;



// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef string Key1;
static string maxKeystr = "1000";
class Item
{
private:
	
	string ufficio;
	
public:
	Key1 keyval;
	Item()
	{
		keyval = maxKeystr;
	}
	Key1 key()
	{
		return keyval;
	}
	
	string offie()
	{
		return ufficio;
	}
		
	int null()
	{
		return keyval == maxKeystr;
	}

	

	// legge da tastiera i dati (chiave, valore) di un elemento
	int scan(istream& is = cin)
	{
		is >> keyval >> ufficio;
		return !(cin.fail());
	}
	void set_val(Key1 a, string b) {
		keyval = a;
		ufficio = b;

	}
	void show(ostream& os = cout)
	{
		os << keyval << " " << ufficio << endl;
	}
};
ostream& operator<<(ostream& os, Item& x)
{
	x.show(os); return os;
}

static int maxKey = 1000;

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key2;

class Item2
{
private:

	string nome;

public:
	Key2 keyval;
	Item2()
	{
		keyval = maxKey;
	}
	Key2 key()
	{
		return keyval;
	}

	string name()
	{
		return nome;
	}

	int null()
	{
		return keyval == maxKey;
	}



	// legge da tastiera i dati (chiave, valore) di un elemento
	int scan(istream& is = cin)
	{
		is >> keyval >> nome;
		return !(cin.fail());
	}
	void set_val(Key2 a, string b) {
		keyval = a;
		nome = b;

	}
	void show(ostream& os = cout)
	{
		os << keyval << " " << nome << endl;
	}
};
ostream& operator<<(ostream& os, Item2& x)
{
	x.show(os); return os;
}



#endif