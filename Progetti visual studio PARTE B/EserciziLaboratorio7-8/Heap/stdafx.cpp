// stdafx.cpp : file di origine che include solo le inclusioni standard
// Heap.pch sarà l'intestazione precompilata
// stdafx.obj conterrà le informazioni sui tipi precompilati

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap.h"

int main(int argc, char** argv) {

	MINPQ<int> coda(4);
	int Len[4] = { 4,3,2,6 };
	for (int i = 0;i < 4;i++) {
		coda.insert(Len[i]);
	}
	cout << coda.length();
	int costo = 0;
	while (coda.length() >1) {
		int first, second;
		first = coda.getmin();
		second = coda.getmin();
		costo += first + second;
		coda.insert(first+second);
	}
	
	cout << "Costo totale: "  << costo << endl;
	



	
	
	

	int fine;
	cin >> fine;
	return 0;
}
