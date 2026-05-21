// 2024-06-B 矩阵重塑（其二）
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m, t;
    cin >> n >> m >> t;
    pair<int, int> A[m * n];
    //   idx, val

    int row = n, col = m;
    bool trans = false; // transpose

    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i * m + j].first = tmp;
            cin >> A[i * m + j].second;
            tmp++;
        }
    }

    for (int i = 0; i < t; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) // 重塑
        {
            row = a;
            col = b;
        }
        else if (op == 2) // 转置
        {
            int ptr = 0;
            while (ptr != m * n)
            {
                int idx_pre = A[ptr].first;
                int idx_i = idx_pre / col;
                int idx_j = idx_pre % col;
                int idx_pos = idx_j * row + idx_i;
                A[ptr].first = idx_pos;
                ptr++;
            }
            int temp = row;
            row = col;
            col = temp;
        }
        else if (op == 3) // 查询
        {
            int number = a * col + b;
            for (int i = 0; i < m * n; i++)
            {
                if (A[i].first == number)
                {
                    cout << A[i].second << "\n";
                    break;
                }
            }
        }
    }
}