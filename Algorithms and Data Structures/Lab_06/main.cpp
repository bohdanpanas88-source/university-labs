#include <iostream>
#include <random>

void forming(int** array, int n)
{
	std::mt19937 gen(time(nullptr));
	std::uniform_int_distribution<> dis(-10, 10);

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			array[i][j] = dis(gen);
		}
	}

}

void Conclusion(int** array, int n)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

void heapify(int* diag, int n, int i)
{
	int smallest = i;
	int L = 2 * i + 1;
	int R = 2 * i + 2;

	if (L < n && diag[L] < diag[smallest])
		smallest = L;

	if (R < n && diag[R] < diag[smallest])
		smallest = R;

	if (smallest != i)
	{
		int temp = diag[i];
		diag[i] = diag[smallest];
		diag[smallest] = temp;
		heapify(diag, n, smallest);
	}
}

void HeapSort(int** array, int n)
{
	int* diag = new int[n];
	for (size_t i = 0; i < n; ++i)
		diag[i] = array[i][i];

	for (int i = n / 2 - 1; i >= 0; --i)
		heapify(diag, n, i);

	for (int i = n - 1; i > 0; --i)
	{
		int temp = diag[0];
		diag[0] = diag[i];
		diag[i] = temp;
		heapify(diag, i, 0);
	}

	for (size_t i = 0; i < n; ++i)
		array[i][i] = diag[i];

	delete[] diag;
}

void ShellSort(int** array, int n)
{
	int* diag = new int[n];
	for (size_t i = 0; i < n; ++i)
		diag[i] = array[i][i];

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
		array[i][i] = diag[i];
	}

	delete[] diag;
}



int main()
{
	
	const int n = 6;
	int** array = new int* [n];
	for (size_t i = 0; i < n; ++i)
		array[i] = new int[n];

	forming(array, n);

	std::cout << "\n\n\tArray befor Sort: \n";
	Conclusion(array, n);

	size_t enter;
	std::cout << "Enter (1) if you want  Shell Sort or (2) Heap Sort: ";
	
	do
	{
		std::cin >> enter;
		switch (enter)
		{
		case 1: ShellSort(array, n); break;
		case 2: HeapSort(array, n); break;
		default: std::cout << "Error! Enter again (1 or 2): "; break;
		}
	} while (enter != 1 && enter != 2); 


	std::cout << "\n\n\tArray after Sort: \n";
	Conclusion(array, n);

	for (size_t i = 0; i < n; ++i)
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;

}
