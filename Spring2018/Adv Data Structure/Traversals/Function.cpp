#include "Function.h"
Graph * graphIt(const string & fileName)
{
	char directedInput;
	char weightedInput;
	int vertices;
	int v1;
	int v2;
	int weight;
	bool directed;
	bool weighted;
	string holder;

	ifstream inFile;
	inFile.open(fileName);

	inFile >> vertices >> directedInput >> weightedInput;

	if (directedInput == 'd' || directedInput == 'D') {
		directed = true;
	}
	else if (directedInput == 'u' || directedInput == 'U') {
		directed = false;
	}
	else
	{
		cout << "Not valid input for Directed\n";
		system("pause");
		return 0;
	}

	if (weightedInput == 'w' || weightedInput == 'W') {
		weighted = true;
	}
	else if (weightedInput == 'n' || weightedInput == 'N') {
		weighted = false;
	}
	else
	{
		cout << "Not valid input for Weighted\n";
		system("pause");
		return 0;
	}

	Graph * myGraph = new Graph(vertices, directed, weighted);

	if (weighted)
	{
		while (!inFile.eof())
		{
			inFile >> v1 >> v2 >> weight;
			getline(inFile, holder);

			if (directed)
			{
				myGraph->addEdge(Edge(v1, v2, directed, weighted, weight));
			}
			else
			{
				myGraph->addEdge(Edge(v1, v2, directed, weighted, weight));
				myGraph->addEdge(Edge(v2, v1, directed, weighted, weight));
			}
		}
	}
	else
	{
		while (!inFile.eof())
		{
			inFile >> v1 >> v2;
			getline(inFile, holder);

			if (directed) {
				myGraph->addEdge(Edge(v1, v2, directed, weighted));
			}
			else {
				myGraph->addEdge(Edge(v1, v2, directed, weighted));
				myGraph->addEdge(Edge(v2, v1, directed, weighted));
			}
		}
	}

	inFile.close();

	return myGraph;
}

void pre_visit(int vertex) {
	cout << vertex << " ";
}

void BFS(const Graph * graph, int start) {
	int currentVertex;

	bool * visited = new bool[graph->getNumVertices()];

	for (int i = 0; i < graph->getNumVertices(); i++)
	{
		visited[i] = false;
	}
	visited[start] = true;

	queue<int> Queue;
	Queue.push(start);

	while (!Queue.empty())
	{
		currentVertex = Queue.front();
		Queue.pop();

		pre_visit(currentVertex);

		list<Edge> currentAdjacents = graph->getAdjacentList(currentVertex);

		for (list<Edge>::iterator index = currentAdjacents.begin(); index != currentAdjacents.end(); index++)
		{
			if (visited[index->getV2()])continue;

			visited[index->getV2()] = true;
			Queue.push(index->getV2());
		}

	}
}

void DFS(const Graph * graph, int start)
{
	bool * visited = new bool[graph->getNumVertices()];

	for (int i = 0; i < graph->getNumVertices(); i++)
	{
		visited[i] = false;
	}

	RDFS(graph, visited, start);
}

void RDFS(const Graph * graph, bool visited[], int v) {
	pre_visit(v);
	visited[v] = true;

	list<Edge> currentAdjacents = graph->getAdjacentList(v);

	for (list<Edge>::iterator index = currentAdjacents.begin(); index != currentAdjacents.end(); index++)
	{
		if (visited[index->getV2()]) continue;

		RDFS(graph, visited, index->getV2());
	}
}

void printIt(Graph * graph)
{
	for (int index = 0; index < graph->getNumVertices(); index++)
	{
		cout << index << ":";
		list<Edge> currentAdjacents = graph->getAdjacentList(index);
		for (list<Edge>::iterator index = currentAdjacents.begin(); index != currentAdjacents.end(); index++)
		{
			cout << " ( " << index->getV1() << " , " << index->getV2() << " ) ";
		}
		cout << endl;
	}
}
