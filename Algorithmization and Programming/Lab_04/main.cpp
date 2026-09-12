#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << "--------------------Лабораторна робота 4--------------------" << endl;
	cout << "Програма для обчислення одного із значень функції на проміжку[-5,5]" << endl;
	cout << "-------------------------------------------------------------------- - " << endl;

	double x, y;

	cout << "Введіть значення аргументу: \tx =";
	cin >> x;

	if ((x<-5)||(x>5)) 
		cout<<"Неможливо обчислити! Значкння x виходить за межі інтервалу [-5,5]" <<endl;
	else
	{
		if (x <= 1)
		{
			y = x;
			cout << "Виконалась перша умова!";
		}

	    else if ((fabs(x) > 1) && (fabs(x) < 2.5))
		{
			y = pow(x, 2);
			cout << "Виконалась друга умова!";
		}

		else if (fabs(x) >= 2.5)
		{
			y = 6.25 * sqrt(fabs(x) - 1.5);
			cout << "Виконалась третя умова!";
		}

		cout << "Значення функції: \ty = " << y << endl;

		while (!_kbhit());
		return 0;


	}

}
