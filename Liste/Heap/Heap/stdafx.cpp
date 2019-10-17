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
	srand(time(NULL));

	aPQ<int> priorityq(10);

	priorityq.insert(5);
	priorityq.insert(50);
	priorityq.insert(12);
	priorityq.insert(27);
	int N = 6;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		a[i] = i+2;
		
	}
	a[2] = 1000;
	for (int y = 0;y < N;y++) {
		cout << a[y] << endl;
	}
	
	cout << " " << endl;
	
	fixUp(a,6);
	for (int y = 0;y < N;y++) {
		cout << a[y] << endl;
	}


	
	
	

	int fine;
	cin >> fine;
	return 0;
}
