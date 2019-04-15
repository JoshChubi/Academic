// CS546 Josh Ortiz
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
	int A, B, C, s1, s2, s3, sumSquares, sq1, sq2, sq3, Ahi, Bhi;
	cout << "Enter three sides of a triangle:";
	cin >> A >> B >> C;
	cout << endl;
	// Intel assembler for A > B && A > C
	// result set in variable Ahi
	__asm {
		mov	Ahi, 0
		mov	eax, A
		cmp	eax, B
		jle	doneAhi
		cmp	eax, C
		jle	doneAhi
		mov	Ahi, 1
		doneAhi:	nop

	}
	cout << "Ahi:" << Ahi << endl;
	if (Ahi) {
		s1 = A;
		s2 = B;
		s3 = C;
	}
	else if (B > A && B > C) {
		s1 = B;
		s2 = A;
		s3 = C;
	}
	else {
		// Intel Assembler for
		// s1 = C; s2 = A; s3 = B;
		__asm {
			mov	eax, C
			mov	s1, eax
			mov	eax, A
			mov	s2, eax
			mov	eax, B
			mov	s3, eax
		}
	}
	// Intel assembler for
	// sumSquares = (s1 * s1) - ((s2 * s2) + (s3 * s3));
	__asm {
		mov	eax, s1
		imul	s1; one operand form - implies eax
		mov	sq1, eax
		; note that high - order part of product is in edx
		mov	eax, s2
		imul	eax, s2; two operand form
		mov	sq2, eax
		mov	eax, s3
		imul	s3
		mov	sq3, eax
		add	eax, sq2
		sub	eax, sq1
		mov	sumSquares, eax
	}
	cout << "sq1:" << sq1 << " sq2:" << sq2 << " sq3:" << sq3 << " sumSquares:" << sumSquares << endl;
	if (sumSquares) {
		cout << "This is not a right triangle\n";
	}
	else {
		cout << "This is a right triangle\n";
		// area of a right triangle calculated here: s2*s2
		_asm {
			mov edx, 0; clear edx not sure why
			mov eax, s2; load the side
			imul eax, s3; multiply the side in regiester by other side
			shr eax, 1; idiv did not work so i did a right shift once to divide by two
			mov Bhi, eax; stores the area in Bhi, this variable was given and not used, so i stored it here
		}
		cout << "Area of a " << s1 << " " << s2 << " " << s3 << " triangle: " << Bhi << endl;
	}
	system("pause");
	return 0;
}