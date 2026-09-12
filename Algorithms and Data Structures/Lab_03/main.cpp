#include <iostream>
#include <random>
#include <ctime>

void sorting(int* arr_2, size_t N)
{
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = i + 1; j < N; ++j)
		{
			if (arr_2[i] > arr_2[j])
			{
				int temp = arr_2[i];
				arr_2[i] = arr_2[j];
				arr_2[j] = temp;
			}
		}
	}
}

void vuvid(int* arr_3, size_t N)
{
	std::cout << "Sorted array: ";
	for (size_t i = 0; i < N; ++i)
	{
		std::cout << arr_3[i] << "\t";
	}
}

int poshukElementa(int* arr, size_t N, int elem)
{
	size_t L = 0,m = 0, R = N - 1;
	while (L <= R)
	{
		m = (L + R) / 2;
		if (arr[m] == elem)
		{
			return m;
		}
		else if (arr[m] < elem)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	}
	return -1;

}

int main()
{
	std::cout << "\t\tTask_1\n";
	size_t N;
	int element;
	std::cout << "Enter the size of the array: ";
	std::cin >> N;

	int* arr_1 = new int[N];
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> dis(-20, 20);
	
	for (size_t i = 0; i < N; ++i)
	{
		arr_1[i] = dis(gen);
	}
	sorting(arr_1, N);
	vuvid(arr_1, N);

	std::cout << "\nWhat is element you need: ";
	std::cin >> element;

	int ind = poshukElementa(arr_1, N, element);
	
	if (ind == -1)
	{
		std::cout << "Element not found in the array: ";
		delete[] arr_1;
		return 0;
	}
	else
	{
		std::cout << "Index of element :" << ind + 1 << "\n";
	}

	delete[] arr_1;
	return 0;
	
}
