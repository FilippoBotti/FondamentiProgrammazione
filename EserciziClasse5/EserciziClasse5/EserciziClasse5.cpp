// EserciziClasse5.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#define x 3
#define y 3

using namespace std;

int main()
{
	int matrix[y][x] = { {3,10,5},
	{7,6,9},
	{3,6,1} };
	int somma = 0;
	int max = 0;
	int i, j;
	int cont = 0, pos = 0;
	for (i = 0;i < y;i++) {
		somma = 0;
		cont += 1;
		for (j = 0;j < x;j++) {
			somma += matrix[j][i];
			
		}
		if (somma > max) {
			max = somma;
			pos = cont;
		}
		
	}
	for (i = 0;i < y;i++) {
		for (j = 0;j < x;j++) {
			cout << matrix[i][j] << " ";;
		}
		cout << " " << endl;
	}
	cout << "La somma maggiore risulta " << max << endl;
	cout << "La colonna e' la " << pos << endl;
	cin >> i;
	
    return 0;
}

