// Josh Ortiz
#include"UnionFind.h"
#include"Graph.h"
#include"Edge.h"
#include<stack>
#include <stdio.h>    
#include <stdlib.h> 
#include <time.h>

using namespace std;

struct wall
{
	int cellOne;
	int cellTwo;
};

const int N = 3;

const int NUMOFWALLS = N * (N - 1) * 2;

const bool DIRECTED = false, WEIGHTED = false;

void wallGeneration(wall *data);
void mazeGeneration(Graph &graph,UnionFind *maze, wall *wallData);
void printStack(stack<int> stac);
void DFS(Graph graph, int start, int end);
void RDFS(Graph graph, int start, int end, stack<int> &stac, bool visited[]);

int main()
{
	srand(time(NULL));

	wall *wallData;
	wallData = new wall[NUMOFWALLS];
	
	UnionFind *maze;
	maze = new UnionFind(N*N);

	Graph graph( (N*N) , DIRECTED, WEIGHTED);
	
	cout << "The " << N << "x" << N << " Maze:\n";

	wallGeneration(wallData);

	mazeGeneration(graph, maze, wallData);

	DFS(graph, 0, N*N - 1);

	system("pause");
	return 0;
}

void wallGeneration(wall *data)
{
	int cellOne = 0, cellTwo = 0, index = 0;

	for (cellOne = 0; cellOne < N*N - 1; cellOne++)
	{
		cellTwo = cellOne + 1;
		if (cellTwo % N != 0)
		{
			data[index].cellOne = cellOne;
			data[index].cellTwo = cellTwo;
			index++;
		}

		cellTwo = cellOne + N;
		if (cellTwo < N*N)
		{
			data[index].cellOne = cellOne;
			data[index].cellTwo = cellTwo;
			index++;
		}
	}

}

void mazeGeneration(Graph &graph,UnionFind *maze, wall *wallData)
{	
	for (int i = 0; i < NUMOFWALLS; i++)
		swap(wallData[i], wallData[rand() % (i + 1)]);

	for (int i = 0; i < NUMOFWALLS; i++)
	{
		if (maze->pcFind(wallData[i].cellOne) != maze->pcFind(wallData[i].cellTwo))
		{
			maze->wUnion(wallData[i].cellOne, wallData[i].cellTwo);
			cout << "(" << wallData[i].cellOne << ", " << wallData[i].cellTwo << ") - WALL KNOCKED DOWN\n";
			Edge add(wallData[i].cellOne, wallData[i].cellTwo, DIRECTED);
			graph.addEdge(add);
		}
		else
			cout << "(" << wallData[i].cellOne << ", " << wallData[i].cellTwo << ") - WALL LEFT UP\n";

	}
}


void printStack(stack<int> stac)
{
	while(!stac.empty())
	{
		cout << stac.top() << " ";
		stac.pop();
	}
	cout << endl;
}

void DFS(Graph graph, int start, int end)
{
	stack<int> stac;
	stack<int> stacPath;
	cout << "Path for "<< N <<"x"<<N<<" maze is: ";
	bool *visited;
	visited = new bool[graph.getNumVertices()];

	for (int i = 0; i < graph.getNumVertices(); i++)
		visited[i] = false;

	RDFS(graph, start, end, stac, visited);
	
	delete visited;

	while(!stac.empty())
	{
		stacPath.push(stac.top());
		stac.pop();
	}

	printStack(stacPath);
}

void RDFS(Graph graph, int start, int end, stack<int> &stac, bool visited[])
{
	stac.push(start);
	if (start != end)
	{
		visited[start] = true;
		list<Edge> adjList = graph.getAdjacentList(start);
	
		for (list<Edge>::iterator i = adjList.begin(); i != adjList.end(); i++)
		{
			if (visited[i->getV2()]) continue;
			RDFS(graph, i->getV2(), end, stac, visited);
		}

		if (stac.top() != end)
			stac.pop();
	}
}