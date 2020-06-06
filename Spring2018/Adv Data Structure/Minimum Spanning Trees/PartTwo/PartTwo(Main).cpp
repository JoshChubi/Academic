#include<iostream>
#include<fstream>
#include<queue>
#include"Graph.h"
#include"Edge.h"
#include"UnionFind.h"

using namespace std;

class compare
{
public:
	int operator() (Edge one, Edge two)
	{
		return one.getWeight() > two.getWeight();
	}
};

ifstream infile;

Graph fillGraph();
void MST(Graph g);

int main()
{
	Graph graph = fillGraph();

	cout << "Minimum Spaning Tree\n";
	MST(graph);

	system("pause");
	return 0;
}



Graph fillGraph()
{
	bool directed=false, weighted=true;
	int numOfVer, v1, v2;
	double weight;
	
	infile.open("input.txt");

	infile >> numOfVer;

	Graph graph(numOfVer, directed, weighted);

	while (!infile.eof())
	{
		if (weighted)
		{
			infile >> v1;
			infile >> v2;
			infile >> weight;
			graph.addEdge(Edge(v1, v2, weight, directed));
		}
		else
		{
			infile >> v1;
			infile >> v2;
			graph.addEdge(Edge(v1, v2, directed));
		}
	}

	infile.close();

	return graph;
}

void MST(Graph g)
{
	UnionFind vertSet(g.getNumVertices());
	bool directed = false;
	bool weighted = true;
	Edge temp;
	Graph mst(g.getNumVertices(), directed, weighted);
	double mstWeight = 0;


	priority_queue<Edge, vector<Edge>, compare> priorityQue;
	for (int i = 0; i < g.getNumVertices(); i++)
	{
		list<Edge> edgeList = g.getAdjacentList(i);
		for (list<Edge>::iterator index = edgeList.begin(); index != edgeList.end(); index++)
			if (index->getV1() > index->getV2())
				priorityQue.push(*index);
	}


	cout << "The Edges are: \n\n";

	while (!priorityQue.empty())
	{
		temp = priorityQue.top();
		priorityQue.pop();

		if ( vertSet.pcFind( temp.getV1() ) != vertSet.pcFind( temp.getV2() ) )
		{
			mst.addEdge(temp);
			vertSet.wUnion(temp.getV1(), temp.getV2());
			cout << " ("<<temp.getV1() << " , " << temp.getV2() << " )\n";
			mstWeight += temp.getWeight();
		}
	}

	cout << "\nMinimum Spaning Tree sum is: " << mstWeight << endl;
}