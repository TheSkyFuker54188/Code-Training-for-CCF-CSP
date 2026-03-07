#include <iostream>
#include <cstdio>

using namespace std;

// todo   星期计算公式`(初始星期 + 偏移天数 - 1) % 7 + 1`

int m_day[1 + 12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_sumd[1 + 12]; // 截止idx月1日，一共几天

int a, b, c, y1, y2;

bool leap(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> a >> b >> c >> y1 >> y2;

    int year_sumd = 0;
    for (int i = 1850; i < y1; i++)
        year_sumd += 365 + leap(i);

    month_sumd[0] = 0;
    for (int i = 1; i <= 12; i++)
        month_sumd[i] = month_sumd[i - 1] + m_day[i - 1]; // 先不算闰年，得到每月1日的偏移天数

    int w = (2 + year_sumd - 1) % 7 + 1; // y1年的1月1日星期几？

    for (int y = y1; y <= y2; y++)
    {
        bool flag = false;

        // int a_day;
        bool post_Feb = false;
        if (leap(y) && a >= 3)
            post_Feb = true;

        int w_a = (w + month_sumd[a] + post_Feb - 1) % 7 + 1; // y年a月1日星期几？

        int cnt_c = 0;
        int w_today = w_a;

        int days_thismonth = m_day[a];
        if (leap(y) && a == 2)
            days_thismonth += 1;
        for (int d = 1; d <= days_thismonth; d++)
        {
            if (w_today == c)
            {
                cnt_c++;
                if (cnt_c == b)
                {
                    flag = true;
                    printf("%d/%02d/%02d\n", y, a, d);
                }
            }
            w_today = w_today % 7 + 1;
        }
        if (flag == false)
        {
            cout << "none\n";
        }

        w = (w + 365 + leap(y) - 1) % 7 + 1;
    }
    return 0;
}