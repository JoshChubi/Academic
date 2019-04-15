// Ortiz, Josh		CS 546 Section 14860 5/1/18
// Third Labrator Assignemnt - Map NYC Taxi Destination

#pragma comment(linker,"/STACK:4194304")

#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;
// The following defines the size of the square image in pixels.
#define IMAGE_SIZE 1024

const float south = 40.700455, north = 40.830509, west = -74.045033, east = -73.91479;

int main(int argc, char* argv[])
{
	BITMAPFILEHEADER bmfh;

	BITMAPINFOHEADER bmih;

	char colorTable[1024];
	// The following defines the array which holds the image.  
	char bits[IMAGE_SIZE][IMAGE_SIZE] = { 0 };

	int i, j;

	float longitude, lattitude;

	// Define and open the output file. 
	ofstream bmpOut("foo.bmp", ios::out + ios::binary);
	ifstream binIn("L2Data10K.dat", ios::in + ios::binary);
	if (!bmpOut) {
		cout << "...could not open file, ending.";
		return -1;
	}
	if (!binIn) {
		cout << "...could not open file, ending.";
		return -1;
	}
	// Initialize the bit map file header with static values.
	bmfh.bfType = 0x4d42;
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfOffBits = sizeof(bmfh) + sizeof(bmih) + sizeof(colorTable);
	bmfh.bfSize = bmfh.bfOffBits + sizeof(bits);

	// Initialize the bit map information header with static values.
	bmih.biSize = 40;
	bmih.biWidth = IMAGE_SIZE;
	bmih.biHeight = IMAGE_SIZE;
	bmih.biPlanes = 1;
	bmih.biBitCount = 8;
	bmih.biCompression = 0;
	bmih.biSizeImage = IMAGE_SIZE * IMAGE_SIZE;
	bmih.biXPelsPerMeter = 2835;  // magic number, see Wikipedia entry
	bmih.biYPelsPerMeter = 2835;
	bmih.biClrUsed = 256;
	bmih.biClrImportant = 0;

	// Build color table.
	for (i = 0; i < 256; i++) {
		j = i * 4;
		colorTable[j] = colorTable[j + 1] = colorTable[j + 2] = colorTable[j + 3] = i;
		// for your edification, try setting one of the first three values to 255 instead of i
		// and see what it does to the generated bit map.
	}

	while (!binIn.eof())
	{
		binIn.read((char*)&lattitude, sizeof(float));
		binIn.read((char*)&longitude, sizeof(float));

		if ((longitude <= east && longitude >= west) && (lattitude <= north && lattitude >= south))
		{
			lattitude -= south;
			lattitude /= north - south;
			lattitude *= IMAGE_SIZE;

			longitude -= east;
			longitude /= west - east;
			longitude *= IMAGE_SIZE;

			if ((int)ceil(lattitude) < IMAGE_SIZE && (int)ceil(longitude) < IMAGE_SIZE)
			{
				bits[(int)ceil(lattitude)][IMAGE_SIZE - abs((int)ceil(longitude))] = 255;
			}
		}

	}

	// Write out the bit map.  
	char* workPtr;
	workPtr = (char*)&bmfh;
	bmpOut.write(workPtr, 14);
	workPtr = (char*)&bmih;
	bmpOut.write(workPtr, 40);
	workPtr = &colorTable[0];
	bmpOut.write(workPtr, sizeof(colorTable));
	workPtr = &bits[0][0];
	bmpOut.write(workPtr, IMAGE_SIZE*IMAGE_SIZE);
	bmpOut.close();

	// Now let's look at our creation.
	system("mspaint foo.bmp");

	// Done.
	return 0;
}
