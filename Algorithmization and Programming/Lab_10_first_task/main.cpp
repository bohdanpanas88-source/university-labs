#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char* str1 = new char[100];

    strcpy(str1, "Надійшла весна прекрасна , многоцвітна , тепла , ясна .");


    cout << "Виведення стрічки: " << endl << " str1 = " << str1 << endl;

    char* chang = new char[100];
    char* word = strtok(str1, " ");
    char a[20], b[20];
    cout << "Введіть слово яке потрібно вставити в текст: ";
    cin >> b;
    cout << "Введіть слово яке потрібно замінити: ";
    cin >> a;
    cout << endl;


    while (word != 0)
    {
        if (strcmp(word, a) == 0)
        {
            strcpy(word, b);
        }

        if (strlen(chang) > 0)
            strcat(chang, " ");
        strcat(chang, word);

        word = strtok(0, " ");
    }

    cout << "Змінений текст:" << chang << endl;

    delete[] str1;
    delete[] chang;
    system("pause");
    return 0;
}
