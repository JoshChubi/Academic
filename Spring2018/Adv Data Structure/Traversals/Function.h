#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include"Graph.h"

Graph * graphIt(const string & fileName);
void printIt(Graph * graph);
void pre_visit(int vertex);
void BFS(const Graph * graph, int start);
void DFS(const Graph * graph, int start);
void RDFS(const Graph * graph, bool visited[], int v);
