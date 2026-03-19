// 2014年12月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1 + 500;

int n;
int m[MAX][MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    int cnt = 0;

    cout << m[0][0];
    m[0][0] = 0;
    cnt++;

    int x = 0, y = 0;

    while (cnt != n * n)
    {

        if (x != n - 1 && cnt != n * n)
        {
            x += 1;
            cout << " " << m[y][x];
            m[y][x] = 0;
            cnt++;
        }

        while (x != 0 && y != n - 1 && cnt != n * n)
        {
            if (m[y + 1][x - 1] != 0)
            {
                x -= 1;
                y += 1;
                cout << " " << m[y][x];
                m[y][x] = 0;
                cnt++;
            }
            else
                break;
        }

        if (y != n - 1 && cnt != n * n)
        {
            y += 1;
            cout << " " << m[y][x];
            m[y][x] = 0;
            cnt++;
        }

        while (y != 0 && x != n - 1 && cnt != n * n)
        {
            if (m[y - 1][x + 1] != 0)
            {
                x += 1;
                y -= 1;
                cout << " " << m[y][x];
                m[y][x] = 0;
                cnt++;
            }
            else
                break;
        }
    }
}