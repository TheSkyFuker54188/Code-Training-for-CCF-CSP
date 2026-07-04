#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n, target;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> target;

    int l = 0, r = m * n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int y = mid / n;
        int x = mid % n;

        if (a[y][x] == target)
        {
            cout << "true";
            return 0;
        }
        else if (a[y][x] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "false";
    return 0;
}