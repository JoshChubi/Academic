// cs542 Josh Ortiz
#include "boolEquiv.h"

using namespace std;

int main()
{
	string exprStr;
	cout << "Enter expressions | Seperated by Commas | Capitalized Variables\nexpr: ";

	while (getline(std::cin, exprStr) && !exprStr.empty())
		cout << "      " << equivalence(exprStr) << "\nexpr: ";

	system("pause");
}