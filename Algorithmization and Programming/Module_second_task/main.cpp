#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a, b;
	float c;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (b >= 10 && b <= 400) {
		c = a / b;
		cout << "1 умова." <<endl;
	}
	else {
		c = a * b;
		cout << "2 умова." <<endl;
	}

	cout << "c = " << c << endl;

	getchar();
	return 0;

}
