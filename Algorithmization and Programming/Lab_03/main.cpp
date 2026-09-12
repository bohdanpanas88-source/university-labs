#include <iostream>
#include <math.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << L"-------------------------------Лабораторна робота1--------------------------------" << endl;
    wcout << L"--------------------------Робота з типами float і short-------------------------------" << endl;

    wcout << L"\n--------------Завдання 1------------------" << endl;
    float a = 0;
    short b = 0;
    wcout << L"Введіть ціле число: ";
    wcin >> b;
    wcout << L"Введіть ціле число: ";
    wcin >> a;

    wcout << L"\n------------Завдання 2------------------" << endl;
    short shortRes = b / a + a;
    float floatRes = b / a + a;
    wcout << L"\nРезультат збережений у змінних \nРізного типу." << endl;
    wcout << ((shortRes == floatRes) ? L"Результати співпадають!!!" : L"Результати не співпадають!!!") << endl;

    wcout << L"------------Завдання 3-------------" << endl;
    short newA = a;
    wcout << L"\nНеявне перетворення типів(float в short)" << endl;
    wcout << L"\tЗначення до перетворення: " << a;
    wcout << L"\tЗначення після перетворення: " << newA << endl;

    wcout << L"\n----------Завдання 4-------------" << endl;
    float newB = (float)b;
    wcout << L"\nЯвне перетворення типів(short в float)" << endl;
    wcout << L"\tЗначення до перетворення: " << b;
    wcout << L"\tЗначення після перетворення: " << newB << endl;

    wcout << L"\n--------Завдання 5--------------" << endl;
    bool compare;
    wcout << L"\nРезультат порівняння: " << endl;
    compare = (a == b);
    wcout << L"\t(a == b) Результат: " << compare << endl;
    compare = (a >= b);
    wcout << L"\t(a >= b) Результат: " << compare << endl;

    wcout << L"\n-------Завдання 6--------------" << endl;
    wcout << L"\nПри перетворенні типів float в short ";
    wcout << ((newA == a) ? L"обрізання не відбулося" : L"відбулося обрізання") << endl;

    wcout << L"\n------Завдання 7---------------" << endl;
    wcout << L"Змінна a займає " << sizeof(a) << L" байти" << endl;
    wcout << L"Змінна b займає " << sizeof(b) << L" байти" << endl;

    wcout << L"\n------Завдання 8---------------" << endl;
    wcout << L"Адреса змінної a: " << &a << endl;
    wcout << L"Адреса змінної b: " << &b << endl;

    return 0;
}
