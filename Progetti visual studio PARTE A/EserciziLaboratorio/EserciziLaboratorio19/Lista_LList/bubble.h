#ifndef BUBBLE_H
#define BUBBLE_H

#include "ListTest.h"

void bubble(LList<Item>& L1, int l, int r)
{
	/*
	int n = L1.length();
	Item *a;
	a = new Item[n];
	int j = 0;
	
	for (L1.moveToStart();L1.currPos() < L1.length();L1.next()) {
		a[j] = L1.getValue();
		
		j++;
	}
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {

			compexch(a[j - 1], a[j]);
		}
	}
	L1.clear();
	

	for (int j = 0;j < n;j++) {
		L1.append(a[j]);
	}



	for (int i = l; i < r; i++) {
	for (int j = r; j > i; j--) {

	compexch(a[j - 1], a[j]);
	}
	}
	*/
	Item it_temp;
	Item it_curr;
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			L1.moveToPos(j-1);
			it_curr = L1.getValue();
			L1.moveToPos(j);
			it_temp = L1.getValue();
			if (it_temp.key() < it_curr.key())
			{
				L1.moveToPos(j-1);
				L1.remove();
				
				L1.insert(it_temp);
				L1.moveToPos(j);
				L1.remove();
				
				L1.insert(it_curr);
			}
		}
	}
	L1.moveToStart();


}
#endif