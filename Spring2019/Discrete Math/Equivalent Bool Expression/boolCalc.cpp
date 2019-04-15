#include "boolCalc.h"

bool die(const std::string & msg)
{
	std::cout << "Fatal error: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

bool eval(const std::string & expr)
{
	std::stack<bool> oprnd;
	std::stack<char> oprtr;
	for (char token : "(" + expr + ")")
	{
		if (token == ' ')
			continue;
		else if (isdigit(token))
			oprnd.push(token - '0');
		else if (token == '(' || token == '!')
			oprtr.push(token);
		else
		{
			while (prec(oprtr.top()) > prec(token))
			{
				char currentOP = oprtr.top(); oprtr.pop();
				bool rhs = oprnd.top(); oprnd.pop();
				bool lhs = NULL;
				if (currentOP != '!')
					lhs = oprnd.top(), oprnd.pop();
				bool ans = NULL;
				switch (currentOP)
				{
				case '!': ans = !rhs; break;
				case '&': ans = lhs && rhs; break;
				case '^': ans = lhs ^ rhs; break;
				case '|': ans = lhs || rhs; break;
				default: die("invalid operator");
				}
				oprnd.push(ans);
			}
			token == ')' ? oprtr.pop() : oprtr.push(token);
		}
	}
	return oprnd.top();
}

unsigned prec(char op)
{
	const std::string oprtr = "!&^|()";
	const std::string prec = "432100";
	return prec[oprtr.find(op)] - '0';
}