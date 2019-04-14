#pragma once
#ifndef EQUIVREL_H
#define EQUIVREL_H

#include <iostream>
#include <algorithm>
#include <set>

typedef std::pair<unsigned, unsigned> OP;
typedef std::set<OP> SOP;

void showSOP(const SOP & sop);
void showUniv(const std::set<unsigned> univ);
bool er(const SOP & sop, const std::set<unsigned> & univ);

#endif // !EQUIVREL_H
