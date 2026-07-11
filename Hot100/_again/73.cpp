#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    bool col_0 = false;
    bool row_0 = false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;

            if (x == 0)
            {
                if (i == 0)
                {
                    row_0 = true;
                }
                if (j == 0)
                {
                    col_0 = true;
                }
                else
                {
                    a[0][j] = 0;
                    a[i][0] = 0;
                }
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (a[i][0] == 0)
        {
            for (int j = 1; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (a[0][i] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                a[j][i] = 0;
            }
        }
    }

    if (col_0)
        for (int i = 0; i < m; i++)
            a[i][0] = 0;
    if (row_0)
        for (int i = 0; i < n; i++)
            a[0][i] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}