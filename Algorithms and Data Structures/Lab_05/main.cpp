#include <iostream>
#include <random>

void GenArray(int* Array[], int n)
{
	std::mt19937 gen(time(nullptr));
	std::uniform_int_distribution<> dis(-20, 20);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			Array[i][j] = dis(gen);
		}
	}
}

void vuvidArray(int* Array[], int n)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			std::cout << Array[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

void shellSort(int* Array[], int n)
{
	int* diag = new int[n];

	for (size_t i = 0; i < n; ++i)
	{
		diag[i] = Array[i][i];
	}


	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < n; ++i)
		{
			int temp = diag[i];
			int j;
			for (j = i; j >= gap && diag[j - gap] < temp; j -= gap)
			{
				diag[j] = diag[j - gap];
			}
			diag[j] = temp;
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		Array[i][i] = diag[i];
	}

	delete[] diag;
}

int main()
{
	size_t n = 6, m = 6;
	int** Array = new int* [n];
	for (size_t i = 0; i < n; ++i)
	{
		Array[i] = new int[m];
	}

	GenArray(Array, n);

	std::cout << "\n\tOld Array:\n";
	vuvidArray(Array, n);
	shellSort(Array, n);

	std::cout << "\n\tNew Array:\n";
	vuvidArray(Array, n);

	for (size_t i = 0; i < n; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;

	return 0;
}
