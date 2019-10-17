#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "symbol_table_item.h"
#include"llist.h"
//classi per la realizzazione di una symbol table (dizionario) tramite array con e senza ordinamento delle chiavi 

template <class Item, class Key>
class ST
{
private:
	Item nullItem;
	LList<Item>* st;
	int M;
public:
	ST()
	{
		M = nullItem.key(); st = new LList<Item> [M]; 
	}
	int number = 0;
	~ST() { delete[] st; } // Destructor
						   // restituisce il numero totale di elementi nella symbol table
	int count()
	{
		return number;
	}
	// inserisce un nuovo elemento
	void insert(Item x)
	{
		
		st[x.key()].insert(x);
		number++;
		
	}
	// ricerca un elemento data una chiave in ingresso
	Item search(Key v)
	{
		return st[v];
	}
	// elimina un elemento dalla symbol table
	void remove(Item x)
	{
		
		st[x.key()].clear();
		number--;
		
	}
	// restituisce la testa della lista con chiave selezionata
	Item select(int k)
	{
		for (int i = 0; i < M; i++)
			if (!st[i].null())
				if (k-- == 0)  st[i].moveToStart(); return st[i].getValue();
		return nullItem;
	}
	void show(ostream& os)
	{
		for (int i = 0; i < M; i++)
			if (!st[i].getValue().null()) st[i].getValue().show(os);
	}
};



template <class Item, class Key>
class ST_ordered
{
private:
	Item nullItem, *st;
	int N;
	Item searchR(int l, int r, Key v)
	{
		if (l > r) return nullItem;
		int m = (l + r) / 2;
		if (v == st[m].key()) return st[m];
		if (l == r) return nullItem;
		if (v < st[m].key())
			return searchR(l, m - 1, v);
		else return searchR(m + 1, r, v);
	}
public:
	ST_ordered(int maxN)
	{
		st = new Item[maxN]; N = 0;
	}
	~ST_ordered() { delete[] st; } // Destructor
	int count()
	{
		return N;
	}
	void insert(Item x)
	{
		int i = N++; Key v = x.key();
		while (i > 0 && v < st[i - 1].key())
		{
			st[i] = st[i - 1]; i--;
		}
		st[i] = x;
	}
	Item search(Key v)
	{
		return searchR(0, N - 1, v);
	}
	Item search_slow(Key v)
	{
		for (int i = 0; i < N; i++)
		{
			if (!(st[i].key() < v)) break;
			if (v == st[i].key()) return st[i];
		}
		return nullItem;
	}
	Item select(int k)
	{
		return st[k];
	}
	void show(ostream& os)
	{
		int i = 0;
		while (i < N) st[i++].show(os);
	}

	void remove(Item x)
	{
		int i = 0;
		Key v = x.key();
		while ((i < N) && (v != st[i].key()))
		{
			i++;
		}
		while (i < N - 1)
		{
			st[i] = st[i + 1]; i++;
		}
		if (i != N) N--;
	}
};

#endif