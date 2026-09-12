#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "\tЛабораторна робота 7" << endl;
	cout << "\t      Завдання 1    " << endl;
	cout << "Обчислити значення функції і вивести додавтні та відємні а також  значення їх аргументів [1.2 ; 4.4]: " << endl << endl;

	const float y = 617.3, fi = 0.3;
	float xStart = 1.2, xEnd = 4.4, krok = 0.15, t;
	float	x = xStart;

	cout << "Аргумент" << "\t" << "Відємні" << endl ;

	while (x <= xEnd)
	{

		t = 3 * pow(y, 1. / 3) / x * cos(x + fi) + log10(x);

		if (t < 0)
		{
			cout << x << "\t\t" << t << endl;

		}
		x += krok;
	}

	x = xStart;

	cout << "Аргумент" << "\t" << "Додатні" << endl;

	while (x <= xEnd)
	{
		t = 3 * pow(y, 1. / 3) / x * cos(x + fi) + log10(x);


		if (t > 0)
		{
			cout << x << "\t\t" << t << endl;
		}

		x += krok;

	}

	getchar();
	return 0;
}
