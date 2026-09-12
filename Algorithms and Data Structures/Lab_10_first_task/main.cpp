#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>

double get_max(double a, double b) 
{
    return (a > b) ? a : b;
}

double get_min(double a, double b) 
{
    return (a < b) ? a : b;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}


bool intersect_1d(double a, double b, double c, double d)
{
    if (a > b)
    {
        double tmp = a; a = b; b = tmp;
    }
    if (c > d) 
    {
        double tmp = c; c = d; d = tmp; 
    }
    return get_max(a, c) <= get_min(b, d);
}

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;

    printf("Enter segment 1 (x1 y1 x2 y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    printf("Enter segment 2 (x3 y3 x4 y4): ");
    scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);

    bool box = intersect_1d(x1, x2, x3, x4) && intersect_1d(y1, y2, y3, y4);

    double a1 = area(x1, y1, x2, y2, x3, y3);
    double a2 = area(x1, y1, x2, y2, x4, y4);
    double a3 = area(x3, y3, x4, y4, x1, y1);
    double a4 = area(x3, y3, x4, y4, x2, y2);

    if (box && (a1 * a2 <= 0) && (a3 * a4 <= 0))
        printf("\nResult: they intersect.\n");
    else
        printf("\nResult: they do not intersect.\n");

    return 0;
}
