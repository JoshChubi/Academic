//Josh Ortiz Cs542
#include "sets.h"

using namespace std;

int main()
{
	SOP mySOP{ OP(1,2),OP(2,3),OP(3,4),OP(4,5) };

	cout << "show( makeOP(7,3) ): ";
	show(makeOP(7, 3));

	cout << "\n\nadd( OP(1,2), OP(5,7) ): ";
	show(add(OP(1, 2), OP(5, 7)));

	cout << "\n\nshow(mySOP): ";
	show(mySOP);

	cout << "\n\nelementOf( OP(1, 2), SOP{ OP(1,1), OP(2,1), OP(2,2)} ): " << (elementOf(OP(1, 2), SOP{ OP(1,1), OP(2,1), OP(2,2) })?"true":"false") ;

	cout << "\n\nfirstFound(3,mySOP): " << (firstFound(3,mySOP)?"true":"false");

	cout << "\n\nsecondFound(8,mySOP): " << (secondFound(8,mySOP)?"true":"false");

	cout << "\n\neitherFound(5,mySOP): " << (eitherFound(5,mySOP)?"true":"false");

	cout << "\n\nUnion(mySOP, SOP{OP(5,5),OP(0,0)} ): ";
	show( Union(mySOP, SOP{OP(5,5),OP(0,0)}) );
	cout << "\n\n";

	system("pause");
	return 0;
}