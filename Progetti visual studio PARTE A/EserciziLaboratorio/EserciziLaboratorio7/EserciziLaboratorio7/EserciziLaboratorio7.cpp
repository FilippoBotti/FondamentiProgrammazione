// EserciziLaboratorio7.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "Pair.h"
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main()
{
	Pair<int> x;
	Pair<int> y;
	Pair<int> z;
	int i;
	x.set_Pair(8, 9);
	y.set_Pair(2, 1);
	z = x.sum(y);
	cout << z.get_element(0) << " " << z.get_element(1); 
	cin >> i;
    return 0;
}

