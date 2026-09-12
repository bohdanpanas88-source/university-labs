#include <iostream>
#include <conio.h>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	int n;
	double S = 0, D = 1;
	
	cout << "\t\t\tЛаболаторна робота  N6" << endl;
	cout << "\t\t\t\tЗавдання 2" << endl;
	cout << "\tОбчислення суми та добутку для заданого значення n" << endl <<endl;
	
	cout << "\tВведіть ціле число n: ";
	cin >> n;

	for (int k = 1; k <= n; ++k) {
		S += k + cos(k) / pow(2, k);
		D *= 1 / k + sqrt(k);
	}

	cout << "\tСума = " << S <<endl << "\tДобуток = " << D << endl;

	system("pause");
	return 0;
}
