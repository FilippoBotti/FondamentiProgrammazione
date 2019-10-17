#include "stdafx.h"
#include "Money.h"
#include<iostream>
using namespace std;

Money::Money()
{
	euro = 0;
	cent = 0;
}

void Money::set_euros(int e) {
	euro = e;
}

void Money::set_cent(int c) {
	cent = c;

}


int Money::get_euros() {
	return euro;
}

int Money::get_cent() {
	return cent;
}

Money Money::operator+(Money op2) {
	Money tmp;
	tmp.euro = euro + op2.euro; tmp.cent = cent + op2.cent;
	if (tmp.cent >= 100) {
		tmp.cent = tmp.cent - 100;
		tmp.euro = tmp.euro + 1;
	}
	return tmp;}

Money::~Money()
{
}


CreditCard::CreditCard() {
	name = "William";
	number = "456786";
	

}

void CreditCard::print() {
	cout << "Nome proprietario: " << name << endl << "Numero carta: " << number << endl;
}

Money CreditCard::get_totalcharges() {
	Money total;
	total = total + m;
	return total;

}

void CreditCard::charge(string s, int euro, int cent) {
	m.set_cent(cent);
	m.set_euros(euro);
}