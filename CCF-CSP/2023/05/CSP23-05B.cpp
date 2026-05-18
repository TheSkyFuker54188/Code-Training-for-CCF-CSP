// 2023-05-B 矩阵运算
//! 无优化版
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    int Q[n][d], K[n][d], V[n][d];
    long long tmp[n][n];
    long long ans[n][d];
    int W[n];

    memset(Q, 0, sizeof(Q));
    memset(K, 0, sizeof(K));
    memset(V, 0, sizeof(V));
    memset(tmp, 0, sizeof(tmp));
    memset(ans, 0, sizeof(ans));
    memset(W, 0, sizeof(W));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // tmp[i][j];
            for (int k = 0; k < d; k++)
            {
                tmp[i][j] += Q[i][k] * K[j][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] *= W[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += tmp[i][k] * V[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}