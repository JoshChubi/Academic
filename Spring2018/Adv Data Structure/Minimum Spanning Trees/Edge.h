#ifndef _EDGE_
#define _EDGE_
#include<stdlib.h>
#include <iostream>
using namespace std;

class Edge
{
private:
	int v1;
	int v2;
	bool directed;
	bool weighted;
	double weight;


public:
	Edge();
	Edge(int v1, int v2, bool directed);
	Edge(int v1, int v2, double weight, bool directed);

	int getV1();
	int getV2();
	double getWeight();

	bool isDirected();
	bool isWeighted();

	Edge forUndirected();

};
#endif
