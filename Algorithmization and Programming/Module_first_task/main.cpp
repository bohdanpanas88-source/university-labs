#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
	int N = 8, Q_n = 6250;
	float L = 4206.5, delta_t = 2.83, k = 0.82; 
	float Q_2n, m;

	Q_2n = k * delta_t;
	m = N * L / 1000 * (Q_n - Q_2n) * delta_t / pow(delta_t,2);

		cout << "Q_2n = " << Q_2n <<endl << "m = " << m << endl;

	getchar();
	return 0;
}
