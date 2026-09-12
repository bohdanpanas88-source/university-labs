#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	const int n = 6, m = 8;
	int A[n][m] , max ;
	
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = rand() % 30 - 15;
			cout << A[i][j] << "\t";
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{

			if (abs(A[i][j]) > max)
			{
				max = abs(A[i][j]);
			}
		}
	}

	cout << endl;
	cout << "Найбільший елемент за абсолютною величиною :" << max << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = A[i][j] / max;
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

	getchar();
	return 0;
}
