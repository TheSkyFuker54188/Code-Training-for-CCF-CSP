// 2023-03-A 田地丈量
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10000 + 1;

int main()
{
    //freopen("in.txt", "r", stdin);
    int s = 0;
    int n, a, b;
    cin >> n >> a >> b;

    bool e[b + 1][a + 1];
    memset(e, false, sizeof(e));

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 = min(y1, b);
        y2 = min(y2, b);
        x1 = min(x1, a);
        x2 = min(x2, a);

        y1 = max(y1, 0);
        y2 = max(y2, 0);
        x1 = max(x1, 0);
        x2 = max(x2, 0);

        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                if (e[y][x] == true)
                    s++;
                else
                {
                    e[y][x] = true;
                    s++;
                }
            }
        }
    }
    cout << s;
}