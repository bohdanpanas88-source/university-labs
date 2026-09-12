#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	char *str1 = new char[100];
	
	strcpy(str1,"Бук бундючивсь перед дубом , Тряс над дубом бурим чубом . Дуб пригнув до чуба бука — Буде букові наука .");
	cout << "Виведення стрічки: " << endl << "str1 = " << str1 << endl;

	char words[100][30];
	int count[100];
	int a = 0;
    const char* simvols = " ,.!?-";
	
	char* slova = strtok(str1, simvols);

	while (slova != 0)
	{
		bool found = false;

		for (int i = 0; i < a; i++)
		{
			if (strcmp(words[i], slova) == 0)
			{
				count[i]++;
				found = true;
				break;
			}
		}
		if (!found)
		{
			strcpy(words[a], slova);
			count[a] = 1;
			a++;
		}
		slova = strtok(0, simvols);
	}

	cout << "\tСлово" << "\t\tКількість" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < a; i++)
	{
		cout << "\t" << words[i] << "\t\t" << count[i] << endl;
	}

	system("pause");
	return 0;
} 
