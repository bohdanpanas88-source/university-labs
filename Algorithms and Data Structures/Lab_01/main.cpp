#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	std::cout << "----------------------------First_task-----------------------" << "\n";
	float a, t1, t2;
	int y, x;

	std::cout << "Enter integer x and y: ";
	if (!(std::cin >> x >> y))
	{
		std::cout << "Error" "\n";
		return 1;
	}
	
	t1 = fabs(y + pow(x, 3) / .3);
	t2 = pow(y, 2) + pow(x, 2) / t1;
	a = y + x / t2;
	std::cout << "a = " << a << "\n";

	std::cout << "----------------------------Second_task-----------------------" << "\n";
	float S, P, R;
	std::cout << "Enter R: ";
	std::cin >> R;
	if (R < 0 || R == 0)
	{
		std::cout << "R must be > 0" << "\n";
		return 1;
	}
	S = M_PI * pow(R, 2);
	P = 2 * M_PI * R;
	std::cout << "S = " << S << std::setw(8) << "P = " << P << "\n";

	system("pause");
	return 0;
}
