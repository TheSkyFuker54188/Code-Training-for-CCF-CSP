#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 1000 + 5;

int n, m, k, d;
bool blocked[MAXN][MAXN];
int demand[MAXN][MAXN];
int dista[MAXN][MAXN];
bool is_store[MAXN][MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_grid(int y, int x)
{
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> d;

    queue<pair<int, int>> q;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            dista[y][x] = -1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        is_store[y][x] = true;
    }

    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        demand[y][x] += c;
    }

    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        blocked[y][x] = true;
    }

    // Multi-source BFS: all stores are distance 0 at the same time.
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (is_store[y][x] && !blocked[y][x])
            {
                dista[y][x] = 0;
                q.push({y, x});
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (!in_grid(ny, nx))
                continue;
            if (blocked[ny][nx])
                continue;
            if (dista[ny][nx] != -1)
                continue;
            dista[ny][nx] = dista[y][x] + 1;
            q.push({ny, nx});
        }
    }

    long long ans = 0;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (demand[y][x] == 0)
                continue;
            ans += 1LL * demand[y][x] * dista[y][x];
        }
    }

    cout << ans;
    return 0;
}