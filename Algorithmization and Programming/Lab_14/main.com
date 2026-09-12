#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	std::cout << "\n\t\tTask_1\n";

	size_t N = 100, n = 20;
	char* wordReplaced = new char[n];
	char* wordSubstitute = new char[n];
	char* str_1 = new char[N];

	std::cout << "\n\tВведіть строку зі словом весна або без нього:\n";
	std::cin.getline(str_1, N);
	std::cout << "\n\tВВедіть слово яке хочете замінити у тексті: ";
	std::cin.getline(wordReplaced, n);
	std::cout << "\n\tВВедіть слово на яке замінити: ";
	std::cin.getline(wordSubstitute, n);
    
	std::cout << "\n\n\tТекст:\n";
	char* nextToken = nullptr;
	char* word_1 = strtok_s(str_1, " ", &nextToken);
	while (word_1)
	{
			if (strcmp(wordReplaced,word_1) == 0)
			{
				word_1 = wordSubstitute;
				std::cout << word_1 << "\t";
			}
			else
			{
				std::cout << word_1 << "\t";
			}
		
		word_1 = strtok_s(nullptr, " ", &nextToken);
	}


	delete[] str_1;
	delete[] wordReplaced;
	delete[] wordSubstitute;

	std::cout << "\n\t\tTask_2\n";

	char* str_2 = new char[N];
	char* words[100];
	int count = 0, index;

	std::cout << "\n\tВведіть текст: ";
	std::cin.getline(str_2, N);
	 
	

	char* word_2 = strtok_s(str_2, " ", &nextToken);
	while (word_2) {
		words[count++] = word_2;
		word_2 = strtok_s(nullptr, " ", &nextToken);
	}

	for (size_t i = 0; i < count; ++i)
	{
		bool alredy = false;
		for (size_t k = 0; k < i; ++k)
		{
			if (strcmp(words[i], words[k]) == 0)
			{
				alredy = true;
				break;
			}
		}

		if (alredy)
		{
			continue;
		}

		index = 0;
		for (size_t j = i; j < count; ++j)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				++index;
			}
		}
		std::cout << i+1 << ") " << words[i] << "\tкількість: " << index << "\n";
	}

	delete[] str_2;
	return 0;

}
