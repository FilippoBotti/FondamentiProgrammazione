// EserciziLaboratorio23.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include<cstdlib>

using namespace std;

string Reverse_string(string s) {
	string b;
	if (s.length()==1) {
		return s;
	}
	else {
		char i;
		i = s[s.length() - 1];
		s[s.length() - 1] = s[0];
		s[0] = i;
		b = i + Reverse_string(s.substr(1, s.length() - 2)) + s[s.length() - 1];
		return b;
	}
	
		
	
	
}
int main()
{	
	string a,b;
	
	cout << "Inserisci la stringa " << endl;
	getline (cin,a);
	
	
	
	b = Reverse_string(a);
	cout << "La stringa rovesciata e': " <<  b << endl;
	cin >> a;
    return 0;
}

