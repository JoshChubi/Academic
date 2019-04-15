// Josh Ortiz cs542
#include "boolCalc.h"

using namespace std;

int main()
{
	string expr;

	cout << "expr: ";
	while (getline(std::cin, expr) && !expr.empty())
		cout << "      " << eval(expr) << endl << "expr: ";

	system("pause");
	return 0;
}
