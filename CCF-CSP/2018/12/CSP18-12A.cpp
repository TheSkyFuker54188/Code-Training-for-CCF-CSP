// 2018-12-A 小明上学
#include <iostream>

using namespace std;

const int MAX = 100 + 1;

int main()
{
    int tik = 0;

    int r, y, g;
    int n;
    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, t;
        cin >> k >> t;
        if (k == 0)
        {
            tik += t;
        }
        else if (k == 1)
        {
            tik += t;
        }
        else if (k == 2)
        {
            tik += t + r;
        }
        else if (k == 3)
        {
        }
    }

    cout << tik;
}