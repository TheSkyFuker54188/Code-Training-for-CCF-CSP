// 2015年03月 第A题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int N = 1 + 1000;
const int M = 1 + 1000;

int n, m;

int a[N][M];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}