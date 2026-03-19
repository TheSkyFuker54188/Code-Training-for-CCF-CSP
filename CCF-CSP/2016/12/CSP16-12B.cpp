// 2016年12月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <algorithm>

using namespace std;

int t;

int main()
{
    cin >> t;
    for (int s = 100; s < 10000000; s += 100)
    {
        if (s < 3500)
        {
            if (s == t)
            {
                cout << s;
                break;
            }
            else
                continue;
        }
        else
        {
            int tax = 0;
            int a = s - 3500;

            tax += min(1500, (a)) * 0.03;
            if (a > 1500)
                tax += min(4500 - 1500, (a - 1500)) * 0.1;
            if (a > 4500)
                tax += min(9000 - 4500, (a - 4500)) * 0.2;
            if (a > 9000)
                tax += min(35000 - 9000, (a - 9000)) * 0.25;
            if (a > 35000)
                tax += min(55000 - 35000, (a - 35000)) * 0.3;
            if (a > 55000)
                tax += min(80000 - 55000, (a - 55000)) * 0.35;
            if (a > 80000)
                tax += (a - 80000) * 0.45;

            if (s - tax == t)
            {
                cout << s << endl;
                break;
            }
        }
    }
}