#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    clock_t start, end;
    start = clock();
    std::cout << "               Task_1               " << "\n";

    const int N = 2;
    int y[N], m[N], d[N];

    for (size_t i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ")Enter: year, month, day: ";
        std::cin >> y[i] >> m[i] >> d[i];
        std::cout << "\n";

    }

    std::cout << "               Task_2                " << "\n";

    std::tm date[N] = {};
    time_t dat[N];
    for (int i = 0; i < N; ++i)
    {
        date[i].tm_year = y[i] - 1900;
        date[i].tm_mon = m[i] - 1;
        date[i].tm_mday = d[i];
        dat[i] = mktime(&date[i]);

    }


    std::cout << "Date earlier: ";
    if (dat[0] < dat[1])
    {
        std::cout << "date1" << "\n";
    }
    else if (dat[0] > dat[1])
    {
        std::cout << "date2" << "\n";
    }
    else
    {
        std::cout << "date1 == date2" << "\n";
    }

    std::cout << "                Task_3                 " << "\n";
    double rizn = std::difftime(dat[0], dat[1]) / 86400;
    std::cout << "rizn = " << std::abs
    (rizn) << "\n";

    std::time_t t = time(nullptr);
    tm tinfo;
    localtime_s(&tinfo, &t);
    char array[80];
    std::strftime(array, sizeof(array), "%d.%m.%Y %H:%M:%S", &tinfo);

    std::cout << "Current date and time: " << array << "\n";

    end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << time << "\n";
    return 0;

}
