#include <iostream>
#include <cmath>

void print(float** arr, int n, int m)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			std::cout << arr[i][j] << "\t\t";
		}
		std::cout << "\n";
    }
}

int main()
{
	std::cout << "\t\tTask_1\n\n";
	size_t n = 4, m = 4;

	float** A = new float* [n];
	float** B = new float* [n];
	float** C = new float* [n];
	for (size_t i = 0; i < n; ++i)
	{
		A[i] = new float[m];
		B[i] = new float[m];
		C[i] = new float[m];
	}

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			A[i][j] = tan(pow(i, 3) + pow(j, 3));
			B[i][j] = (i - 4) * cos(j);

		}
	}

	std::cout << "\n\t\tMatrix A\n\n";
	print(A,n,m);
	std::cout << "\n\t\tMatrix B\n\n";
	print(B,n,m);

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			if (i % 2 != 0)
			{
				C[i][j] = A[i][j];
			}
			else if (i % 2 == 0)
			{
				C[i][j] = B[i][j];
			}
		}
	}
	std::cout << "\n\t\tMatrix C\n\n";
	print(C, n, m);

	for (size_t i = 0; i < n; ++i)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] B;
	delete[] C;

	system("pause");
	return 0;
}
