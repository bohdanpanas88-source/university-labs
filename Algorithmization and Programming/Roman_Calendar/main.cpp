#include <iostream>
using namespace std;

int main() 
{
    int day, month, year;
    int c, y, m;
    int weekday;

    cout << "Введіть дату: день, місяць, рік " << endl;
    cin >> day >> month >> year;

    if(month == 1 || month == 2 ) year--;
    m = month - 2;
    if( m <= 0) m += 12;
    c = year / 100;
    y = year - c * 100;
    weekday = (day + (13 * m - 1) / 5 + y +y / 4 + c / 4 - 2 * c + 777) % 7;

    switch(weekday)
    {
        case 1: cout <<"Monday" <<endl; break;
        case 2: cout <<"Tuesday" <<endl; break;
        case 3: cout <<"Wensday" <<endl; break;
        case 4: cout <<"Thursday" <<endl; break;
        case 5: cout <<"Friday" <<endl; break;
        case 6: cout <<"Suturday" <<endl; break;
        case 0: cout <<"Sunday" <<endl; break;
    }

    system("pause");
    return 0;
}
