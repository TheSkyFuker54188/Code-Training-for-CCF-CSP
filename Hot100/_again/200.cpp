#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<char>> a;
vector<vector<bool>> b;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int cnt = 0;

void dfs(int y, int x)
{
    b[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < m && nx >= 0 && nx < n && //! 注意边界
            a[ny][nx] == '1' && b[ny][nx] == false)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> m >> n;
    a.assign(m, vector<char>(n));
    b.assign(m, vector<bool>(n, false));

    string tem;
    for (int i = 0; i < m; i++)
    {
        cin >> tem;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = tem[j];
        }
    }

    /*     for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        } */

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '1' && b[i][j] == false)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}