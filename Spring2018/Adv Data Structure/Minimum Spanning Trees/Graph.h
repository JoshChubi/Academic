#ifndef _GRAPH_
#define _GRAPH_
#include"Edge.h"
#include<list>
using namespace std;

class Graph
{
private:
	int edgeCount;
	int vertCount;
	bool directed;
	bool weighted;
	list<Edge> *edgeList;

public:
	Graph(int n, bool directed, bool weighted);

	int getNumVertices();
	int getNumEdges();

	bool isDirected();
	bool isWeighted();

	void addEdge(Edge e);

	Edge getEdge(int v1, int v2);

	list<Edge> getAdjacentList(int v);
};
#endif  
