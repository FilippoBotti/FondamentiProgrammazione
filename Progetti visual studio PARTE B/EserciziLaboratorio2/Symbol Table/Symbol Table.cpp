// Symbol Table.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include "symbol_table.h"

int main(int argc, char **argv[])
{
	srand(time(NULL));
	int N;
	
	ST<Item, Key> st;
	Item x;
	x.random_element();
	Item y;
	y.random_element();
	Item z;
	z.random_element();
	st.insert(x);
	st.insert(y);
	st.insert(z);
	st.show(cout);
	cout << "Elemento con chiave maggiore: " << endl;
	Item max = st.max();
	cout << max;
	cout << "Inserisci la floor_key: " << endl;
	int floor;
	cin >> floor;
	
	cout << "Elemento con chiave maggiore inferiore alla floor_key inserita: " << endl;
	max = st.floor(floor);
	cout << max;
	int a;
	cin >> a;
	return 0;
}
