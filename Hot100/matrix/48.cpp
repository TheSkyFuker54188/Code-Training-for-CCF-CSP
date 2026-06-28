#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}