// 2020-9-B 风险人群筛查
#include <iostream>
// #include <algorithm>

using namespace std;

int main()
{
    int n, k, t, xl, yd, xr, yu;
    int pass = 0, stay = 0;

    cin >> n >> k >> t >> xl >> yd >> xr >> yu;

    for (int i = 0; i < n; i++)
    {
        bool a[t];

        for (int j = 0; j < t; j++)
        {
            a[j] = false;
            int x, y;
            cin >> x >> y;
            if (x >= xl && x <= xr &&
                y >= yd && y <= yu)
                a[j] = true;
        }

        int streak = 0;
        int cnt = 0;
        for (int j = 0; j < t; j++)
        {
            if (a[j] == true)
            {
                streak++;
                if (streak > cnt)
                    cnt = streak;
            }
            else
            {
                streak = 0;
            }
        }
        if (cnt >= k)
        {
            pass++;
            stay++;
        }
        else if (cnt > 0)
        {
            pass++;
        }
    }

    cout << pass << endl
         << stay;
}