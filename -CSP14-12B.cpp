#include <iostream>

using namespace std;

const int MAX = 1 + 500;

int n;
int m[MAX][MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    cout << m[0][0];

    int x = 0, y = 0;
    while (x != n - 1 && y != n - 1)
    {
        x += 1;
        cout << " " << m[y][x];

        while (x != 0)
        {
            x -= 1;
            y += 1;
            cout << " "<< m[y][x];
        }

        if (y != n - 1)
        {
            y += 1;
            cout << " "<< m[y][x];
        }

        while (y != 0)
        {
            x += 1;
            y -= 1;
            cout << " "<< m[y][x];
        }
    }
}