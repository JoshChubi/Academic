#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> priorityQueue;

void replacmentSelectionHUB(int data[], int arraySize, int memSpace);

void replacmentSelection(double &currentRun, int data[], int dataLocation, int memSpace, int arraySize, priorityQueue unfrozenQ, priorityQueue frozenQ);

int main()
{
	int data[] = { 109,49,34,68,45,2,60,38,28,47,16,19,34,55,98,78,76,40,35,86,10 };
	int arraySize = sizeof(data) / sizeof(int);
	int memSpace = 5;

	cout << "Part One:";
	replacmentSelectionHUB(data, arraySize, memSpace);
	cout << endl;

	cout << "\nPart Two:";
	int dataTwo[100];
	for (int i = 0; i < 100; i++)
		dataTwo[i] = i+1;
	random_shuffle(begin(dataTwo), end(dataTwo));

	memSpace = 10;
	arraySize = sizeof(dataTwo) / sizeof(int);

	replacmentSelectionHUB(dataTwo, arraySize, memSpace);

	cout << endl;
	system("pause");
	return 0;
}

void replacmentSelectionHUB(int data[], int arraySize, int memSpace)
{
	priority_queue<int, vector<int>, greater<int> > unfrozenQ, frozenQ;

	int dataLocation = 0;

	double currentRuns = 0.0;

	replacmentSelection(currentRuns, data, dataLocation, memSpace, arraySize, unfrozenQ, frozenQ);

	cout << endl << "\nLength Of Run: " << arraySize / currentRuns;
}

void replacmentSelection(double &currentRun, int data[], int dataLocation, int memSpace, int arraySize, priorityQueue unfrozenQ, priorityQueue frozenQ)
{
	currentRun++;
	bool lastRun = dataLocation == arraySize;

	for (int i = 0; (i < memSpace) && (unfrozenQ.size() <= memSpace); i++)
	{
		if (dataLocation == arraySize)
		{
			break;
		}
		unfrozenQ.push(data[dataLocation]);
		dataLocation++;
	}

	int numFrozen = 0;
	int lastOutput;
	cout << "\nRun #" << currentRun << ": ";
	while ( (numFrozen < memSpace) && !unfrozenQ.empty())
	{
		cout << unfrozenQ.top() << " ";
		lastOutput = unfrozenQ.top();
		unfrozenQ.pop();

		if (dataLocation == arraySize)
		{
			numFrozen++;
		}
		else if (unfrozenQ.size() < (memSpace - numFrozen) )
		{
			unfrozenQ.push(data[dataLocation]);
			dataLocation++;
		}
		if (!unfrozenQ.empty())
		{
			if (unfrozenQ.top() < lastOutput)
			{
				frozenQ.push(unfrozenQ.top());
				unfrozenQ.pop();
				numFrozen++;
			}
		}
	}

	if (lastRun)
		return;

	replacmentSelection(currentRun, data, dataLocation, memSpace, arraySize, frozenQ, unfrozenQ);
}