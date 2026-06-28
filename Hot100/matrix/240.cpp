#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int target;
    cin >> target;

    int x = n - 1;
    int y = 0;
    while (x >= 0 && y < m)
    {
        if (a[y][x] < target)
        {
            // cout << a[y][x];
            y++;
        }
        else if (a[y][x] > target)
        {
            // cout << a[y][x];
            x--;
        }
        else if (a[y][x] == target)
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}