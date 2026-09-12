#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << "                            Лаболаторна робота 9" << endl;
	cout << "                                    Завдання 1" << endl;

	const int n = 8, m = 7;
	int A[n][m], diag;

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = rand() % 20;
			cout << A[i][j] << "\t";
		}
	}
	cout << endl << endl;

	for (int j = 0; j < m; ++j)
	{
		diag = A[j][j];
		if (diag != 0)
		{
			for (int i = 0;i < n; ++i)
			{
				A[i][j] /= diag;
			}
		}

	}
	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			cout << A[i][j] << "\t";
		}
	}

	system("pause");
	return 0;
}
