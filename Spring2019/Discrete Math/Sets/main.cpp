//Josh Ortiz Cs542
#include "sets.h"

using namespace std;

int main()
{
	set<int> mySet{ 1,2,3,4,5,6,7 };

	cout << "show(mySet):";
	show(mySet);

	cout << "\nevens(mySet): " << evens(mySet) << endl;

	cout << "\nhowManyInteresting(mySet,isEven): " << howManyInteresting(mySet) << endl;

	cout << "\nsubset(mySet, {7,6,5,4,3,1,2} ): " << (subset(mySet, { 7,6,5,4,3,1,2 }) ? "True" : "False") << endl;

	cout << "\nUnion(mySet, {8,9,1} ):";
	show(Union(mySet, { 8,9,1 }));

	cout << "\nintersection( {1,3,5,7} , {5,7,9,11} ):";
	show(intersection({ 1,3,5,7 }, { 5,7,9,11 }));

	cout << "\ncomplement( { 0,10,12,4}, {0,2,4,6,8,10,12,14,16} ):";
	show(complement({ 0,10,12,4 }, { 0,2,4,6,8,10,12,14,16 }));

	cout << "\ndifference( {1,2,3,4} , {3,4,5,6} ):";
	show(difference({ 1,2,3,4 }, { 3,4,5,6 }));

	cout << "\nsymmetricDifference( {1,2,3,4} , {3,4,5,6} ):";
	show(symmetricDifference({ 1,2,3,4 }, { 3,4,5,6 }));

	cout << endl;
	system("pause");
	return 0;
}