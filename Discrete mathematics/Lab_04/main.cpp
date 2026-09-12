#include <iostream>
#include <cmath>
#include <conio.h>

int main()
{
	std::cout << "\t\tTask_1\n";
	float lenA = 0, lenB = 0, dob = 0, modulVect = 0;
	size_t N = 10;
	float* a = new float[N];
	float* b = new float[N];

	std::cout << "a[i]" << "\t\t" << "b[i]" << "\n";
	for (size_t i = 0; i < N; ++i)
	{
		a[i] = 2 * pow(i, 2) + cos(5 * i + 3);
		b[i] = log(i + 4) - pow(cos(i + 2), 2);
		std::cout << a[i] << "\t\t" << b[i] << "\n";
	}
    
	for (size_t i = 0; i < N; ++i)
	{
		lenA += a[i] * a[i];
		lenB += b[i] * b[i];
		dob += a[i] * b[i];
	}

	modulVect = sqrt(lenA + lenB) - pow(dob, 2);

	std::cout << "\nModul vector dobutok: " << modulVect << "\n";

	delete[] a;
	delete[] b;

	getchar();
	return 0;
}
