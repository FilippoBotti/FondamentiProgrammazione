#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
class Money
{
public:
	Money();
	void set_euros(int);
	int get_euros();
	void set_cent(int);
	int  get_cent();
	
	~Money();
	Money operator+(Money op2);
	
private:
	int euro,cent;
};

class CreditCard
{
public:
	CreditCard();
	void print();
	Money get_totalcharges();
	void charge(string, int, int);
private:
	Money m;
	string name, number;
};