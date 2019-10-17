// Symbol Table.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

#include "symbol_table.h"

int main(int argc, char **argv[])
{
	srand(time(NULL));
	int N;
	int maxN = 1;
	int sw = 2;
	ST<Item, Key> st;
	//ST_ordered<Item, Key> st(maxN);
	for (N = 0; N < maxN; N++)
	{
		Item v;
		if (sw) v.random_element(); else if (!v.scan()) break;
		if (!(st.search(v.key())).null()) continue;
		st.insert(v);
		
	}
	cout << endl; st.show(cout);
	cout << N << " keys" << endl;
	cout << st.count() << " distinct keys" << endl << endl;

	Item x;
	
	x = st.select(1);
	st.remove(x);
	st.show(cout);
	cout << st.count() << " distinct keys" << endl;
	int a;
	cin >> a;
	return 0;
}
