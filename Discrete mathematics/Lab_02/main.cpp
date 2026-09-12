#include <iostream>
#include <cmath>
#include <conio.h>
#include <random>

int main()
{
	std::cout << "\t\tTask_2\n";
	float seredne = 0, index = 0;
	size_t N;
	std::cout << "Enter nubbers of elements: ";
	std::cin >> N;
	int* arr = new int[N];
    
	std::cout << "Array: \n";
	std::mt19937 gen(time(nullptr));
	std::uniform_int_distribution<> dis(-15, 20);
	for (size_t i = 0; i < N; ++i)
	{
		arr[i] = dis(gen);
		std::cout << arr[i] << "\t";
		if (arr[i] < 0)
		{
			seredne += arr[i];
			index++;
		}
	}
	std::cout << "\n\n";

	std::cout << "Seredne videmne: " << seredne / index << "\n";

	delete[] arr;

	system("pause");
	return 0;
}
