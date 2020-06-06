#include"Graph.h"

Graph::Graph(int numVertices, bool directed, bool weighted)
{
	this->numVertices = numVertices;
	this->directed = directed;
	this->weighted = weighted;
	edgeList = new list<Edge>[numVertices];
}

int Graph::getNumVertices() const 
{
	return numVertices;
}

int Graph::getNumEdges() const
{
	if (directed) {
		return numEdges;
	}
		
	return numEdges/2;
}

bool Graph::isDirected() const 
{
	return directed;
}

bool Graph::isWeighted() const
{
	return weighted;
}

void Graph::addEdge(Edge e) 
{
	edgeList[e.getV1()].push_back(e);
	numEdges++;
}

list<Edge> Graph::getAdjacentList(int v) const
{
	return edgeList[v];
}

Edge Graph::getEdge(int v1, int v2) const
{

	for (list<Edge>::iterator index = edgeList[v1].begin(); index != edgeList[v1].end(); index++)
	{
		if (index->getV2() == v2)
		{
			return *index;
		}
	}

	return Edge(-1, -1, false, false, -1);
}
