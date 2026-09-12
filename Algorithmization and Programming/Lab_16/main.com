#include <iostream>
#include <random>

template <typename T>
void MaxElem(T** array, int n)
{
	if (n < 1) return ;

	T Max_Elem_diag = array[0][0];
	int index_i = 0, index_j = 0;

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (i + j < n - 1)
			{
				if (array[i][j] > Max_Elem_diag)
				{
					Max_Elem_diag = array[i][j];
					index_i = i;
					index_j = j;
				}
			}
		}
	}
	std::cout << "\nMax above secondary diagonal: Array[" << index_i+1 << "][" << index_j+1 << "] = " << Max_Elem_diag << "\n";
}

template <typename T>
void randing(T** array, int n)
{
	std::mt19937 gen(time(nullptr));
	std::uniform_real_distribution<> dis(-20.0, 20.0);

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			array[i][j] = dis(gen);
			std::cout << array[i][j] << "\t\t";
		}
		std::cout << "\n";
	}
}

template <typename T>
void Array(int n)
{
	T** array = new T* [n];
	for (size_t i = 0; i < n; ++i)
		array[i] = new T [n];

	randing(array, n);
	MaxElem(array, n);

	for (int i = 0; i < n; ++i)
		delete[] array[i];
	delete[] array;
}

int main()
{
	size_t n;
	std::cout << "Enter n*n array: ";
	std::cin >> n;
	
	int choice;

	std::cout << "\t\tMenu:\n";
	std::cout << "\t1)Type INT; \n \t2)Type FLOAT; \n \t3)Type DOUBLE;\n\tENTER: ";
	do
	{
		std::cin >> choice;

		switch (choice)
		{
		case 1: Array<int>(n); break;
		case 2: Array<float>(n); break;
		case 3: Array<double>(n); break;
		default: std::cout << "Error. Enter again: ";
		}
	} while (choice != 1 && choice != 2 && choice != 3);

	return 0;
}
