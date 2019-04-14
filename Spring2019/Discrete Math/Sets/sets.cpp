#include "sets.h"

void show(const std::set<int> & s)
{
	for (int n : s)
		std::cout << " " << n;
	std::cout << std::endl;
}

unsigned evens(const std::set<int> & s)
{
	int numberOfEvens = 0;
	for (int n : s)
		if (!(n % 2))
			numberOfEvens++;

	return numberOfEvens;
}

bool isEven(int n)
{
	return !(n % 2);
}

unsigned howManyInteresting(const std::set<int> & s, bool(*interesting)(int n))
{
	int numberOfInteresting = 0;
	for (int n : s)
		if (interesting(n))
			numberOfInteresting++;
	return numberOfInteresting;
}

bool subset(const std::set<int> & little, const std::set<int> & big)
{
	return little.size() == big.size() ? little == big : false;
}

std::set<int> Union(const std::set<int> & s0, const std::set<int> & s1)
{
	std::set<int> newSet(s0);
	newSet.insert(s1.begin(), s1.end());
	return newSet;
}

std::set<int> intersection(const std::set<int> & s0, const std::set<int> & s1)
{
	std::set<int> intersected;

	for (int n : s0)
		if (s1.find(n) != s1.end())
			intersected.insert(n);

	return intersected;
}

std::set<int> complement(const std::set<int> & s, const std::set<int> & universe)
{
	std::set<int> doesntContain;

	for (int n : universe)
		if (s.find(n) == s.end())
			doesntContain.insert(n);

	return doesntContain;
}

std::set<int> difference(const std::set<int> & a, const std::set<int> & b)
{
	return complement(b, a);
}

std::set<int> symmetricDifference(const std::set<int> & a, const std::set<int> & b)
{
	return Union(complement(a, b), difference(a, b));
}