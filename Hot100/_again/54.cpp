#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n, false));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int y = 0, x = 0;
    int cnt = 1;
    cout << a[0][0] << " ";
    b[0][0] = true;
    while (cnt != m * n)
    {
        while (x < n - 1 && b[y][x + 1] != true)
        {
            cout << a[y][++x] << " ";
            b[y][x] = true;
            cnt++;
        }
        //cout << '\n';
        while (y < m - 1 && b[y + 1][x] != true)
        {
            cout << a[++y][x] << " ";
            b[y][x] = true;
            cnt++;
        }
        //cout << '\n';
        while (x > 0 && b[y][x - 1] != true)
        {
            cout << a[y][--x] << " ";
            b[y][x] = true;
            cnt++;
        }
        //cout << '\n';
        while (y > 0 && b[y - 1][x] != true)
        {
            cout << a[--y][x] << " ";
            b[y][x] = true;
            cnt++;
        }
        //cout << '\n';
    }
}