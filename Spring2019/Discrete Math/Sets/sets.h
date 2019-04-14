#pragma once
#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <set>
#include <algorithm>

void show(const std::set<int> & s);
unsigned evens(const std::set<int> & s);
bool isEven(int n);
unsigned howManyInteresting(const std::set<int> & s, bool(*interesting)(int n) = isEven);
bool subset(const std::set<int> & little, const std::set<int> & big);
std::set<int> Union(const std::set<int> & s0, const std::set<int> & s1);
std::set<int> intersection(const std::set<int> & s0, const std::set<int> & s1);
std::set<int> complement(const std::set<int> & s, const std::set<int> & universe);
std::set<int> difference(const std::set<int> & a, const std::set<int> & b);
std::set<int> symmetricDifference(const std::set<int> & a, const std::set<int> & b);

#endif // !SETS_H
