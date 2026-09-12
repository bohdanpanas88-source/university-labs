#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>

double cross_product(double x1, double y1, double x2, double y2, double x3, double y3) 
{
    return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
}

int main()
{
    int n;

    printf("Enter the number of point N: ");
    if (scanf("%d", &n) != 1 || n < 3)
    {
        printf("Enter: N >= 3.\n");
        return 0;
    }

    double* X = new double[n];
    double* Y = new double[n];

    printf("Enter coordinates(x y) for each point:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &X[i], &Y[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (X[j] > X[j + 1] || (X[j] == X[j + 1] && Y[j] > Y[j + 1]))
            {
                double tempX = X[j]; X[j] = X[j + 1]; X[j + 1] = tempX;
                double tempY = Y[j]; Y[j] = Y[j + 1]; Y[j + 1] = tempY;
            }
        }
    }

    double* hX = new double[2 * n];
    double* hY = new double[2 * n];
    int hSize = 0;

    for (int i = 0; i < n; i++)
    {
        while (hSize >= 2 && cross_product(hX[hSize - 2], hY[hSize - 2], hX[hSize - 1], hY[hSize - 1], X[i], Y[i]) >= 0)
        {
            hSize--;
        }
        hX[hSize] = X[i];
        hY[hSize] = Y[i];
        hSize++;
    }

    int lowerStart = hSize + 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (hSize >= lowerStart && cross_product(hX[hSize - 2], hY[hSize - 2], hX[hSize - 1], hY[hSize - 1], X[i], Y[i]) >= 0)
        {
            hSize--;
        }
        hX[hSize] = X[i];
        hY[hSize] = Y[i];
        hSize++;
    }

    printf("\nTochky opukloi obolonky:\n");
    for (int i = 0; i < hSize - 1; i++)
    {
        printf("(%.2f, %.2f)\n", hX[i], hY[i]);

        delete[] X;
        delete[] Y;
        delete[] hX;
        delete[] hY;

        return 0;
    }
}
