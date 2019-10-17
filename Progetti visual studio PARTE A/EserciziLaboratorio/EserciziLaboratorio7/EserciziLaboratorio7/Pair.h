#pragma once

template <class T>
class Pair
{
public:
	Pair();
	void set_Pair(T,T);
	T get_element(int);
	Pair<T> sum(Pair);
	

private:
	T a[2];
};

#include "stdafx.h"
#include "Pair.h"

template <class T>
Pair<T>::Pair()
{
	a[0] = 0;
	a[1] = 0;



}

template <class T>
void Pair<T>::set_Pair(T x, T y) {
	a[0] = x;
	a[1] = y;

}

template <class T>
T Pair<T>::get_element(int position) {
	return a[position];

}

template <class T>
Pair<T> Pair<T>::sum(Pair x) {
	Pair<T> sum;
	T y, z;
	y = a[0] + x.get_element(0);
	z = a[1] + x.get_element(1);
	sum.set_Pair(y, z);
	return sum;



};




