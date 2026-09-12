#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

int main()
{
	std::cout << "\t\tTask_1\n";
	int k = 0, l = 0;
	float larg_modul = 0;
	size_t N = 10;
	int* A = new int[N];
	float* B = new float[N];
	 
	std::cout << "\t\tArray A: \n";
	std::mt19937 gen(time(nullptr));
	std::uniform_int_distribution<> dis(-50, 50);
	for (size_t i = 0; i < N; ++i)
	{
		A[i] = dis(gen);
		std::cout << A[i] << "\t";

		if (A[i] < 0)
		{
			l++;	
		}
		if (A[i] > A[k])
		{
			k = i;
		}
	}
	std::cout << "\n\n\n";
	std::cout << "Number of negative elements A: " << l << "\n";
	std::cout << "Index  of the largest elment A: " << k+1 << "\n\n\n";

	std::cout << "\t\tArray_B: \n";
	for (size_t i = 0; i < N; ++i)
	{
		if (A[i] <= 0)
		{
			B[i] = pow(A[i], 3) + pow(cos(A[i] + k), 2);
		}
		else if (A[i] > 0)
		{
			B[i] = A[i] / (log(A[i] + 3) / log(3)) - sin(A[i] + l);
		}

		std::cout << B[i] << "\t\t";
	}

	larg_modul = fabs(B[0]);
	for (size_t i = 1; i < N; ++i)
	{
		if (larg_modul < fabs(B[i]))
		{
			larg_modul = fabs(B[i]);
		}
	}
	std::cout << "\n\n\nLargest element B by modul: " << larg_modul << "\n\n";

	delete[] A;
	delete[] B;

	system("pause");
	return 0;
}
