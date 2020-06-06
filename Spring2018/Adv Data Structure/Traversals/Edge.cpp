#include"Edge.h"

Edge::Edge(int v1, int v2, bool directed, bool weighted, double weight)
{
	this->v1 = v1;
	this->v2 = v2;
	this->directed = directed;
	this-> weighted = weighted;
	this->weight=weight;
}

int Edge::getV1() const
{
	return v1;
}

int Edge::getV2() const
{
	return v2;
}
