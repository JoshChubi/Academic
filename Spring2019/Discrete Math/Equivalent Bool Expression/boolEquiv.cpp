#include "boolEquiv.h"
bool next(std::string & curVal)
{
	for (unsigned i = curVal.size() - 1; ; i--)
	{
		if (i == std::string::npos)
			return false;
		curVal[i] = '0' + '1' - curVal[i];
		if (curVal[i] == '1')
			return true;
	}
}

bool lowerCaseVar(const std::string & exprStr)
{
	for (auto c : exprStr)
		if (islower(c))
			return true;
	return false;
}

bool unCorrespondingVar(std::vector<std::string> exprVec, std::string baseVar)
{
	sort(baseVar.begin(), baseVar.end());
	for (unsigned index = 1; index < exprVec.size(); index++)
	{
		std::string corrVar = findVar(exprVec[index]);
		sort(corrVar.begin(), corrVar.end());
		if (baseVar != corrVar)
			return true;
	}
	return false;
}

std::vector<std::string> split(const std::string & fullExpr, const char & delimiter)
{
	unsigned pos = 0;
	unsigned posDelim = fullExpr.find(delimiter, pos);
	std::vector<std::string> tokens;

	for (unsigned exprIndex = 0; exprIndex < count(fullExpr.begin(), fullExpr.end(), delimiter); exprIndex++)
	{
		tokens.push_back(fullExpr.substr(pos, posDelim - pos)); // from current pos subStr (posDelim - pos) chars
		pos = posDelim + 1;
		posDelim = fullExpr.find(delimiter, pos);
	}
	tokens.push_back(fullExpr.substr(pos));

	return tokens;
}

std::string findVar(std::string expr)
{
	std::string var = "";

	for (char c : expr)
		if (isalpha(c))
		{
			var += c;
			replace(expr.begin(), expr.end(), c, '\0');
		}

	return var;
}

std::string replacVar(std::string expr, const std::string & var, const std::string & curVal)
{
	for (unsigned index = 0; index < var.length(); index++)
		replace(expr.begin(), expr.end(), var[index], curVal[index]);

	return expr;
}

std::string equivalence(const std::string & exprStr)
{
	std::vector<std::string> exprVec = split(exprStr, DELIMITER);
	std::string variables = findVar(exprVec[0]);
	std::string curVal(variables.length(), '0');

	if (exprVec.size() == 1)
		return "Requires more than one expression";
	else if (lowerCaseVar(exprStr))
		return "Variables must be uppercase";
	else if (unCorrespondingVar(exprVec, variables))
		return "Expressions must have corresponding variables";

	do
	{
		bool equiVal = eval(replacVar(exprVec[0], variables, curVal));
		for (unsigned index = 1; index < exprVec.size(); index++)
			if (equiVal != eval(replacVar(exprVec[index], variables, curVal)))
				return "Not Equivalent";
	} while (next(curVal));

	return "Equivalent";
}