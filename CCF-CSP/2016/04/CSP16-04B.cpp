// 2016年04月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

int g[15][10];
int a[4][4];
int l;

int g_high[10];
int a_low[4];
int dist[4];

int main()
{

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 10; j++)
            cin >> g[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];

    cin >> l;
    l--;

    for (int x = 0; x < 10; x++)
    {
        g_high[x] = 15; //! 默认为底部
        for (int y = 0; y < 15; y++)
        {
            if (g[y][x] == 1)
            {
                g_high[x] = y;
                break;
            }
        }
    }

    for (int x = 0; x < 4; x++)
    {
        a_low[x] = -1; //! 记为-1表示本列图案为空
        for (int y = 3; y >= 0; y--)
        {
            if (a[y][x] == 1)
            {
                a_low[x] = y;
                break;
            }
        }
    }

    int d = 999;
    for (int i = 0; i < 4; i++)
    {
        if (a_low[i] != -1) // 要考虑这一列有方块才算距离
        {
            //! 注意：板块第 i 列，应该去与地图的第 i + l 列对比
            // todo  距离 = (地图中最高的点) - (板块中最低点) - 1
            dist[i] = g_high[i + l] - a_low[i] - 1;
            if (dist[i] < d)
                d = dist[i];
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] == 1)
            {
                // 用下落距离 d 将 a 的原本位置偏移
                g[i + d][j + l] = 1;
            }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}