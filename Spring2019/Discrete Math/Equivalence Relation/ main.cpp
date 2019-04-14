// Josh Ortiz CS 542
#include "equivRel.h"

using namespace std;

int main()
{
	cout << "Assume the values in sop exist in the universe\n\n";

	SOP sop = { OP(1,1), OP(2,2), OP(3,2), OP(2,3), OP(3,3) };
	set<unsigned> universe = { 1,2,3 };

	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl;

	sop = { OP(1,2), OP(2,1), OP(1,1) };
	universe = { 1,2 };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl; // doesnt pass reflexivity, missing (2,2)

	sop = { OP(5,5), OP(6,5), OP(5,7), OP(6,7), OP(6,6), OP(7,7) };
	universe = { 5,6,7 };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl; // doest pass Symmetry, missing (7,5) (5,6) (7,6)

	sop = { OP(10,10), OP(15,15), OP(20,10), OP(10,20), OP(20,20) };
	universe = { 10,15,20 };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl;

	sop = { OP(0,0), OP(0,1), OP(0,3), OP(1,0), OP(1,1), OP(2,2), OP(3,0), OP(3,3) };
	universe = { 0,1,2,3 };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl; // doesnt pass transivity, (3,0) & (0,1) is missing (3,1)

	sop = { OP('a','b'), OP('b','a'), OP('a','a'), OP('b','b') };
	universe = { 'a','b' };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl;

	sop = { OP(2,1), OP(1,1)};
	universe = { 1,2 };
	cout << "equivalence relation: " << (er(sop, universe) ? "True" : "False") << endl << endl;

	system("pause");
	return 0;
}
