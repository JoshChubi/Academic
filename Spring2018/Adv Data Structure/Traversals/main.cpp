#include "Function.h"

using namespace std;

int main() 
{
	Graph * graph = graphIt("Run1.txt");

	/*----------------------------------------------------------------------------------------------*/
	cout << "--RUN ONE--\nGraph:\n";
	printIt(graph);
	cout << "Vertices: " << graph->getNumVertices() << endl;
	cout << "Edges: " << graph->getNumEdges() << endl;

	cout << "Directed: ";
	if (graph->isDirected()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	cout << "Weighted: ";
	if (graph->isWeighted()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	cout << "Breadth first traversal: ";
	BFS(graph,0);

	cout << "\nDepth first traversal: ";
	DFS(graph,0);
	cout << "\n\n";


	/*----------------------------------------------------------------------------------------------*/
	graph = graphIt("Run2.txt");

	cout << "--RUN TWO--\nGraph:\n";
	printIt(graph);
	cout << "Vertices: " << graph->getNumVertices() << endl;
	cout << "Edges: " << graph->getNumEdges() << endl;

	cout << "Directed: ";
	if (graph->isDirected()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	cout << "Weighted: ";
	if (graph->isWeighted()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	cout << "Breadth first traversal: ";
	BFS(graph,0);

	cout << "\nDepth first traversal: ";
	DFS(graph,0);
	cout << endl;

	/*----------------------------------------------------------------------------------------------*/
	system("pause");
	return 0;
}
