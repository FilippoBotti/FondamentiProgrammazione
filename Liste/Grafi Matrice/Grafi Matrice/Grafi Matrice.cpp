// Grafi Matrice.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"


// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple program to test graph construction:
// Reads graph from a file and builds it.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency Matrix representation

#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency Matrix
#include "grmat.h"


// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test harness for the depth first search traversal code
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency Matrix representation

#include "book.h"
#include "grmat.h"
#include "graphutil.h"

// Start with some implementations for the abstract functions
void PreVisit(Graph* G, int v) {
	cout << "PreVisit vertex " << v << "\n";
}

void PostVisit(Graph* G, int v) {
	cout << "PostVisit vertex " << v << "\n";
}

void DFS(Graph* G, int v) { // Depth first search
	PreVisit(G, v);           // Take appropriate action
	G->setMark(v, VISITED);
	for (int w = G->first(v); w<G->n(); w = G->next(v, w))
		if (G->getMark(w) == UNVISITED)
			DFS(G, w);
	//PostVisit(G, v);          // Take appropriate action
}

// Test the generalized traversal function

// Start with some implementations for the abstract functions
void doTraverse(Graph* G, int v) {
	cout << "doTraverse vertex " << v << "\n";
	DFS(G, v);
}

void graphTraverse(Graph* G) {
	int v;
	for (v = 0; v<G->n(); v++)
		G->setMark(v, UNVISITED);  // Initialize mark bits
	for (v = 0; v<G->n(); v++)
		if (G->getMark(v) == UNVISITED)
			doTraverse(G, v);
}


void DFS_component(Graph* G, int v, int component) {
	G->setMark(v, component);
	for (int w = G->first(v); w<G->n(); w = G->next(v, w))
		if (G->getMark(w) == 0)
			DFS_component(G, w, component);
}

void concom(Graph* G) {
	int i;
	int component = 1;   // Counter for current component
	for (i = 0; i<G->n(); i++) // For n vertices in graph
		G->setMark(i, 0); // Vertices start in no component
	for (i = 0; i<G->n(); i++)
		if (G->getMark(i) == 0) // Start a new component
			DFS_component(G, i, component++);
}


int main(int argc, char** argv) {
	Graph* G;




	G = createGraph<Graphm>(myfile);
	

	Gprint(G);

	cout << "next(1, 4)=" << G->next(1, 4) << endl;
	cout << "first(5)=" << G->first(5) << endl;
	cout << "next(1, 5)=" << G->next(1, 5) << endl;
	cout << "next(1, 2)=" << G->next(1, 2) << endl;
	cout << "next(0, 2)=" << G->next(0, 2) << endl;
	G->setEdge(1, 4, 5);
	Gprint(G);
	G->delEdge(1, 4);
	Gprint(G);
	cout << "Number of vertices is " << G->n() << "\n";
	cout << "Number of edges is " << G->e() << "\n";
	return 0;
}
