#include "Edge.h"

Edge::Edge()
{
	v1 = NULL;
	v2 = NULL;
	directed = NULL;
	weighted = NULL;
	weight = 0;
}

Edge::Edge(int v1, int v2, bool directed)
{
	this->v1 = v1;
	this->v2 = v2;
	this->directed = directed;
	weighted = false;
	weight = 0;
}

Edge::Edge(int v1, int v2, double weight, bool directed)
{
		this->v1 = v1;
		this->v2 = v2;
		this->directed = directed;
		this->weight = weight;
		weighted = true;
}

int Edge::getV1()
{
	return v1;
}

int Edge::getV2()
{
	return v2;
}

double Edge::getWeight()
{
	return weight;
}

bool Edge::isDirected()
{
	return directed;
}

bool Edge::isWeighted()
{
	return weighted;
}

Edge Edge::forUndirected()
{
	Edge revEdge = *this;
	revEdge.v1 = v2;
	revEdge.v2 = v1;
	return revEdge;
}
