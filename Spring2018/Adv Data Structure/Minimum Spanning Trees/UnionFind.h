#ifndef _UNIONFIND_
#define _UNIONFIND_
#include<stdlib.h>
#include <iostream>
using namespace std;

class UnionFind
{
private:
	int *tree;
	int capacity;

public:
	UnionFind(int n);

	int pcFind(int e);

	void wUnion(int e1, int e2);
	void printArray();
};
#endif
