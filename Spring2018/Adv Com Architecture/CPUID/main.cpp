// CS 546 Josh Ortiz
#include <iostream>
#include <iomanip>
#include <intrin.h>

using namespace std;

int main(int argc, char* argv[])
{
	int b[4] = { 0 };

	int a;

	for (a = 0; a < 5; a++) {
		__cpuid(b, a);
		cout << "Code:" << a << " gives " << setw(8) << hex << setfill('0') << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
	}

	system("pause");
	return 0;
}