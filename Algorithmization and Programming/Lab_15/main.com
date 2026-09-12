#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

int getUkIndex(wchar_t c) {
    wchar_t l = towlower(c);

    if (l >= L'а' && l <= L'е') return (l - L'а' + 1);
    if (l == L'є') return 7;
    if (l >= L'ж' && l <= L'и') return (l - L'ж' + 8);
    if (l == L'і') return 12;
    if (l == L'ї') return 13;
    if (l == L'й') return 14;
    if (l >= L'к' && l <= L'я') return (l - L'к' + 15);

    return 0; 
}


bool isInRange(wchar_t c) {
    int index = getUkIndex(c);
    return (index >= 12 && index <= 33);
}

void transformTask1(std::wstring& word) {
    if (word.length() < 2) return;
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (isInRange(word[i])) {
            wchar_t temp = word[i];
            word[i] = word[i + 1];
            word[i + 1] = temp;

            i++;
        }
    }
}

void transformTask2(std::wstring& word) {
    if (word.length() < 2) return;
    wchar_t temp = word[0];
    word[0] = word[word.length() - 1];
    word[word.length() - 1] = temp;
}

int main() {
    std::setlocale(LC_ALL, "");

    std::wstring text;
    std::wcout << L"Введіть текст: ";
    std::getline(std::wcin, text);

    std::wcout << L"\nЗавдання 1 (циклічний зсув літер від 'і' до 'я'):\n";
    size_t start = 0;
    for (size_t i = 0; i <= text.length(); ++i) {
        if (i == text.length() || text[i] == L' ') {
            size_t len = i - start;
            if (len > 0) {
                std::wstring word = text.substr(start, len);
                transformTask1(word);
                std::wcout << word << L" ";
            }
            start = i + 1;
        }
    }

    std::wcout << L"\n\nЗавдання 2 (перестановка першої і останьої букви в слові):\n";
    start = 0;
    for (size_t i = 0; i <= text.length(); ++i) {
        if (i == text.length() || text[i] == L' ') {
            size_t len = i - start;
            if (len > 0) {
                std::wstring word = text.substr(start, len);
                transformTask2(word);
                std::wcout << word << L" ";
            }
            start = i + 1;
        }
    }

    std::wcout << "\n";
    return 0;
}
