#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[]) {

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int a, b;

	cout << "----------------------Обрахування тригонометричнтх функцій(в градусах)-----------------------------" << endl;

	cout << "Meню:" << endl;
	cout << "\tВведіть число (1) якщо хочете обрахувати sin(a)." << endl;
	cout << "\tВведіть число (2) якщо хочете обрахувати cos(a)." << endl;
	cout << "\tВведіть число (3) якщо хочете обрахувати tg(a)." << endl;
	cout << "Ваш вибір: b =";
	cin >> b;

	cout << "\tВведіть число для обрахування вибраної функції =";
	cin >> a;

	switch (b) {
	case 1:cout << "\tОбрахування sin(a) =" << sin(a); break;
	case 2:cout << "\tОбрахування cos(a) =" << cos(a); break;
	case 3:cout << "\tОбрахування tg(a) =" << tan(a); break;
	default:cout << "\tПомилка При виборі пункту \"Меню\"!"; break;
	}
	 
	while (!_kbhit());
	return 0;

}
