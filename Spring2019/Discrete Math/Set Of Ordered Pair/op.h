#pragma once
#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <algorithm>
#include <set>

typedef std::pair<unsigned, unsigned> OP;
typedef std::set<OP> SOP;

void show(const OP & op);
OP makeOP(unsigned first, unsigned second);
OP add(const OP & a, const OP & b);
void show(const SOP & sop);
bool elementOf(const OP & op, const SOP & sop);
bool firstFound(unsigned first, const SOP & sop);
bool secondFound(unsigned second, const SOP & sop);
bool eitherFound(unsigned n, const SOP & sop);
SOP Union(const SOP & sop0, const SOP & sop1);

#endif
