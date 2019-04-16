//CS 575 Josh Ortiz
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846;

int main ()
{
	double volume, radius; 
	
	cout << "Input Radius of sphere: " << endl; // prompt
	cin >> radius;
	volume = 4.0/3.0*PI*(radius*radius*radius); //make sure operants are double type
	cout << "The volume of the sphere is: " << volume << endl;
	return 0;
}
