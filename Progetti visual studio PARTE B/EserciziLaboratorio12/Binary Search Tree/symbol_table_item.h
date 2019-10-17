#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions
#include<string>
#include <iostream>
using namespace std;

static int maxKey = 1000;

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key;

class Item
{
private:
	string nome,mail;
	int voto;
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
		return nome;
	}
	int mark()
	{
		return voto;
	}
	string email()
	{
		return mail;
	}
	int null()
	{
		return keyval == maxKey;
	}

	void show(ostream& os = cout)
	{
		if (voto == 0) {
			os << keyval << " " << nome << " " << "INSUFFICIENTE" << " " << mail << endl;
		}
		else {
			os << keyval << " " << nome << " " << voto << " " << mail << endl;
		}
	}
	void set_val(Key h,string a, int b, string c) {
		keyval = h;
		nome = a;
		voto = b;
		mail = c;
	}
};
ostream& operator<<(ostream& os, Item& x)
{
	x.show(os); return os;
}


#endif