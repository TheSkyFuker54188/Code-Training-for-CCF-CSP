// 2013年12月 第E题
// 算法 + 数据结构）

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50 + 5;

int R, C;
char grid[MAX][MAX];

const int dr[4] = {-1, 1, 0, 0};
//                上0  下1
const int dc[4] = {0, 0, -1, 1};
//                       左2 右3

bool in(int r, int c)
{
    if (r >= 0 && r < R && c >= 0 && c < C)
        return true;
    else
        return false;
}

bool yes(int r, int c, int dir)
{
    char ch = grid[r][c];
    if (ch == '+' || ch == 'S' || ch == 'T')
        return true;
    if (ch == '|')
        return dir == 0 || dir == 1;
    if (ch == '-')
        return dir == 2 || dir == 3;
    if (ch == '.')
        return dir == 1;
    return false;
}

void bfsS(int sr, int sc, bool been[MAX][MAX])
{
    queue<pair<int, int>> q;
    been[sr][sc] = true;

    q.push({sr, sc});
    while (!q.empty())
    {
        auto p = q.front();
        int r = p.first;
        int c = p.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            if (!yes(r, c, dir))
                continue;
            int new_r = r + dr[dir];
            int new_c = c + dc[dir];
            if (!in(new_r, new_c))
                continue;
            if (grid[new_r][new_c] == '#')
                continue;
            if (been[new_r][new_c])
                continue;
            else
            {
                been[new_r][new_c] = true;
                q.push({new_r, new_c});
            }
        }
    }
}

void bfsT(int tr, int tc, bool canT[MAX][MAX])
{
    queue<pair<int, int>> q;
    canT[tr][tc] = true;

    q.push({tr, tc});
    while (!q.empty())
    {
        auto p = q.front();
        int r = p.first;
        int c = p.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int pre_r = r - dr[dir];
            int pre_c = c - dc[dir];
            if (!yes(pre_r, pre_c, dir))
                continue;
            if (!in(pre_r, pre_c))
                continue;
            if (grid[pre_r][pre_c] == '#')
                continue;
            if (canT[pre_r][pre_c])
                continue;
            else
            {
                canT[pre_r][pre_c] = true;
                q.push({pre_r, pre_c});
            }
        }
    }
}

int main()
{
    int sr, sc, tr, tc;
    bool been[MAX][MAX];
    bool canT[MAX][MAX];

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            been[i][j] = false;
            canT[i][j] = false;

            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'T')
            {
                tr = i;
                tc = j;
            }
        }
    }
    bfsS(sr, sc, been);
    if (!been[tr][tc])
    {
        cout << "I'm stuck!" << endl;
        return 0;
    }
    bfsT(tr, tc, canT);

    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (been[i][j] && !canT[i][j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}