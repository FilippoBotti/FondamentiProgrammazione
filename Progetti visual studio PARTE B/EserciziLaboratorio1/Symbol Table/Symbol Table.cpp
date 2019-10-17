// Symbol Table.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include "symbol_table.h"

int main(int argc, char **argv[])
{
	srand(time(NULL));
	int maxN = 3;
	
	ST<Item, Key> st;
	Item piero;
	piero.set_element(50, "Piero", 20);
	st.insert(piero);
	//ST_ordered<Item, Key> st(maxN);
	for (int i = 0;i < maxN;i++) {
		Item x;
		
		cout << "Inserici nome ed eta' " << endl;
		x.scan();
		st.insert(x);
	}
	cout << endl; st.show(cout);
	
	int a;
	cin >> a;
	return 0;
}
