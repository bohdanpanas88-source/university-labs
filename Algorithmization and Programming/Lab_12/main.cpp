#include <iostream>
#include <conio.h>

float GetSide();
float Perimeter(float a, float y);

int main()
{
	float a, b;

	a = GetSide();
	b = GetSide();
	std::cout << "Perimeter: " << Perimeter(a, b) << "\n";

	system("pause");
	return 0;
}

float GetSide()
{
	float x;
	
	std::cout << "Enter side: ";
	std::cin >> x;
	while(x < 0 || x == 0)
	{	
	   std::cout << "Incorrect value.Enter additional number: ";
	   std::cin >> x;
	   continue;
	}
	std::cout << "Correct value.\n";
	return x;
}

float Perimeter(float a, float y)
{
	float p;
	p = (a + y) * 2;
	return p;
}
