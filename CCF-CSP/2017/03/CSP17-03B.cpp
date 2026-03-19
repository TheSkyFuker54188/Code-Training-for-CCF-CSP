// 2017年03月 第B题
// 算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000;

int n;
int m;
int opt[MAX];
int Q[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        Q[i] = i + 1;
    cin >> m;
    for (int t = 0; t < m; t++)
    {
        int p;
        int q;
        cin >> p >> q;
        for (int i = 0; i < n; i++)
            if (Q[i] == p)
            {
                int tmp = Q[i];
                int ins = i + q;
                int vac = i;
                // cout << "ins:" << ins << " vac:" << vac << endl;
                if (q > 0)
                {
                    for (int j = vac; j < ins; j++)
                        Q[j] = Q[j + 1];
                    Q[ins] = tmp;
                }
                else if (q < 0)
                {
                    for (int j = vac; j > ins; j--)
                        Q[j] = Q[j - 1];
                    Q[ins] = tmp;
                }
                break;
            }
    }
    for (int i = 0; i < n; i++)
    {
        cout << Q[i] << " ";
    }
}