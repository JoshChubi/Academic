#include "Graph.h"

Graph::Graph(int n, bool directed, bool weighted)
{
	vertCount = n;
	edgeCount = 0;
	edgeList = new list<Edge>[vertCount];
	this->directed = directed;
	this->weighted = weighted;
}

int Graph::getNumVertices()
{
	return vertCount;
}

int Graph::getNumEdges()
{
	return edgeCount;
}

bool Graph::isDirected()
{
	return directed;
}

bool Graph::isWeighted()
{
	return weighted;
}

void Graph::addEdge(Edge e)
{
	edgeCount++;

	edgeList[e.getV1()].push_back(e);

	if (!directed)
	{
		edgeList[e.getV2()].push_back(e.forUndirected());
	}
}

list<Edge> Graph::getAdjacentList(int v)
{
	if (edgeList[v].size()>0)
		return edgeList[v];

	list<Edge> noAdj;
	return  noAdj;
}

Edge Graph::getEdge(int v1, int v2)
{
	for (list<Edge>::iterator index = edgeList[v1].begin(); index != edgeList[v1].end(); index++)
		if (index->getV2() == v2)
			return *index;

	return Edge();
}
