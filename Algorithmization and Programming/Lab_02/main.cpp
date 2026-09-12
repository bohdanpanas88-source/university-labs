#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	 
	cout << "/--------------Лабораторна робота 2--------------/" << endl;
	
	float u, a, b;
	float y;

	cout << "Введіть значення: u, a, b:" << endl;
	cout << "\tu= ";
	cin >> u;
	cout << "\ta= ";
	cin >> a;
	cout << "\tb= ";
	cin >> b;
	
	y = (pow(a,u) + exp(-b * u)) / pow(sin(b * u), 2) + 1.24;
    cout << "Результат обчислення: \n\ty(u,a,b) =" << y << endl;

	getchar();
    return 0;
}
