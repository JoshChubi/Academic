//Ortiz, Josh	CS546 Section 14869	5/28/18
//Fifth Laboratory Assignment - Option A - Generate USPS bar codes

#pragma comment(linker,"/STACK:4194304")
#include <iostream>
#include <fstream>
#include "windows.h"
#include <math.h>
#include <string>

using namespace std;

#define picHeight 160
#define picLength 3000
#define longPixHi 150
#define shortPixHi 60
#define pixLen 24
#define pixSpace 30

void longLine(int &j);
void shortLine(int &j);

int size = sizeof(char);
char bits[picHeight][picLength] = { 0 };

int main(int argc, char* argv[])
{
	BITMAPFILEHEADER bmfh;

	BITMAPINFOHEADER bmih;

	char colorTable[1024];

	string address;

	int i = 0, j = 0, k = 0, l = 0;

	ofstream bmpOut("JBOLab5.bmp", ios::out + ios::binary);

	if (!bmpOut) {
		cout << "error: file could not open";
		exit(1);
	}

	bmfh.bfType = 0x4d42;
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfOffBits = sizeof(bmfh) + sizeof(bmih) + sizeof(colorTable);
	bmfh.bfSize = bmfh.bfOffBits + sizeof(bits);

	bmih.biSize = 40;
	bmih.biWidth = picLength;
	bmih.biHeight = picHeight;
	bmih.biPlanes = 1;
	bmih.biBitCount = 8;
	bmih.biCompression = 0;
	bmih.biSizeImage = picLength * picHeight;
	bmih.biXPelsPerMeter = 2835;
	bmih.biYPelsPerMeter = 2835;
	bmih.biClrUsed = 256;
	bmih.biClrImportant = 0;

	for (unsigned i = 0; i < 256; i++) {
		j = i * 4;
		colorTable[j] = colorTable[j + 1] = colorTable[j + 2] = colorTable[j + 3] = i;
	}

	for (unsigned i = 0; i < picHeight; ++i) {
		for (unsigned j = 0; j < picLength; ++j) {
			bits[i][j] = 0xff;
		}
	}


	cout << "Enter a five-digit Zip code and a four-digit Zip+4 extension:";

	getline(cin, address);

	j = 4 * pixSpace;
	longLine(j);

	int checkDigit = 0;

	for (unsigned i = 0; i < address.length(); i++) {
		if (address[i] >= '0' && address[i] <= '9') {
			checkDigit += (address[i] - '0');
		}
	}

	checkDigit = checkDigit % 10;

	checkDigit = 10 - checkDigit;

	address.append(to_string(checkDigit));

	for (unsigned l = 0; l < address.length(); l++) {
		switch (address[l]) {
		case ' ':
		case '-':
			continue;
			break;
		case '0': //11000
			longLine(j);
			longLine(j);
			shortLine(j);
			shortLine(j);
			shortLine(j);
			break;
		case '1': //00011
			shortLine(j);
			shortLine(j);
			shortLine(j);
			longLine(j);
			longLine(j);
			break;
		case '2': //00101
			shortLine(j);
			shortLine(j);
			longLine(j);
			shortLine(j);
			longLine(j);
			break;
		case '3': //00110
			shortLine(j);
			shortLine(j);
			longLine(j);
			longLine(j);
			shortLine(j);
			break;
		case '4': //01001
			shortLine(j);
			longLine(j);
			shortLine(j);
			shortLine(j);
			longLine(j);
			break;
		case '5': //01010
			shortLine(j);
			longLine(j);
			shortLine(j);
			longLine(j);
			shortLine(j);
			break;
		case '6': //01100
			shortLine(j);
			longLine(j);
			longLine(j);
			shortLine(j);
			shortLine(j);
			break;
		case '7': //10001
			longLine(j);
			shortLine(j);
			shortLine(j);
			shortLine(j);
			longLine(j);
			break;
		case '8': //10010
			longLine(j);
			shortLine(j);
			shortLine(j);
			longLine(j);
			shortLine(j);
			break;
		case '9': //10100
			longLine(j);
			shortLine(j);
			longLine(j);
			shortLine(j);
			shortLine(j);
			break;

		}

	}

	longLine(j);

	char* workPtr;
	workPtr = (char*)&bmfh;
	bmpOut.write(workPtr, 14);
	workPtr = (char*)&bmih;
	bmpOut.write(workPtr, 40);
	workPtr = &colorTable[0];
	bmpOut.write(workPtr, sizeof(colorTable));
	workPtr = &bits[0][0];
	bmpOut.write(workPtr, picLength * picHeight);
	bmpOut.close();
	cout << "Bit map file JBOLab5.bmp created\n";
	system("mspaint JBOLab5.bmp");

	return 0;
}

void longLine(int &j) {

	int temp = j;
	__asm {
		mov ecx, 0;
	outerLoop:
		cmp ecx, pixLen;
		je done;
		mov ebx, 0;
	innerLoop:
		mov eax, 0;
		mov eax, ebx;
		imul eax, picLength;
		add eax, temp;
		mov[bits + eax], 0;
		cmp ebx, longPixHi;
		je innerLoopDone;
		inc ebx;
		jmp innerLoop;
	innerLoopDone:
		mov eax, temp;
		inc eax;
		mov temp, eax;
		inc ecx;
		jmp outerLoop;
	done:
	}

	j = temp;
	j += pixSpace;
}

void shortLine(int &j) {
	int temp = j;
	__asm {
		mov ecx, 0;
	outerLoop:
		cmp ecx, pixLen;
		je done;
		mov ebx, 0;
	innerLoop:
		mov eax, 0;
		mov eax, ebx;
		imul eax, picLength;
		add eax, temp;
		mov[bits + eax], 0;
		cmp ebx, shortPixHi;
		je innerLoopDone;
		inc ebx;
		jmp innerLoop;
	innerLoopDone:
		mov eax, temp;
		inc eax;
		mov temp, eax;
		inc ecx;
		jmp outerLoop;
	done:
	}

	j = temp;
	j += pixSpace;
}