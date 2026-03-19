// 2015年09月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

int y, d;

int day[1 + 12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    else
        return false;
}

int main()
{
    cin >> y >> d;

    int feb = 28 + int(leap(y));
    int thisy_day[1 + 12] = {0, 31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int date = d, month = 1;
    for (int i = 1; i <= 12; i++)
    {
        date -= thisy_day[i];
        if (date > 0)
            month++;
        else
        {
            date += thisy_day[i];
            break;
        }
    }
    cout << month << endl
         << date;
    return 0;
}
