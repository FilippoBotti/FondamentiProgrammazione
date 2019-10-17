// provaselection.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>

using namespace std;

template <typename E>
void exch(E &A, E &B)
{
	E t = A; A = B; B = t;
}

void selection(int a[], int l, int r)
{
	for (int i = l; i < r; i++)
	{
		int min = i;
		for (int j = i + 1; j <= r; j++) {
			cout << a[j] << " e' minore di " << a[min] << " se si " << min << " diventa " << j << endl;
			if (a[j] < a[min]) min = j;
			cout << "confronto " << a[i] << " con " << a[min] <<  endl;
			exch(a[i], a[min]);
			for (int h = 0; h < 7;h++) {
				cout << a[h] << ",";
			}
			cout << endl;
		}
	}
}



int main()
{
	int a[7] = { 5,4,7,6 ,3,2,1};
	selection(a,0,6);
	for (int y = 0;y < 7;y++) {
		cout << "vett" << a[y] << endl;
	}
	int h;
	cin >> h;

    return 0;
}

