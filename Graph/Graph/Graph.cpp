// Graph.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <windows.h>
#include<conio.h>
#include<vector>

using namespace std;
struct Edge
{
	int v, w;
	Edge(int v = -1, int w = -1) : v(v), w(w) { }
};
class GRAPH
{
private:
	// Код, зависящий от реализации
public:
	GRAPH(int, bool);
	~GRAPH();
	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);
	class adjIterator
	{
	public:
		adjIterator(const GRAPH &, int);
		int beg();
		int nxt();
		bool end();
	};
};
template <class Graph>
vector <Edge> edges(Graph &G)
{
	int E = 0;
	vector <Edge> a(G.E());
	for (int v = 0; v < G.V(); v++)
	{
		typename Graph::adjIterator A(G, v);
		for (int w = A.beg(); !A.end(); w = A.nxt())
			if (G.directed() || v < w)
				a[E++] = Edge(v, w);
	}
	return a;
}
template <class Graph>
class IO
{
public:
	static void show(const Graph &);
	static void scanEZ(Graph &);
	static void scan(Graph &);
};
template <class Graph, class Edge, class EdgePtr>
class MST
{
	const Graph &G;
	vector<EdgePtr> a, mst;
	UF uf;
public:
	MST(Graph &G) : G(G), uf(G.V()), mst(G.V())
	{
		int V = G.V(), E = G.E();
		a = edges<Graph, Edge, EdgePtr>(G);
		sort<EdgePtr>(a, 0, E - 1);
		for (int i = 0, k = 1; i < E && k < V; i++)
			if (!uf.find(a[i]->v, a[i]->w))
			{
				uf.unite(a[i]->v, a[i]->w);
				mst[k++] = a[i];
			}
	}
};
class DenseGRAPH
{
	int Vcnt, Ecnt; bool digraph;
	vector <vector <bool> > adj;
public:
	DenseGRAPH(int V, bool digraph = false) :
		adj(V), Vcnt(V), Ecnt(0), digraph(digraph)
	{
		for (int i = 0; i < V; i++)
			adj[i].assign(V, false);
	}
	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	bool directed() const { return digraph; }
	void insert(Edge e)
	{
		int v = e.v, w = e.w;
		if (adj[v][w] == false) Ecnt++;
		adj[v][w] = true;
		if (!digraph) adj[w][v] = true;
	}
	void remove(Edge e)
	{
		int v = e.v, w = e.w;
		if (adj[v][w] == true) Ecnt—;
		adj[v][w] = false;
		if (!digraph) adj[w][v] = false;
	}
	bool edge(int v, int w) const
	{
		return adj[v][w];
	}
	class adjlterator;
	friend class adjlterator;
};
class DenseGRAPH::adjIterator
{
	const DenseGRAPH &G;
	int i, v;
public:
	adjIterator(const DenseGRAPH &G, int v) :
		G(G), v(v), i(-1) { }
	int beg()
	{
		i = -1; return nxt();
	}
	int nxt()
	{
		for (i++; i < G.V(); i++)
			if (G.adj[v][i] == true) return i;
		return -1;
	}
	bool end()
	{
		return i >= G.V();
	}
};