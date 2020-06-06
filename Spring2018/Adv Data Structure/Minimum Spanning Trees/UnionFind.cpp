#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
	capacity = n;
	tree = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		tree[i] = -1;
	}
}

int UnionFind::pcFind(int e)
{
	int root, prev;
	root = e;
	while (tree[root] >= 0)
	{
		root = tree[root];
	}
	while (tree[e] >= 0)
	{
		prev = e;
		e = tree[e];
		tree[prev] = root;
	}
	return root;
}

void UnionFind::wUnion(int e1, int e2)
{
	int r1 = pcFind(e1);
	int r2 = pcFind(e2);

	if (tree[r2] >= tree[r1])
	{
		if (tree[r2]<0)
			tree[r1] += tree[r2];
		tree[r2] = r1;
	}
	else
	{
		if (tree[r1]<0)
			tree[r2] += tree[r1];
		tree[r1] = r2;
	}
}

void UnionFind::printArray()
{
	for (int i = 0; i < capacity ; i++)
	{
		cout << tree[i] << " ";
	}
}
