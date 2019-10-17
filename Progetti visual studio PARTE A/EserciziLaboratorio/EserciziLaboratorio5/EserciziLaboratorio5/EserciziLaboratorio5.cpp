// EserciziLaboratorio5.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include"Money.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

ostream& operator<<(ostream& os, Money m)
{
	cout << m.get_euros() << "," << m.get_cent() << " Euro" << endl;
	return os;
}

int main()
{
	int i;
	string spesa;
	int euro, cent;
	Money m;
	Money totale;
	CreditCard carta;

	ifstream myfile("charges.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> spesa >> euro >> cent;
			m.set_euros(euro);
			m.set_cent(cent);
			carta.charge(spesa, m.get_euros(), m.get_cent());
			totale =totale+ carta.get_totalcharges();
		}
	}
	carta.print();
	cout << "Totale spesa: " << totale << endl;

	
	
	
	
	cin >> i;
	
    return 0;
}

