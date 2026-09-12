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
	float a[n], c, x = 1.38 * 9, sum = 0, aruf;
	int pos = -1;

	cout << "+----------------------------------------------------------+" << endl;
	cout << "                 Лаболаторна робота 8" << endl;
	cout << "   Завдання 3. Сортування елементів масиву за зростанням" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	cout << "Вектор a[" << n << "]" << endl;

	for (int i = 0; i < n; ++i)
	{
		a[i] = ((pow(log(pow(pow(x, 0.4) + i, 3)), 2)) / (pow(i, 2) + i + 3)) - pow(i, x / 3);
		cout << "\t" << a[i] << endl;
		sum += a[i];
	}
	cout << "Сума:" << sum << endl;
	aruf = sum / 10;
	cout << "Середнє арифметичне масиву:" << aruf << endl;

	
	for (int i = 0; i < n; ++i)
	{
		if (aruf < a[i])
		{
			pos = i;
			cout << "Елемент масиву який більший за середнє арифметичне:" << a[i] << endl << "Номер елемента масиву:" << i << endl;
			break;
		}
	}

	if (pos == -1)
	{
		cout << "Немає елементів, більших за середнє арифметичне!" << endl;
		system("pause");
		return 0;
	}
	else {

		float temp;
		for (int i = pos + 1; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	cout << "Відсортований вектор a[" << n << "]" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "\t" << a[i] << endl;
	}

	system("pause");
	return 0;
}
