#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
using namespace std;

int main(int argc, char* aegv[])
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	const int n = 10;
	float a[n], c, x = 1.38 * 9;

	cout << "+----------------------------------------------------------+" << endl;
	cout << "                 Лаболаторна робота 8" << endl;
	cout << "   Завдання 3. Сортування елементів масиву за зростанням" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	cout << "Вектор a[" << n << "]" << endl;
	
	for (int i = 0; i <= n ; ++i)
	{
		a[i] = (pow(log(pow(pow(x, 0.4) + i, 3)), 2) / pow(i, 2) + i + 3) - pow(i, x / 3);
		cout << "\t" << a[i] << endl;
	}
}
