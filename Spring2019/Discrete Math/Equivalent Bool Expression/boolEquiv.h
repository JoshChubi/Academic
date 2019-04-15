#pragma once
#ifndef BOOLEQUIV_H
#define BOOLEQUIV_H

#include "boolCalc.h"
#include <algorithm>
#include <vector>

const char DELIMITER = ',';

bool next(std::string & curVal);
bool lowerCaseVar(const std::string & exprStr);
bool unCorrespondingVar(std::vector<std::string> exprVec, std::string baseVar);
std::vector<std::string> split(const std::string & fullExpr, const char & delimiter);
std::string findVar(std::string expr);
std::string replacVar(std::string expr, const std::string & var, const std::string & curVal);
std::string equivalence(const std::string & exprStr);

#endif // !BOOLEQUIV_H
