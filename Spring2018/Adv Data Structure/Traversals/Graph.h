#include<list>
#include"Edge.h"

using namespace std;

class Graph {
public:
	Graph(int numVertices, bool directed, bool weighted);
	
	int getNumVertices() const;
	int getNumEdges() const;

	bool isDirected() const;
	bool isWeighted() const;

	void addEdge(Edge e);

	list<Edge> getAdjacentList(int v) const;
	Edge getEdge(int v1, int v2) const;
private:
	int numVertices;
	int numEdges = 0;

	bool directed;
	bool weighted;

	list<Edge> * edgeList;
};
