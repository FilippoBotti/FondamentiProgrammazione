// ConsoleApplication1.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include <cstdlib>

#define N 4
using namespace std;



int main()
{
	float v[N];
	int i = 0, max = 0, min = 1000000;
	float media = 0, x, devstd=0;
	for (i = 0;i < N;i++) {
		cout << "Inserisci il valore da mettere nel vettore " << endl;
		cin >> x;
		v[i] = x;
	}
	for (i = 0;i < N;i++) {
		if (v[i] > max) {
			max = v[i];
		}
		if (v[i] < min) {
			min = v[i];
		}
		media += v[i];
	}
	media = media / N;

	for (i = 0; i<N; i++)
	{
		devstd += (v[i] - media)*(v[i] - media);
	}
	devstd = sqrt(devstd / N);

	cout << "Il massimo risulta " << max << " Il minimo risulta " << min << " La media risulta " << media << " La deviazione standar risulta " << devstd << endl;
	cout << "Premi un tasto per chiudere il programma " << endl;
	cin >> x;
	return 0;
}

