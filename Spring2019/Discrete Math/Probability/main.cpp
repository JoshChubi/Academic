// Josh Ortiz HW 14 CS 542
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const char NORTHCHAR = '0';
const char EASTCHAR = '1';

string createSequence(const unsigned & a, const unsigned & b);
bool seqOrdered(const string & sequence, const bool & strictly = false);
double monotonic(unsigned a, unsigned b);
double strictlyMonotonic(unsigned a, unsigned b);

void shuffle(string & s);
double okNesting(unsigned n);

double duel(double a, double b);

double flip(double p, unsigned n, unsigned k);

vector<string> crossPath(const unsigned & north, const unsigned & east);
double prettyLady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY);

const unsigned TRIALS = 1'000'000;

int main()
{
	cout << int(4 == 4) << endl;
	cout << monotonic(2, 3) << endl;
	cout << strictlyMonotonic(2, 2) << endl;
	cout << okNesting(2) << endl;
	cout << duel(.5, .5) << endl;
	cout << flip(2.0/3.0, 5, 3) << endl;
	cout << prettyLady(2, 2, 1, 1) << endl;
	system("pause");
	return 0;
}

string createSequence(const unsigned & a, const unsigned & b)
{
	string sequence = "";
	for (unsigned itter = 0; itter < b; itter++)
		sequence += '0' + rand() % a;
	return sequence;
}

bool seqOrdered(const string & sequence, const bool & strictly)
{
	char prevDig = sequence[0];
	bool decreasing = true;
	bool increasing = true;

	for (auto curDig : sequence.substr(strictly)) // if strictly, start at 1 (True) else start at 0 (false), to avoid repeats
		if (prevDig == curDig && !strictly)
			continue;
		else if (prevDig > curDig)
			prevDig = curDig;
		else
		{
			decreasing = false;
			break;
		}

	for (auto curDig : sequence.substr(strictly))
		if (prevDig == curDig && !strictly)
			continue;
		else if (prevDig < curDig)
			prevDig = curDig;
		else
		{
			increasing = false;
			break;
		}
	return decreasing || increasing;
}

double monotonic(unsigned a, unsigned b)
{
	unsigned count = 0;
	for (unsigned attempts = 0; attempts < TRIALS; attempts++)
		count += int(seqOrdered(createSequence(a, b)));
	return double(count) / TRIALS;
}

double strictlyMonotonic(unsigned a, unsigned b)
{
	if (a < b)
		return 0;
	unsigned count = 0;
	for (unsigned attempts = 0; attempts < TRIALS; attempts++)
		count += int(seqOrdered(createSequence(a, b), true));
	return double(count) / TRIALS;
}

void shuffle(string & s)
{ 
	if (s.size() < 2) 
		return; 
	for (unsigned i = s.size() - 1; i > 0; i--)
		swap(s[i], s[rand() % (i + 1)]);
}

double okNesting(unsigned n)
{
	string str = string(n, '(') + string(n, ')');
	string caseOne = string(n,'(')+string(n,')');
	string caseTwo = "";
	for (unsigned itter = 0; itter < n; itter++)
		caseTwo += "()";
	unsigned count = 0;
	for (unsigned attempts = 0; attempts < TRIALS; attempts++)
	{
		shuffle(str);
		count += int(!str.compare(caseOne) || !str.compare(caseTwo));
	}
	return double(count) / TRIALS;
}

double duel(double a, double b)
{
	unsigned count = 0;
	for (unsigned attempts = 0; attempts < TRIALS; attempts++)
	{
		bool bothAlive = true;
		while (bothAlive)
			if (rand() % 100 + 1 <= a*100)
			{
				
				count += 1;
				bothAlive = false;
			}
			else if (rand() % 100 + 1 <= b*100)
				bothAlive = false;
	}
	return double(count) / TRIALS;
}

double flip(double p, unsigned n, unsigned k)
{
	unsigned count = 0;
	for (unsigned attempts = 0, numOfHeads = 0; attempts < TRIALS; attempts++, numOfHeads = 0)
	{
		for (unsigned itr = 0; itr < n; itr++)
			numOfHeads += int(rand() % 100 + 1 <= p * 100);
		count += int(k == numOfHeads);
	}
	return double(count)/TRIALS;
}

vector<string> crossPath(const unsigned & north, const unsigned & east)
{
	string fStrings = string(north, NORTHCHAR) + string(east, EASTCHAR);
	vector<string> paths;

	int n = north + east;
	bool isFinished = false;

	do {
		paths.push_back(fStrings);
		int i;
		for (i = n - 2; i >= 0; --i)
			if (fStrings[i] < fStrings[i + 1])
				break;

		if (i == -1)
			isFinished = true;
		else {
			int nextChar = i + 1;

			for (int j = i + 2; j <= n - 1; j++)
				if (fStrings[j] > fStrings[i] && fStrings[j] < fStrings[nextChar])
					nextChar = j;

			swap(fStrings[i], fStrings[nextChar]);

			sort(fStrings.begin() + i + 1, fStrings.end());
		}
	} while (!isFinished);
	return paths;
}

double prettyLady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY)
{
	string curPath = string(gridX, NORTHCHAR) + string(gridY, EASTCHAR);
	vector<string> ladyPaths(crossPath(ladyX, ladyY));
	unsigned count = 0;
	for (unsigned attempts = 0; attempts < TRIALS; attempts++)
	{
		shuffle(curPath);
		if (find(ladyPaths.begin(), ladyPaths.end(), curPath.substr(0, ladyX + ladyY)) != ladyPaths.end())
			count++;
	}
	return double(count)/TRIALS;
}