#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    // freopen("in.txt", "r", stdin);
    int m, n;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                cnt++;
            if (a[i][j] == 2)
                q.push({i, j});
        }
    }
    if (cnt == 0)
    {
        cout << 0;
        return 0;
    }

    int tik = 0;
    while (!q.empty())
    {
        int s = q.size();
        for (int j = 0; j < s; j++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && //
                    a[ny][nx] == 1)
                {
                    a[ny][nx] = 2;
                    cnt--;
                    q.push({ny, nx});
                }
            }
        }
        tik++;
    }

    if (cnt == 0)
        cout << tik - 1;
    else
        cout << -1;
}