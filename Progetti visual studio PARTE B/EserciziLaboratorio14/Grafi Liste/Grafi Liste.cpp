// Grafi Liste.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple program to test graph construction:
// Reads graph from a file and builds it.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency List
#include "grlist.h"

// Simple program to test graph construction:
// Version for Adjancency List representation

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test harness for the breadth first search traversal code
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"
#include "grlist.h"
#include "aqueue.h"
#include "graphutil.h"

// Queue used by breadth-first traversal
Queue<int>* Q;

// Start with some implementations for the abstract functions
void PreVisit(Graph* G, int v) {
	cout << "PreVisit vertex " << v << "\n";
}

void PostVisit(Graph* G, int v) {
	cout << "PostVisit vertex " << v << "\n";
}

void BFS(Graph* G, int start, Queue<int>* Q) {
	int v, w;
	Q->enqueue(start);         // Initialize Q
	G->setMark(start, VISITED);
	while (Q->length() != 0) { // Process all vertices on Q
		v = Q->dequeue();
		PreVisit(G, v);          // Take appropriate action
		for (w = G->first(v); w<G->n(); w = G->next(v, w))
			if (G->getMark(w) == UNVISITED) {
				G->setMark(w, VISITED);
				Q->enqueue(w);
			}
	}
}

// Test the generalized traversal function

// Start with some implementations for the abstract functions
void doTraverse(Graph* G, int v) {
	cout << "doTraverse vertex " << v << "\n";
	BFS(G, v, Q);
}

void graphTraverse(Graph* G) {
	int v;
	for (v = 0; v<G->n(); v++)
		G->setMark(v, UNVISITED);  // Initialize mark bits
	for (v = 0; v<G->n(); v++)
		if (G->getMark(v) == UNVISITED)
			doTraverse(G, v);
}


// Test Breadth First Search:
// Version for Adjancency List representation



int main(int argc, char** argv) {
	Graphl G(7);
	srand(time(NULL));
	

	G.create_graph(7, 5);
	

	Gprint(&G);



	int fine;
	cin >> fine;
	return 0;
}
