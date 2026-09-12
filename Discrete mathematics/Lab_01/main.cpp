#include <iostream>
#include <cmath>
#include <conio.h>

int main()
{
	std::cout << "\t\t\tTask_1\n";
	float y, x, a, b, chiselnuk, snamenuk;

	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "\nEnter a: ";
	std::cin >> a;
	std::cout << "\nEnter b: ";
	std::cin >> b;
	std::cout << "\n";

	chiselnuk = exp(sin(pow(x, 2)) + 1);
	snamenuk = pow(x + 3 * a, 1 / 5) + pow(log(b + x), 2);
	y = chiselnuk / snamenuk;
	std::cout << "Result y: " << y << "\n";

	getchar();
	return 0;
}
