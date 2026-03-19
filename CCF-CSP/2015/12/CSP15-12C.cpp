// 2015年12月 第C题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
int m, n, q;

queue<pair<int, int>> que;
//          y ,  x
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

char grid[MAX][MAX];

inline bool in(int y, int x)
{
    if (x >= 0 && x < m && y >= 0 && y < n)
        return true;
    else
        return false;
}
inline bool legal(int y, int x)
{
    if (grid[y][x] != '+' && grid[y][x] != '-' && grid[y][x] != '|')
        return true;
    else
        return false;
}
inline bool been(int y, int x, char c)
{
    if (grid[y][x] == c)
        return true;
    else
        return false;
}
void line(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        for (int y = min(y1, y2); y <= max(y1, y2); y++)
        {
            if (grid[y][x1] == '-' || grid[y][x1] == '+')
                grid[y][x1] = '+';
            else
                grid[y][x1] = '|';
        }
    }
    else if (y1 == y2)
    {
        for (int x = min(x1, x2); x <= max(x1, x2); x++)
        {
            if (grid[y1][x] == '|' || grid[y1][x] == '+')
                grid[y1][x] = '+';
            else
                grid[y1][x] = '-';
        }
    }
    return;
}
void fill()
{
    while (!que.empty())
    {
        int dir;
        auto p = que.front();
        int y = p.first;
        int x = p.second;
        char c = grid[y][x];
        que.pop();
        for (dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (!in(ny, nx))
                continue;
            if (!legal(ny, nx))
                continue;
            if (been(ny, nx, c))
                continue;
            else
            {
                grid[ny][nx] = c;
                que.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> m >> n >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            grid[i][j] = '.';
    for (int i = 0; i < q; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 0)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            line(x1, y1, x2, y2);
        }
        else
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            grid[y][x] = c;
            que.push({y, x});
            fill(); //! 这 q 个操作按照数据给出的顺序依次执行，故每读到一次就得填充，不可等到全局再只用一次BFS
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}