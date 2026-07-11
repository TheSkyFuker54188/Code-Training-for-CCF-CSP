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

    int i = 0;
    int j = n - 1;

    while (i <= m - 1 && j >= 0)
    {
        if (a[i][j] < t)
        {
            i++;
        }
        else if (a[i][j] > t)
        {
            j--;
        }
        else
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}