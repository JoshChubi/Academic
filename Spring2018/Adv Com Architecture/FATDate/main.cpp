#include <iostream>

using namespace std;

// Put the whole procces in a function since it was an eye sore in main, and hard to read
void FATdateToRegDate(short FATdate);
void RegDateToFATdate();

int main()
{
	cout << "CS 546 Section 14860      Lab Assignment 2       Josh Ortiz" << endl;
	FATdateToRegDate(0x1b62);// 11 2 1993
	FATdateToRegDate(0x1c99);// 4 25 1994

	RegDateToFATdate();

	return 0;
}

void FATdateToRegDate(short FATdate)
{
	short month, day, year;

	_asm {
		; procces for year
		mov	ax, FATdate; load hex 1b62 into register
		and ax, 0xFE00; do and operation to binary 1111 1110 0000 0000
		shr ax, 9; shift it 9 times to hold the year in the begging
		add ax, 1980; add the shifted number to 1980
		mov year, ax; save the year
		; procces for month
		mov	ax, FATdate; load hex 1b62 into register
		and ax, 0x1E0; do and operation to binary
		shr ax, 5; shift it 9 times to hold the year in the begging
		mov month, ax; save the year
		; procces for day
		mov	ax, FATdate; load hex 1b62 into register
		and ax, 0x1F; do and operation to binary
		mov day, ax; save the year
	}
	cout << "FATdate: " << hex << FATdate << " is Date: " << dec << month << ' ' << day << ' ' << year << endl;
}

void RegDateToFATdate()
{
	short FATdateCal;
	short month, day, year;


	cout << "Enter a month, day, and year between 1 - 1 - 1980 and 12 - 31 - 2107: ";
	cin >> month >> day >> year;
	if (!((month >= 1) && (month <= 12)) || !((day >= 1) && (day <= 31)) || !((year >= 1980) && (month <= 2107)))
	{
		cout << "Invalid Date Entry";
		system("EXIT");
	}

	_asm
	{
		; save year
		mov ax, year; move the year for calculations
		sub ax, 1980; saves the year
		or ax, 0x0; or 's it to save the value of year in binary
		shl ax, 4; shifts the year over to make room for month
		mov FATdateCal, ax; now stores year + 4 empty + 5 empty
		; save month
		mov ax, month; move month for calculations
		or ax, FATdateCal; or 's it to fatdate to insert the month at the end
		shl ax, 5; shifts it 5 times to make room for the day
		mov FATdateCal, ax; now stores the year + month + 5 empty
		; save day
		mov ax, day; move day for calcualtions
		or ax, FATdateCal; or 's it to save the day
		mov FATdateCal, ax; now has year + month + day
	}
	cout << "FATdate is: " << hex << FATdateCal << endl;
}