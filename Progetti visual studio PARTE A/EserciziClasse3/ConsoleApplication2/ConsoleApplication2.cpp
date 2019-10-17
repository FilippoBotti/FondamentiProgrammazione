//In un esercizio di telepatia, un sensitivo scommette di essere in grado di indovinare almeno 3 numeri 
//consecutivi, in una sequenza di N numeri interi pensati da uno spettatore. Si scriva un programma che 
//carichi da un file la sequenza dei numeri dello spettatore (il file contiene N nella prima riga e i numeri della sequenza nella seconda riga separati da spazi), e verifichi se il sensitivo dice la verità.
//Il programma acquisisce dal sensitivo i 3 numeri (da tastiera).
//Il programma legge il file e crea un array di dimensione N, con allocazione dinamica, e verifica se esiste, nella sequenza di N numeri, una sotto‐sequenza di 3 numeri esattamente 
//uguale a quella inserita dal sensitivo.
#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath>


using namespace std;

int main() {
	int N, i, j, trovato,n;
	int telepata[3];

	ifstream myfile("sequenza.txt");
	myfile >> N;
	int *sequenza = new int[N];
	for (i = 0; i < N; i++) {
		myfile >> sequenza[i];
	}

	cout << "Sequenza letta da file" << endl;
	for (i = 0; i < N; i++) {
		cout << sequenza[i] << " " ;
	}
	cout << " " << endl;
	
	for(i=0;i<3;++i) {
	cout << "Inserisci il numero " << endl;
	cin >> n;
	telepata[i] = n;
}
	for (i = 0;i < 3;++i) {
		cout << telepata[i] << endl;
	}
	for (i = 0;i < N;i++) {
		if (sequenza[i] == telepata[0]) {
			
			if (sequenza[i + 1] == telepata[1]) {
				
				if (sequenza[i + 2] == telepata[2]) {
					cout << "Hai vinto" << endl;
				}
			}
		}
	}







	cin >> N;

}