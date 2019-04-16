#pragma once
#ifndef BOOLEQUIV_H
#define BOOLEQUIV_H

#include "boolCalc.h"
#include <algorithm>
#include <vector>
#include <set>

const char DELIMITER = ',';

bool next(std::string & curVal);
bool lowerCaseVar(const std::string & exprStr);
std::vector<std::string> split(const std::string & fullExpr, const char & delimiter);
std::set<char> findVar(const std::string & expr);
std::string replacVar(std::string expr, const std::set<char> & varSet, const std::string & curVal);
std::string equivalence(const std::string & exprStr);

#endif // !BOOLEQUIV_H
