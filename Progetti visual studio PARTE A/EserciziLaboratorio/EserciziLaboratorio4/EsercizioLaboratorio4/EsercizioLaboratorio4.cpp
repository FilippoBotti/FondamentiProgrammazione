// EsercizioLaboratorio4.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include <ctime>
#include <fstream> 
const int N = 2;
using namespace std;


int main()
{
	struct Libro {
		string titolo;
		string autore;
		int anno;
		float prezzo;
	};
	
	int i = 0;
	
	Libro libri[N];
	float prezzo_medio = 0;
	float max = 0;
	int old = 2019;
	srand(time(NULL));
	
	

	for (i = 0;i < N;i++) {
		cout << "Inserisci il titolo del libro " << i << " su " << N << endl;
		cin >> libri[i].titolo;
		cout << "Inserisci l'autore del libro " << i << " su " << N << endl;
		cin >> libri[i].autore;
		cout << "Inserisci l'anno del libro " << i << " su " << N << endl;
		cin >> libri[i].anno;
		libri[i].prezzo = rand() % 201;
	}

	for (i = 0;i < N;i++) {
		prezzo_medio += libri[i].prezzo;
		if (libri[i].prezzo > max) {
			max = libri[i].prezzo;
		}
		if (libri[i].anno < old) {
			old = libri[i].anno;
		}

	}
	prezzo_medio = prezzo_medio / N;

	for (i = 0;i < N;i++) {
		cout << "prezzo " << libri[i].prezzo << endl;
		

	}
	cout << "Il prezzo massimo risulta " << max << endl;
	cout << "Il libro piu' vecchio risale al " << old << endl;


	ofstream myfile("Testo.txt");
	if (myfile.is_open()) { 
		for (i = 0;i < N;i++) {
			myfile << libri[i].titolo << " " << libri[i].autore << " " << libri[i].anno << " " << libri[i].prezzo << "ZELO E MAGNO GAYYYYY" << endl;
		}
		myfile.close();
	}

	cin >> i;
}

