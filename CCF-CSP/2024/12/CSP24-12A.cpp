// 2024-12-A 移动
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        string o;
        cin >> o;

        int p = 0;
        while (p != o.length())
        {
            if (o[p] == 'f')
            {
                if (y + 1 <= n)
                    y++;
            }
            else if (o[p] == 'b')
            {
                if (y - 1 >= 1)
                    y--;
            }
            else if (o[p] == 'l')
            {
                if (x - 1 >= 1)
                    x--;
            }
            else if (o[p] == 'r')
            {
                if (x + 1 <= n)
                    x++;
            }
            p++;
        }
        cout << x << " " << y << "\n";
    }
}