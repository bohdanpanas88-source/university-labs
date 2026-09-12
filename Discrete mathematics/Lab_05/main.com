#include <iostream>
#include <cmath>

int main()
{
    std::cout << "\t\tTask_1\n";
    int factorial = 1, max_ind = 0, min_ind = 0;
    size_t m = 10;
    float* A = new float[m];
    float x = 1.25, znam = 0, min = 0, max = 0;

    std::cout << "\t\tArray A:\n";
    for (size_t i = 1; i <= m; ++i)  
    {
        if (i == 1)
            factorial = 1;
        else
            factorial *= i;

        znam = pow(x + factorial, 3);
        A[i - 1] = pow(sin(znam), 2) / (pow(i, 2) - 3.1) + pow(x, 2.0 / i);

        std::cout << A[i - 1] << "\n";
    }

    max = A[0];
    min = A[0];
    for (size_t i = 1; i < m; ++i)
    {
        if (max < A[i])
        {
            max = A[i];
            max_ind = i;
        }
        else if (min > A[i])
        {
            min = A[i];
            min_ind = i;
        }
    }


    std::cout << "\nMax_elem: " << max << "\nMin_elem: " << min << "\n";

    int start = (min_ind < max_ind) ? min_ind + 1 : max_ind + 1;
    int end = (min_ind < max_ind) ? max_ind - 1 : min_ind - 1;

    for (size_t i = start; i <= end; ++i)
    {
        for (size_t j = start; j < end - (i - start); ++j)
        {
            if (A[j] > A[j + 1])  
            {
                float temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    std::cout << "\n\t\tNew Array_A: \n";
    for (size_t i = 0; i < m; ++i)
    {
        std::cout << A[i] << "\n";
    }

    delete[] A;
    return 0;
}
