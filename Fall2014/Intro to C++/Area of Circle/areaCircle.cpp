
//CS 575 Josh Ortiz
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846; //Defines PI  

int main ()
{
	double radius, area; 
	
	cout << "Radius: " << endl;
	cin >> radius; 
	area = (radius*radius)*PI; //formula for area
	cout << "Area = " << area << endl;
	return 0;
}
