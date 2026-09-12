#include <iostream>
#include <cmath>

int main()
{
	std::cout << "            Task_1\n";

	size_t size_1 = 10;
	int* arr_1 = new int[size_1];

	std::cout << "Array_1: ";
	for (size_t i = 0; i < size_1; ++i)
	{
		arr_1[i] = (pow(i, 2) + 2) * pow(sin(i), 2);
		std::cout << arr_1[i] << "\t";
	}

	int max_1 = arr_1[0], min_1 = arr_1[0];
	int max_pos_1 = 0, min_pos_1 = 0;
	for (size_t i = 1; i < size_1; ++i)
	{
		if (arr_1[i] > max_1)
		{
			max_1 = arr_1[i];
			max_pos_1 = i;
		}
		else if (arr_1[i] < min_1)
		{
			min_1 = arr_1[i];
			min_pos_1 = i;
		}
	}

	std::cout << "\nMax element: " << max_1 << " at position: " << max_pos_1 + 1;
	std::cout << "\nMin element: " << min_1 << " at position: " << min_pos_1 + 1 << "\n\n";

	delete[] arr_1;

	std::cout << "            Task_2\n";
	size_t size_2 = 10;
	int* arr_2 = new int[size_2];

	std::cout << "Enter array elements one by one: ";
	for (size_t i = 0; i < size_2; ++i)
	{
		std::cin >> arr_2[i];
		if (i > 0)
		{
			while (arr_2[i] <= arr_2[i - 1])
			{
				std::cout << "Enter an element greater than the previous one: ";
				std::cin >> arr_2[i];
			}
			std::cout << "Element accepted" << "\n";
		}
	}

	int max_2 = arr_2[0], min_2 = arr_2[0];
	int max_pos_2 = 0, min_pos_2 = 0;
	for (size_t i = 1; i < size_2; ++i)
	{
		if (max_2 < arr_2[i])
		{
			max_2 = arr_2[i];
			max_pos_2 = i;
		}
		else if (min_2 > arr_2[i])
		{
			min_2 = arr_2[i];
			min_pos_2 = i;
		}
	}

	std::cout << "Array_2: ";
	for (size_t i = 0; i < size_2; ++i)
	{
		std::cout << arr_2[i] << "\t";
	}

	std::cout << "\nMax element: " << max_2 << " at position: " << max_pos_2 + 1;
	std::cout << "\nMin element: " << min_2 << " at position: " << min_pos_2 + 1 << "\n";

	delete[] arr_2;

	system("pause");
	return 0;
}
