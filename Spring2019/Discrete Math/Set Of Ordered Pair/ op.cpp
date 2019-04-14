#include "op.h"

void show(const OP & op)
{
	std::cout << '(' << op.first << ',' << op.second << ") ";
}

OP makeOP(unsigned first, unsigned second)
{
	return OP(first, second);
}

OP add(const OP & a, const OP & b)
{
	return makeOP(a.first + b.first, a.second + b.second);
}

void show(const SOP & sop)
{
	for (OP n : sop)
		show(n);
}

bool elementOf(const OP & op, const SOP & sop)
{
	return sop.count(op);
}

bool firstFound(unsigned first, const SOP & sop)
{
	for (OP n : sop)
		if (first == n.first)
			return true;
	return false;
}

bool secondFound(unsigned second, const SOP & sop)
{
	for (OP n : sop)
		if (second == n.second)
			return true;
	return false;
}

bool eitherFound(unsigned n, const SOP & sop)
{
	return firstFound(n, sop) || secondFound(n, sop);
}

SOP Union(const SOP & sop0, const SOP & sop1)
{
	SOP newSet(sop0);
	newSet.insert(sop1.begin(), sop1.end());
	return newSet;
}
