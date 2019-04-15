// Josh Ortiz CS 542
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// Program Ignores case of FIT/LIT or FNT/LNT

const unsigned F = 0, I = 1, R = 1, L = 2, N = 3, T = 4;

struct SEQUENCE_FORMULA
{
	unsigned varUnKnown;
	unsigned varOne;
	unsigned varTwo;
	unsigned varThree;
	void(*f)(vector<double> &, vector<bool> &);
};

void Nfil(vector<double> & variable, vector<bool> & haveVariable) { variable[N] = (variable[L] - variable[F]) / variable[I] + 1; haveVariable[N] = true; }
void Tfin(vector<double> & variable, vector<bool> & haveVariable) { variable[T] = variable[N] /2 * (2 * variable[F] + (variable[N] - 1)*variable[I]); haveVariable[T] = true; }
void Ifln(vector<double> & variable, vector<bool> & haveVariable) { variable[I] = (variable[L] - variable[F]) / (variable[N] - 1); haveVariable[I] = true; }
void Iflt(vector<double> & variable, vector<bool> & haveVariable) { variable[I] = (((variable[L] - variable[F])*(variable[F] + variable[L])) / 2) / (variable[T] - ((variable[F] + variable[L]) / 2)); haveVariable[I] = true; }
void Lfnt(vector<double> & variable, vector<bool> & haveVariable) { variable[L] = 2 * variable[T] / variable[N] - variable[F]; haveVariable[L] = true; }
void Filn(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = variable[L] - variable[I] * (variable[N] - 1); haveVariable[F] = true; }
void Fint(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = (2 * variable[T] / variable[N] - (variable[N] - 1)*variable[I]) / 2; haveVariable[F] = true; }
void Flnt(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = 2 * variable[T] / variable[N] - variable[L]; haveVariable[F] = true; }

const vector<SEQUENCE_FORMULA> TABLE_ARITHMETIC =
{
	{N,F,I,L,Nfil},
	{T,F,I,N,Tfin},
	{I,F,L,N,Ifln},
	{I,F,L,T,Iflt},
	{L,F,N,T,Lfnt},
	{F,I,L,N,Filn},
	{F,I,N,T,Fint},
	{F,L,N,T,Flnt}
};

void Nfrl(vector<double> & variable, vector<bool> & haveVariable) { variable[N] = (log((variable[L] / variable[F])) / log(abs(variable[R]))) + 1; haveVariable[N] = true; }
void Tfrn(vector<double> & variable, vector<bool> & haveVariable) { variable[T] = (variable[F] * (1 - pow(variable[R], variable[N]))) / (1 - variable[R]); haveVariable[T] = true; }
void Lfrt(vector<double> & variable, vector<bool> & haveVariable) { variable[L] = (variable[T] * (1 - variable[R]) - variable[F]) / (-1 * variable[R]); haveVariable[L] = true; }
void Rfln(vector<double> & variable, vector<bool> & haveVariable) { variable[R] = pow(10, ( log10(variable[L]/variable[F])/(variable[N]-1)) ); haveVariable[R] = true; }
void Rflt(vector<double> & variable, vector<bool> & haveVariable) { variable[R] = (variable[F] - variable[T]) / (variable[L] - variable[T]); haveVariable[R] = true; }
void Frln(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = variable[L] / pow(variable[R], variable[N] - 1); haveVariable[F] = true; }
void Frlt(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = variable[T] * (1 - variable[R]) + variable[R] * variable[L]; haveVariable[F] = true; }
void Frnt(vector<double> & variable, vector<bool> & haveVariable) { variable[F] = variable[T] * (1 - variable[R]) / (1 - pow(variable[R], variable[N])); haveVariable[F] = true; }

const vector<SEQUENCE_FORMULA> TABLE_GEOMETRIC =
{
	{N,F,R,L,Nfrl},
	{T,F,R,N,Tfrn},
	{L,F,R,T,Lfrt},
	{R,F,L,N,Rfln},
	{R,F,L,T,Rflt},
	{F,R,L,N,Frln},
	{F,R,L,T,Frlt},
	{F,R,N,T,Frnt}
};

void getInput(vector<double> & variable, vector<bool> & haveVariable);
vector<unsigned> missingVarPos(const vector<bool> & haveVariable);
void printMissingVar(const vector<double> variable, const vector<unsigned> missingVar);

int main()
{
	cout << "Disclaimer: Program Ignores case of FIT/LIT or FNT/LNT\n\n";
	cout << "Enter Three Variables of the Arithmetic Sequence: ";
	vector<double> variableArithmetic(5);
	vector<bool> hasVariableArithmetic = { false,false,false,false,false };
	
	
	getInput(variableArithmetic, hasVariableArithmetic);

	vector<unsigned> missingVarArithmetic(missingVarPos(hasVariableArithmetic));
	
	for (unsigned i = 0; !hasVariableArithmetic[missingVarArithmetic[0]] || !hasVariableArithmetic[missingVarArithmetic[1]] ; i++)
	{ 
		unsigned j = i % 8; // table search
		if (hasVariableArithmetic[TABLE_ARITHMETIC[j].varOne] && hasVariableArithmetic[TABLE_ARITHMETIC[j].varTwo] && hasVariableArithmetic[TABLE_ARITHMETIC[j].varThree] && !hasVariableArithmetic[TABLE_ARITHMETIC[j].varUnKnown])
			TABLE_ARITHMETIC[j].f(variableArithmetic, hasVariableArithmetic);
	}

	printMissingVar(variableArithmetic, missingVarArithmetic);



	cout << "Enter Three Variables of the Geometric Sequence: ";
	vector<double> variableGeometric(5);
	vector<bool> hasVariableGeometric = { false,false,false,false,false };

	getInput(variableGeometric, hasVariableGeometric);
	vector<unsigned> missingVarGeometric(missingVarPos(hasVariableGeometric));

	for (unsigned i = 0; !hasVariableGeometric[missingVarGeometric[0]] || !hasVariableGeometric[missingVarGeometric[1]]; i++)
	{
		unsigned j = i % 8; // table search
		if (hasVariableGeometric[TABLE_GEOMETRIC[j].varOne] && hasVariableGeometric[TABLE_GEOMETRIC[j].varTwo] && hasVariableGeometric[TABLE_GEOMETRIC[j].varThree] && !hasVariableGeometric[TABLE_GEOMETRIC[j].varUnKnown])
			TABLE_GEOMETRIC[j].f(variableGeometric, hasVariableGeometric);
	}
	printMissingVar(variableGeometric, missingVarGeometric);

	system("pause");
}

void getInput(vector<double> & variable, vector<bool> & haveVariable)
{
	char posInput;
	double valueInput;
	unsigned varPos = 0, count = 0;

	while ( count < 3 )
	{
		cin >> posInput;
		cin >> valueInput;
		switch (toupper(posInput))
		{
		case 'F':
			varPos = F;
			break;
		case 'I':
			varPos = I;
			break;
		case 'R':
			varPos = R;
			break;
		case 'L':
			varPos = L;
			break;
		case 'N':
			varPos = N;
			break;
		case 'T':
			varPos = T;
			break;
		}
		haveVariable[varPos] = true;
		variable[varPos] = valueInput;
		count++;
	}
}

vector<unsigned> missingVarPos(const vector<bool> & haveVariable)
{
	vector<unsigned> missingVar;

	for (unsigned i = 0, missingFound = 0; missingFound < 2; i++)
		if (haveVariable[i] == false)
		{
			missingVar.push_back(i);
			missingFound++;
		}
	
	return missingVar;
}

void printMissingVar(const vector<double> variable, const vector<unsigned> missingVar)
{
	cout << "Missing Variables are: \n";
	for ( unsigned i = 0 ; i<2 ; i++ )
		switch (missingVar[i])
		{
		case 0:
			cout << "F: " << variable[F] << "\n";
			break;
		case 1:
			cout << "I || R: " << variable[I] << "\n";
			break;
		case 2:
			cout << "L: " << variable[L] << "\n";
			break;
		case 3:
			cout << "N: " << variable[N] << "\n";
			break;
		case 4:
			cout << "T: " << variable[T] << "\n";
			break;
		}
}