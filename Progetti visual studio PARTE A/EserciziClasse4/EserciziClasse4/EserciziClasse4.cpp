// EserciziClasse4.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include <sstream>
using namespace std;


int main()
{
	string frase, reverse;
	char max = 'a';
	int n = 0,h;
	int cont = 0,pos=0,posizione=0;
	cout << "Inserisci la frase " << endl;
	getline(cin, frase);
	reverse = frase;
	for (auto i:frase) {
		pos += 1;
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
			n += 1;
		}
		if (i > max) {
			max = i;
			posizione = pos;
		}
	}
	
	cont = frase.length() ;
	for (h = 0;h < frase.length();h++) {
		cont = cont - 1;
		reverse[h] = frase[cont];
		
		
	}

	cout << "Nella frase sono presenti " << n << " vocali " << endl;
	cout << "Il carattere massimo e' " << max << " e la sua posizione e' " << posizione << endl;
	cout << "La stringa invertita e' " << reverse << endl;
	istringstream str(frase);
	string word;
	
	while (str >> word ){
		word[0] = toupper(word[0]);
		cout << word << " ";
	}

	cin >> n;
    return 0;
}

