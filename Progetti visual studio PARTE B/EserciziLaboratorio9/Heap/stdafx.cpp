// stdafx.cpp : file di origine che include solo le inclusioni standard
// Heap.pch sarà l'intestazione precompilata
// stdafx.obj conterrà le informazioni sui tipi precompilati

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap.h"


int main(int argc, char** argv) {

	const int k = 3, N = 4;
	int arr[k][N] = { {1,3,5,7},{ 2,4,6,8},{0,9,10,11 } };
	int out[k*N];
	MINPQ<Item> coda(k);
	for (int i = 0;i < k;i++) {
		int pos = 0;
		Item a(arr[i][pos],i,pos+1);
		coda.insert(a);
		cout << a << endl;
	}
	
	for(int i=0;i<k*N;i++){
		Item extraxt = coda.getmin();
		out[i] = extraxt.valore();
		cout << "a" << extraxt <<  endl;
		
		if (extraxt.fut() < 4 && extraxt.ind() < 3) {
			Item insert(arr[extraxt.ind()][extraxt.fut()], extraxt.ind(), extraxt.fut() + 1);
			coda.insert(insert);
		}
		
	}
	cout << "Array ordinato: ";
	for (int i = 0;i < k*N;i++) {
		cout << out[i] << " ";
	}
	int fine;
	cin >> fine;
	return 0;
}


		/*
		const int k = 3, n = 4;
		int arr[k][n] = { { 1, 3, 5, 7 },
		{ 2, 4, 6, 8 },
		{ 0, 9, 10, 11 } };

		int sorted_array[n*k];

		MINPQ<Item> minheap(k);

		for (int i = 0; i<k; i++)
		{
			Item it(arr[i][0], i, 1);
			minheap.insert(it);
		}

		int j = 0;
		for (int i = 0; i<n*k; i++)
		{
			Item it = minheap.getmin();
			sorted_array[j] = it.key();

			if (it.next_element<n)
			{
				Item toinsert(arr[it.array_id][it.next_element], it.array_id, it.next_element + 1);
				minheap.insert(toinsert);
			}
			j++;
		}

		cout << endl << "sorted_array=";
		for (int i = 0; i<n*k; i++)
			cout << sorted_array[i] << " ";

		
	


*/


	

