#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int n = 5;
	float a[5], x = 1.38 * 9, averageValue = 0, sum = 0;

	cout << "+--------------------------------------------------+" << endl;
	cout << "                  Лаболаторна робота 8" << endl;
	cout << "           Завдання 2. Програма обрахування середнього значення" << endl;
	cout << "+--------------------------------------------------+" << endl;

	for (int i = 1; i < n + 1; ++i)
	{
		a[i - 1] = (pow(log(pow(pow(x, 0.4) + i, 3)), 2) / (pow(i, 2) + i + 3)) - pow(i, x / 3);
	}

	cout << "Елементи вектора a[" << n << "]" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "\t" << a[i] << endl << endl;
	}

	cout << " 1) Визначити найбільший і найменший за модулем елемент(відзначені)" << endl;

	float maxMod, minMod, Mod, p;
	maxMod = fabs(a[1]);
	minMod = fabs(a[1]);
	
	for (int i = 1; i < n; ++i)
	{
		p = i % 2;
		if (!p == 0)
		{
			Mod = fabs(a[i]);
			if (maxMod < Mod)
			{
				maxMod = Mod;
			}
			else if (minMod > Mod)
			{
				minMod = Mod;
			}
		}
	}

	cout << "Найбільший за модулем елемент:" << maxMod << endl;
	cout << "Найменший за модулем елемент:" << minMod << endl << endl;

	cout << " 2) Визначити суму відємних(відзначених) і додатних(невідзначених) елементів та їхні кількості" << endl;

	float sumNev = 0, sumVid = 0;
	int kv = 0, kd = 0;

	for (int i = 0; i < n; ++i)
	{
		p = i % 2;
		if (!p == 0)
		{
			if (a[i] < 0)
			{
				sumVid += a[i];
				kv++;
			}
		}
		else if (p == 0)
		{
			if (a[i] > 0)
			{
				sumNev += a[i];
				kd++;
			}
		}
	}

	cout << "Сума відємних(відзначених) елементів:" << sumVid << "\t" << "Кількість:" << kv << endl;
	cout << "Сума додатних(невідзначених) елементів:" << sumNev << "\t" << "Кількість:" << kd << endl << endl;


	cout << " 3) Визначити серенє арефметичне відємних(невідзначених) і додатних(відзначених) елементів" << endl;
	float dod = 0, vid = 0;
	int kv1 = 0, kd1 = 0;
	for (int i = 0; i < n; ++i)
	{
		p = i % 2;
		if (!p == 0)
		{
			if (a[i] > 0)
			{
				dod += a[i];
				kd1++;
			}
		}
		else if (p == 0)
		{
			if (a[i] < 0)
			{
				vid += a[i];
				kv1++;
			}
		}
		
	}
	

	cout << "Середнє арифметичне додатніх(невідзначених) елементів:" << dod / kd1 << endl;
	cout << "Середнє арифметичне відємних(відзначених) елементів:" << vid / kv1 << endl;

	system("pause");
	return 0;
}
