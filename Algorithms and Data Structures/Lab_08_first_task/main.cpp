#include <iostream>
#include <iomanip>
#include <cmath>

void linearRecursion(float x_end, float x_start)
{
    float b = 0.15, a;
    float i = x_start;
    if (i > x_end + 0.0001) return;

    linearRecursion(x_end, i + 0.1);

    if (i < 0.5)
    {
        a = 0.1;
    }
    else if (0.5 <= i && i <= 1)
    {
        a = 0.5;
    }
    else if (i > 1)
    {
        a = 1;
    }

    std::cout << (pow(a, i) + pow(b, -i)) / (pow(sin(b * i), 2) + 1.24) << "\n";
}

void tailRecursion(float x_end, float x_start)
{
    float b = 0.15, a;
    float i = x_start;

    if (i > x_end + 0.0001) return;

    if (i < 0.5)
    {
        a = 0.1;
    }
    else if (0.5 <= i && i <= 1)
    {
        a = 0.5;
    }
    else if (i > 1)
    {
        a = 1;
    }

    std::cout << (pow(a, i) + pow(b, -i)) / (pow(sin(b * i), 2) + 1.24) << "\n";

    tailRecursion(x_end, i + 0.1);
}

int main()
{
	float x_end = 2.6, x_start = 0.1;
	int caseNumber;
   

	std::cout << "\tEnter (1) if you need linea recursion  or (2) if you need tail recursion: ";
    do
    {
        std::cin >> caseNumber;
        switch (caseNumber)
        {
        case 1:  linearRecursion(x_end, x_start); break;
        case 2:  tailRecursion(x_end, x_start); break;
        default: std::cout << "Wrong number, enter again: "; break;
        }
    } while (caseNumber > 2 || caseNumber < 1);

  
    return 0;
}
