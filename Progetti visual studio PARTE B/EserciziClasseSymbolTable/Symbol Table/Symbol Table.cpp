// Symbol Table.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include "symbol_table.h"

int main(int argc, char **argv[])
{
	
	ST<Item, Key> st2;
	Item y;
	y.set_element(1,99);
	Item z;
	z.set_element(1, 200);
	st2.insert(y);
	st2.insert(z);
	st2.show(cout);
	cout << st2.count() << " numeri " << endl;
	int a;
	cin >> a;
	return 0;
}
