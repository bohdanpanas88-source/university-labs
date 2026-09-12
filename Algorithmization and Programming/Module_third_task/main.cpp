#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	float x, y;
	cout << "x =";
	cin >> x;

	if (x < 7) {
		y = exp(abs(x - 1.2)) / pow(cos(5.7 * x), 2);
		cout << "1 умова" <<endl;
	}
	else if (x >= 7 && x < 11) {
		y = pow(x + 1.8, 0.2);
		cout << "2 умова" <<endl;
	}
	else if (x >= 11) {
		y = pow(x - 5.7, 1 / 3) + 1.2;
		cout << "3 умова" <<endl;
	}

	cout << "y = " << y << endl;

	getchar();
	return 0;

}
