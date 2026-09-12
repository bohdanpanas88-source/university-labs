#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << "------------------Лабораторна робота 6--------------------" << endl;
	cout << "                       завдання 1                          " << endl;
	cout << "------------------Табулювання функціЇ---------------------" << endl;

	const int start = -10, end = 1, step = 1;
	const float  a = 2.8, b = 1.5;
	float y = 0, sum = 0, prod = 1;
	const size_t col1w = 8, col2w = 11, totalw = col1w + col2w;

	cout << setw(totalw) << setfill('-') << '-' << setfill(' ') << endl;
	cout << '|' << setw(col1w) << left << "inter";
	cout << '|' << setw(col2w) << "y" << '|' << endl;
	cout << setw(totalw) << setfill('-') << '-' << setfill(' ') << endl;

	for (float inter = start; inter < end; inter += step)
	{
		y = pow(abs(b * inter) / atan(pow(b, 2) / pow(a, 2) + pow(inter, 2)), 1. / 3);

		cout << '|' << setw(col1w) << left << inter;
		cout << '|' << setw(col2w) << y << '|' << endl;

		sum += y;
		prod *= y;
	}
 
	cout << setw(totalw) << setfill('-') << '-' << setfill(' ') << endl;
	cout << '|' << setw(col1w) << left << "sum";
	cout << '|' << setw(col2w) << sum << '|' << endl;
	cout << setw(totalw) << setfill('-') << '-' << setfill(' ') << endl;
	cout << '|' << setw(col1w) << left << "product";
	cout << '|' << setw(col2w) << fixed << setprecision(2) << prod << '|' << endl;
	cout << setw(totalw) << setfill('-') << '-' << setfill(' ') << endl;
	
	getchar();
	return 0;
}
