#include <iostream>
#include <cstdio>

using namespace std;

int m_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //?  预处理天数
int month[15];                                                  // month[i]代表前i个月的累计天数

bool Leap(int n)
{
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) // 判断是否是闰年
    {
        return true;
    }
    return false;
}

int main()
{
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;

    int days = 0; // todo  总天数（从 1850 年到目标年份 y1 前一年的总天数偏移）

    //?  定位起始年（1850年）： 以 1850-01-01（星期二）为原点。

    //?  计算目标年 1 月 1 日的星期
    /*
    遍历 1850 到y1 - 1年
    每年加 365 天，若是闰年额外加 1 天
    结果对 7 取模
    */
    for (int i = 1850; i < y1; i++) // 从1850年开始算累计多少天
    {
        if (Leap(i))
            days += 366;
        else
            days += 365;
    }
    days %= 7;

    month[0] = 0;
    for (int i = 1; i <= 12; i++)
    {
        month[i] = month[i - 1] + m_day[i - 1];
    }

    // todo  星期的计算通常使用 (初始星期 + 偏移天数 - 1) % 7 + 1

    //?  计算目标年 1 月 1 日的星期
    int week = (2 + days - 1) % 7 + 1; // y1年的1月1日是星期几

    //?  逐年处理 y1到y2
    /*
    确定 a 月 1 日的星期。 可以根据该年 1 月 1 日的星期加上前 a-1 个月的天数偏移
    确定 a 月总天数。 注意判断该年是否为闰年且 a=2
    遍历窗口寻解。 遍历 a 月的每一天，维护一个变量记录当前是星期几，遇到星期 c 就计数，直到计满 b 次
    边界检查。 如果遍历完该月计数还没到 b，输出 none
    滚动更新。 算出该年总天数，更新下一年 1 月 1 日的星期
    */
    for (int i = y1; i <= y2; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            if (j == a) // a月
            {
                bool flag = false;
                int week1 = (week + month[j - 1] - 1) % 7 + 1;
                if (j - 1 >= 2 && Leap(i)) // 如果是闰年，2 月之后的所有月份相较于平年都会多偏移 1 天。
                    week1 = week1 % 7 + 1;

                int len = m_day[j - 1] + (j == 2 && Leap(i) ? 1 : 0);
                int sum = 0; // 计数器：当前是第几个 "星期c"

                for (int k = 1; k <= len; k++)
                {
                    if (week1 == c) // 星期c
                    {
                        if (++sum == b) // 第b个星期
                            flag = true, printf("%04d/%02d/%02d\n", i, j, k);
                    } // 格式化输出：自动补全前导零
                    week1 = week1 % 7 + 1;
                }
                if (!flag)
                    cout << "none" << endl;
            }
        }
        week = (week + 365 + Leap(i) - 1) % 7 + 1; // 更新下一年1月1日是星期几
    }
    return 0;
}