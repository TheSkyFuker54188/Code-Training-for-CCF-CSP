//? BFS求最短路 + 多源最短路
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ans = 0;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m));
    queue<pair<int, int>> q;
    //           y,x
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                q.push({i, j});
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        int d = dist[y][x];
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx > -1 && nx < m && ny > -1 && ny < n //
                && a[ny][nx] == 1)
            {
                dist[ny][nx] = d + 1;
                if (dist[ny][nx] > ans)
                    ans = dist[ny][nx];
                a[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}