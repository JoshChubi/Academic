// Ortiz, Josh CS546 Section 14860 6/6/18 
// Sixth Laboratory Assignment - Count colors 
#pragma	(linker,"/STACK:4194304")
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include<map>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include <ctime>
#include <time.h>

#define length 1024
#define width 1024
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct color {

	int R;
	int B;
	int G;
	string name;
	int counter;

	color(int r, int b, int g, string n)
	{
		R = r;
		B = b;
		G = g;
		name = n;
		counter = 0;
	}
	color()
	{
		R = B = G = counter = 0;
		name = "";
	}
};


typedef multimap<int, color> Myhash;


int main()
{
	int totalSizeUsed = 0;
	int comparisons = 0;
	clock_t c_start = clock();

	fstream colorFile;

	try { colorFile.open("Colors64.txt"); }
	catch (exception e) { throw "Can't open colors file"; }

	FILE* f = fopen("CS546.bmp", "rb");
	if (f == NULL)
		throw "Argument Exception";

	Myhash table;
	Myhash::iterator i;

	color temp;

	pair<Myhash::iterator, Myhash::iterator> range;

	while (!colorFile.eof())
	{
		colorFile >> temp.R;
		colorFile >> temp.B;
		colorFile >> temp.G;
		colorFile.ignore(1);
		getline(colorFile, temp.name);

		table.insert(make_pair(temp.R, temp));
	}

	temp = color();


	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f);

	int row_padded = (width * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];



	for (int index = 0; index < length; index++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			temp.B = data[j + 1];
			temp.G = data[j];
			temp.R = data[j + 2];


			range = table.equal_range(temp.R);
			comparisons += 2; // equal_range has an if with two comparisions

			for (i = range.first; i != range.second; ++i)
			{
				comparisons++;
				if (temp.G == i->second.G)
				{
					comparisons++;
					if (temp.B == i->second.B)
					{
						i->second.counter++;
						break;
					}
				}

			}
		}
	}

	cout << left << setw(30) << "Name" << "Occurrences" << endl << endl;

	for (i = table.begin(); i != table.end(); ++i)
		cout << left << setw(30) << i->second.name << i->second.counter << endl;

	clock_t c_end = clock();

	delete data;

	fclose(f);

	colorFile.close();

	long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;

	//(2* sizeof(int) ) is for the two int for loop itterators index and j
	totalSizeUsed = (2 * sizeof(int)) + sizeof(comparisons) + sizeof(c_start) + sizeof(totalSizeUsed) + sizeof(colorFile) + sizeof(f) + sizeof(table) + sizeof(i) + sizeof(temp) + sizeof(range) + sizeof(info) + sizeof(row_padded) + sizeof(data) + sizeof(c_end) + sizeof(time_elapsed_ms);

	cout << endl << left << setw(30) << "Comparisons: " << comparisons << endl;
	cout << left << setw(30) << "CPU time used: " << time_elapsed_ms << " ms\n";
	cout << left << setw(30) << "Working storage set size: " << totalSizeUsed << " bytes\n\n";

	system("pause");
	return 0;
}