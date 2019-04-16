
// CS 575 Josh Ortiz
#include <iostream>
using namespace std;

const double MIN_IN_HOUR = 60.0;

int main ()
{
	int mph; //miles per hour
	double mpm; //miles per minute
	
	cout << "Input your miles per hour: " << endl<<endl;
	cin >> mph; 
	mpm = mph / MIN_IN_HOUR;
	cout << mph <<" Miles per hour = " << mpm <<" Miles per minute" << endl;
	return 0;
}
