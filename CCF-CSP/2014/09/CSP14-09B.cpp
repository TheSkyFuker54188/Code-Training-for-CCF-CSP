// 2014年09月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

int n;
int x1[100];
int y1[100];
int x2[100];
int y2[100];

int map[100][100];

int cnt;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1[i];
        cin >> y1[i];
        cin >> x2[i];
        cin >> y2[i];
    }

    for (int j = 0; j < n; j++)
    {
        for (int x = x1[j]; x < x2[j]; x++)
            for (int y = y1[j]; y < y2[j]; y++)
            {
                if (map[x][y] == 0)
                {
                    map[x][y] = 1;
                    cnt++;
                }
            }
    }
    cout << cnt;
}