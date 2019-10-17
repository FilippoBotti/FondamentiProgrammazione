// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked queue class

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lqueue.h"

#include "LQueueTest.h"

//Si vuole simulare un sistema in cui sono presenti M code a cui devono essere assegnati N clienti 
//che attendono di essere serviti. Ad ogni iterazione viene selezionata una coda in modo casuale 
//in cui inserire il nuovo cliente e una seconda coda, sempre in modo casuale, da cui prelevare 
//il cliente in testa (se esiste) da servire.




// Main routine for array-based queue driver class
int main(int argc, char** argv) {
	srand(time(NULL));
	LQueue<Item> stampante;
	int timestamp, id, pagine, JOB;
	JOB = 1;
	int cont = 1;
	timestamp = 1;
	int vett[10] = { };

	int b=0, a = 0;
	while (timestamp < 28800) {
		if (stampante.length() > 0) {
			b++;
			vett[stampante.frontValue().name()]++;
		}
		int number = rand() % 180;
		if (number % 180 == 0) {
			int pag = (rand() % 19) +1;
			int id = rand() % 10;
			Item lavoro(timestamp, pag, id, JOB);
			cout << "Timestamp,pagine,id e JOB del lavoro mandato in stampa: " << lavoro << endl;
			
			stampante.enqueue(lavoro);
			if (cont < 0) {
				cont = stampante.frontValue().pag();
			}
			JOB++;
		}
		if (cont <= 0) {
			Lqueueprint(stampante);
			if (stampante.length() > 0) {
				cout << "Lavoro finito: " << stampante.frontValue().key() << " " << stampante.frontValue().pag() << " " << stampante.frontValue().name() << " " << stampante.frontValue().job() << endl;
				cout << timestamp << endl;
				stampante.dequeue();
				if (stampante.length() > 0) {
					cont = stampante.frontValue().pag();
					Lqueueprint(stampante);
				}
			}
		}
		timestamp++;
		cont--;
	}
	for (int i = 0; i < 10 ;i++) {
		cout << "Il lavoratore " << i+1 << "Ha stampato: " << vett[i] << "pagine " << endl;
	}
	Lqueueprint(stampante);
	cout << "Le pagine stampate durante la giornata sono: " <<  b << endl;
	int j;
	cin >> j;
}