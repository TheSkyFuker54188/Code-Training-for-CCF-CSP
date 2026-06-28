//? 原地哈希
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    bool ir = false;
    bool ic = false;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        if (a[0][i] == 0)
            ir = true;

    for (int i = 0; i < m; i++)
        if (a[i][0] == 0)
            ic = true;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
            
    if (ir)
        for (int i = 0; i < n; i++)
            a[0][i] = 0;
    if (ic)
        for (int i = 0; i < m; i++)
            a[i][0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}