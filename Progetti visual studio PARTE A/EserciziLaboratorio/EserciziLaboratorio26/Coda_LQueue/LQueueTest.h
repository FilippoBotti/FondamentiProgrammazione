// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LQUEUETEST_H
#define LQUEUETEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lqueue.h"

// Your basic int type as an object.
class Item {
private:
	int timestamp,pagine,id,JOB;
public:
	Item(){}
	Item(int a,int  b,int  c, int  d) { timestamp = a;pagine = b;id = c;JOB=d; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return timestamp; }
	int pag() const { return pagine;  }
	int name() const { return id; }
	int job() const { return JOB; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key() << " " << i.pag() << " " << i.name() << " " << i.job() << endl;
}



// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print the queue
template <typename E>
void Lqueueprint(LQueue<E>& Q) {
	for (int i = 0; i<Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}

#endif

