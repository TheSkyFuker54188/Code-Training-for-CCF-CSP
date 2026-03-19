// 2015年12月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 30;
int n, m;

int main()
{
    cin >> n >> m;
    int grid[n][m];
    bool eliminate[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            eliminate[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            int tmp1 = grid[i][j];
            int tmp2 = grid[i][j + 1];
            int tmp3 = grid[i][j + 2];
            if (tmp1 == tmp2 && tmp2 == tmp3)
            {
                eliminate[i][j] = true;
                eliminate[i][j + 1] = true;
                eliminate[i][j + 2] = true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            int tmp1 = grid[j][i];
            int tmp2 = grid[j + 1][i];
            int tmp3 = grid[j + 2][i];
            if (tmp1 == tmp2 && tmp2 == tmp3)
            {
                eliminate[j][i] = true;
                eliminate[j + 1][i] = true;
                eliminate[j + 2][i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (eliminate[i][j] != true)
            {
                cout << grid[i][j];
            }
            else
            {
                cout << 0;
            }
            if (j != m - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
    return 0;
}