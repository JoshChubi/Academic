// Josh Ortiz CS 546
#include <iostream>
#include <iomanip>
#include <intrin.h>

using namespace std;

int main(int argc, char* argv[])
{
	int b[4] = { 0 };
	bool popSupport;
	int a;
	int __popcnt = 8388608;

	for (a = 0; a < 5; a++) {
		__cpuid(b, a);
		cout << "Code:" << a << " gives " << setw(8) << hex << setfill('0') << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
		if (a == 1)
			(b[2] & __popcnt) ? popSupport = true : popSupport = false;
	}

	popSupport ? cout << "popcnt is supported" << endl : cout << "popcnt isnt supported" << endl;
	system("pause");
	return 0;
}