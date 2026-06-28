#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int i = 0, j = 0;

    cout << a[0][0] << " ";
    b[0][0] = 1;
    int cnt = 1;
    while (cnt < m * n)
    {
        while (j + 1 < n && b[i][j + 1] == 0)
        {
            j++;
            cout << a[i][j] << " ";
            b[i][j] = 1;
            cnt++;
        }
        while (i + 1 < m && b[i + 1][j] == 0)
        {
            i++;
            cout << a[i][j] << " ";
            b[i][j] = 1;
            cnt++;
        }
        while (j - 1 >= 0 && b[i][j - 1] == 0)
        {
            j--;
            cout << a[i][j] << " ";
            b[i][j] = 1;
            cnt++;
        }
        while (i - 1 >= 0 && b[i - 1][j] == 0)
        {
            i--;
            cout << a[i][j] << " ";
            b[i][j] = 1;
            cnt++;
        }
    }
}