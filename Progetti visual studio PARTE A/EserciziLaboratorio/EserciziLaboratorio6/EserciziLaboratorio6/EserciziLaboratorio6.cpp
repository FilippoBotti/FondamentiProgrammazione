// EserciziLaboratorio6.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include <string>
#define N 10

using namespace std;

template <typename T> 
T Ricerca(T v[N], int n) {
	T vett[N];
	int cont = 0;
	T rip ;
	int max = 0;
	int i = 0;int j = 0;
	for (i = 0;i < N;i++) {
		vett[i] = v[i];
	}

	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++) {
			if (v[i] == vett[j]) {
				cont += 1;
			}
		}
		if (cont > max) {
		rip = v[i];
		max = cont;
	}
		cont = 0;

	}
	return rip;
	
}
int main()
{
	int i;
	cout << "Che tipo di ricerca vuoi fare?(0 = double, 1 = int, n = string) " << endl;
	cin >> i;
	if (i == 0) {
		double vett[N] = { 2.3,2.3,2.3,2.3,2.3,2.3,2.3,4,5,90 };
		double found = 0;
		found = Ricerca(vett, N);
		cout << "L'elemento piu' ripetuto risulta:  " << found << endl;
	}
	else if (i == 1) {
		int vett[N] = { 1,2,3,2,1,2,3,55,4,3 };
		int found = 0;
		found = Ricerca(vett, N);
		cout << "L'elemento piu' ripetuto risulta:  " << found << endl;
	}
	else {
		string vett[N] = { "latte ",  "pippo", "topolino", "minni", "paperino", "pippo", "pippo" , "donnarumma" , "bonaventura" , "andre silva" };
		string found = " ";
		found = Ricerca(vett, N);
		cout << "L'elemento piu' ripetuto risulta:  " << found << endl;
	}
	
	
	cin >> i;
    return 0;
}

