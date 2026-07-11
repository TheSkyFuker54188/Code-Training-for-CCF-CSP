#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int t;
    cin >> t;

    int y = 0;
    int x = n - 1;

    while (y < m && x >= 0)
    {
        if (a[y][x] < t)
            y++;
        else if (a[y][x] > t)
            x--;
        else
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}