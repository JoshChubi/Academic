#pragma once
#ifndef BOOLCALC_H
#define BOOLCALC_H

#include <iostream>
#include <stack>
#include <string>

bool die(const std::string & msg);
bool eval(const std::string & expr);
unsigned prec(char op);

#endif // !BOOLCALC_H
