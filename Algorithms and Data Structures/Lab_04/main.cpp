#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>

void tabulation(float* Array, int N)
{
    float b = 0.15, x_start = 0.1, x_end = 2.6, x_krok = 0.1, a;
    float i = x_start;
    for (int j = 0; j < N; ++j)
    {
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

        Array[j] = (pow(a, i) + pow(b, -i)) / (pow(sin(b * i), 2) + 1.24);
        i += x_krok;
    }
}

void RandomSorting(float* Array, int N)
{
    for (int i = 0; i < N; i++)
    {
        int j = rand() % N;
        float temp = Array[i];
        Array[i] = Array[j];
        Array[j] = temp;
    }
}

void sortBuble(float* Array, int N)
{
    int comparison = 0, exchange = 0;
    for (size_t step = 1; step < N; ++step)
    {
        for (size_t i = 0; i < N - step; ++i)
        {
            ++comparison;
            if (Array[i] > Array[i + 1])
            {
                float temp = Array[i];
                Array[i] = Array[i + 1];
                Array[i + 1] = temp;
                ++exchange;
            }
        }
    }
    std::cout << "\n\tNumber of buuble  sort comparison: " << comparison;
    std::cout << "\n\tNumber of buuble  sort swap: " << exchange;
}

void sortVstavka(float* Array, int N)
{
    int comparison = 0, exchange = 0, j;
    for (size_t i = 1; i < N; ++i)
    {
        float rab = Array[i];
        j = i - 1;
        while (j >= 0)
        {
            ++comparison;

            if (Array[j] > rab)
            {
                Array[j + 1] = Array[j];
                --j;
                ++exchange;
            }
            else break;
        }
        Array[j + 1] = rab;
    }


    std::cout << "\n\tNumber of insertion  sort comparison: " << comparison;
    std::cout << "\n\tNumber of insertion  sort swap: " << exchange;
}

void sortSelection(float* Array, int N)
{
    int comparison = 0, exchange = 0;
    for (size_t i = 0; i < N; ++i)
    {
        int minIndex = i;
        for (size_t j = i + 1; j < N; ++j)
        {
            ++comparison;
            if (Array[j] < Array[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            float temp = Array[i];
            Array[i] = Array[minIndex];
            Array[minIndex] = temp;
            ++exchange;
        }
    }
    std::cout << "\n\tNumber of Selection  sort comparison: " << comparison;
    std::cout << "\n\tNumber of Selection  sort swap: " << exchange;
}


void VuvidTabulation(float* Array, int N)
{
    float x_start = 0.1, x_end = 2.6, x_krok = 0.1, i;
    std::cout << "\n\n\tKrok" << "\t\tElement\n";
    i = x_start;
    for (int j = 0; j < N; ++j)
    {
        std::cout << "\t+---+-----------+-------+\n";
        std::cout << "\t|" << i << "|\t\t|" << Array[j] << "|\t\n";
        i += x_krok;
    }
    std::cout << "\t+---+-----------+-------+\n";

}

int main()
{
    int i = 1;
    int value = ++i;
    std::cout << value<<std::endl;
    std::cout << i<<std::endl;




    size_t N = 26;
    float b = 0.15, x_start = 0.1, x_end = 2.6, x_krok = 0.1;
    int caseNumber;
    srand(time(0));

    float* Array = new float[N];
    tabulation(Array, N);             // Масив табулюєця за зростанням по формулі
    RandomSorting(Array, N);          // Я його перемішую, щоб відсортувати за зростанням (2-ма методами)

    std::cout << "\n\n\tThe array isnt sorted:";
    VuvidTabulation(Array, N);

    std::cout << "\n\n\tEnter 1: if need sortObmin, 2: sortBstavka, 3: sortSelection. ";
    do
    {
        std::cin >> caseNumber;
        switch (caseNumber)
        {
        case 1:  sortBuble(Array, N); break;
        case 2:  sortVstavka(Array, N); break;
        case 3:  sortSelection(Array, N); break;
        default: std::cout << "Wrong number, enter again: "; break;
        }
    } while (caseNumber > 3 || caseNumber < 1);

    std::cout << "\n\n\tSorted array:";
    VuvidTabulation(Array, N);

    delete[] Array;
    return 0;
}
