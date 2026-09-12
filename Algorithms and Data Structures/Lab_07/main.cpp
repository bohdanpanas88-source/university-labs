#include <iostream>
#include <conio.h>
#include <cmath>

long assignments = 0;
long comparisons = 0;

void AbstractMerge(int* Array, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (size_t i = 0; i < n1; ++i)
	{
		L[i] = Array[l +i];
		++assignments;
	}

	for (size_t j = 0; j < n2; ++j)
	{
		R[j] = Array[m + 1 + j];
		++assignments;
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		++comparisons;
		if (L[i] <= R[j])
		{
			Array[k] = L[i];
			++i;
		}
		else
		{
			Array[k] = R[j];
			++j;
		}
		++assignments;
		++k;
	}

	while (i < n1)
	{
		Array[k] = L[i];
		++i;
		++k;
		+assignments;
	}
	while (j < n2)
	{
		Array[k] = R[j];
		++j;
		++k;
		++assignments;
	}

	delete[] L;
	delete[] R;
}

void TwoWayMergeSort(int* Array, int L, int R)
{
	if (L < R)
	{
		int m = L + (R - L) / 2;

		TwoWayMergeSort(Array, L, m);
		TwoWayMergeSort(Array, m + 1, R);

		AbstractMerge(Array, L, m, R);
	}
}

int SizeArray()
{
	int N;
	std::cout << "\tEnter size N array (100<N<1000): ";
	do
	{
		std::cin >> N;
		if (100 >= N || N >= 1000)
		{
			std::cout << "\n Error! Enter size (100<N<1000): ";
		}
	} while (100 >= N  || N >= 1000);
	return N;
}

void ConclusionArray(int* Array, int N)
{
	for (size_t i = 0; i < N; ++i)
	{
		std::cout << Array[i] << "\t";
	}
}

void Progresion(int* Array,int N)
{

	size_t d;
	long long S = 0;
	std::cout << "\n\n\n Enter first element (a1) Array(unmatches): ";
	do
	{
		std::cin >> Array[0];
		if (Array[0] % 2 == 0)
		{
			std::cout << "\nError! Pleace enter unmatches element array: ";
		}
	} while (Array[0] % 2 == 0);

	std::cout << "\n\n Enter difference d Array(unmatches): ";
	do
	{
		std::cin >> d;
		if (d % 2 == 0)
		{
			std::cout << "\nError! Enter unmatches difference: ";
		}
	} while (d % 2 == 0);

	for (size_t i = 1; i < N; ++i)
	{
		Array[i] = Array[0] + d * (i - 1);
	}
	 
	std::cout << "\n\n\t\tOld not sorting Array:\n";
	ConclusionArray(Array, N);

	S = (2 * Array[0] + d * (N - 1)) * N / 2;
	std::cout << "\n\n\tSum of the array S(" << N << "):" << S << "\n";

	TwoWayMergeSort(Array, 0, N - 1);
	
	std::cout << "\nSorting Array: \n";
	ConclusionArray(Array, N);

	std::cout << "\nEfektivnist:\n";
	std::cout << "Porivnyannya: " << comparisons << "\n";
	std::cout << "Perisylanovka: " << assignments << "\n";
}

int main()
{
	const int N = SizeArray();
	int* Array = new int[N];

	Progresion(Array, N);

	delete[] Array;
	return 0;
}
