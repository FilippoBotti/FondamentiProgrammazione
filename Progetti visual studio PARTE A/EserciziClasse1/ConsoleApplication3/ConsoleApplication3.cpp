// ConsoleApplication3.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<string>
#define N 11
using namespace std;

string Ricerca(int n, int vett[N]) {
	string result;
	if (vett[N / 2] == n) {
		result = to_string(n);

	}
	else if (vett[N / 4] == n) {
		result = to_string(n);
	}
	else {
		result = "Non trovato";
	}
	return result;
}

int main()
{



	int vett[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10 }, j;
	string risultato;
	cout << "Inserisci il numero da cercare " << endl;
	cin >> j;
	risultato = Ricerca(j, vett);
	cout << "La posizione del tuo numero risulta : " << risultato << endl;


	cin >> j;
    return 0;
}

