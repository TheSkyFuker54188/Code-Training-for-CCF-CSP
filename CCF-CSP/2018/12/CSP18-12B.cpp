// 2018-12-B 小明放学
#include <iostream>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    long long tik = 0;
    int r, y, g;
    int n;

    cin >> r >> y >> g;
    cin >> n;

    int round = r + y + g;
    for (int i = 0; i < n; i++)
    {
        int k, t;
        cin >> k >> t;

        if (k == 0)
            tik += t;
        else
        {
            long long now;
            if (k == 1)
            {
                now = ((r - t) + tik) % round;
            }
            if (k == 3)
            {
                now = (((g - t) + r) + tik) % round;
            }
            if (k == 2)
            {
                now = (((y - t) + g + r) + tik) % round;
            }

            if (now < r)
            {
                tik += r - now;
            }
            else if (now < r + g)
            {
                ;
            }
            else if (now < r + g + y)
            {
                tik += (y - (now - r - g)) + r;
            }
        }
    }
    cout << tik;
}

/* 
极小样例：n=1，分别测 k=0/1/2/3。
边界样例：t=1、t=r/y/g、r=y=g=1。
极限样例：n=1e5，大量道路段 k=0,t=1e6（专门测溢出）。
 */