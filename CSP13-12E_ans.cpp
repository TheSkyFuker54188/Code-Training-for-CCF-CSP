// CCF-CSP 2013-12 第3题（原名：地图）
// 思路：
//   Step 1. 正向 BFS：从 S 出发，标记所有"从 S 可达"的格子。
//   Step 2. 反向 BFS：从 T 出发，沿着边方向反向传播，
//           标记所有"能到达 T"的格子。
//   Step 3. 统计"从 S 可达 && 不能到达 T"的格子数。
//   特判：若 S 本身就不能到 T，输出 I'm stuck!
//
// 关键思想：反向 BFS 避免了对每个可达点分别做 BFS，大幅提升效率和代码简洁性。

#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 55;

int R, C;
char grid[MAXN][MAXN];

// 四个方向：上、下、左、右（索引 0-3）
const int DR[] = {-1, 1, 0, 0};
const int DC[] = {0, 0, -1, 1};

// 判断坐标是否在地图内
bool inBounds(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C;
}

// 判断站在 (r, c) 时，能否向 dir 方向迈出一步
// dir: 0=上, 1=下, 2=左, 3=右
bool canLeave(int r, int c, int dir)
{
    char ch = grid[r][c];
    if (ch == '+' || ch == 'S' || ch == 'T')
        return true; // 四向自由
    if (ch == '-')
        return dir == 2 || dir == 3; // 仅左右
    if (ch == '|')
        return dir == 0 || dir == 1; // 仅上下
    if (ch == '.')
        return dir == 1; // 仅向下
    return false;        // '#'
}

// BFS：从 (sr, sc) 出发，用正向规则，标记所有可达格子到 visited
void bfsForward(int sr, int sc, bool visited[MAXN][MAXN])
{
    queue<pair<int, int>> q;
    visited[sr][sc] = true;
    q.push({sr, sc});
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            if (!canLeave(r, c, dir))
                continue;
            int nr = r + DR[dir], nc = c + DC[dir];
            if (!inBounds(nr, nc))
                continue;
            if (grid[nr][nc] == '#')
                continue;
            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

// 反向 BFS：从 (tr, tc) 出发，沿边方向"倒退"传播，
// 标记所有"存在路径通往 T"的格子到 canReachT
// 反向逻辑：若 A 能离开朝 dir 方向，且 A 的那个邻居已知"能到 T"，
//           则 A 也"能到 T"。反向搜索就是：对已知能到 T 的格子，
//           枚举哪些格子可以"迈出 dir 方向"恰好到达它。
void bfsReverse(int tr, int tc, bool canReachT[MAXN][MAXN])
{
    queue<pair<int, int>> q;
    canReachT[tr][tc] = true;
    q.push({tr, tc});
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        // 枚举四个方向，找出"能走进 (r,c)"的前驱格子
        for (int dir = 0; dir < 4; dir++)
        {
            // 前驱在 (r,c) 的反方向邻格
            int pr = r - DR[dir], pc = c - DC[dir];
            if (!inBounds(pr, pc))
                continue;
            if (grid[pr][pc] == '#')
                continue;
            // 前驱必须能朝 dir 方向走（即能走进 (r,c)）
            if (!canLeave(pr, pc, dir))
                continue;
            if (!canReachT[pr][pc])
            {
                canReachT[pr][pc] = true;
                q.push({pr, pc});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    int sr = -1, sc = -1, tr = -1, tc = -1;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
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

    // Step 1：正向 BFS，找出所有从 S 可达的格子
    bool fromS[MAXN][MAXN] = {};
    bfsForward(sr, sc, fromS);

    // 特判：S 自身都无法到达 T
    if (!fromS[tr][tc])
    {
        cout << "I'm stuck!" << endl;
        return 0;
    }

    // Step 2：反向 BFS，找出所有能到达 T 的格子
    bool canReachT[MAXN][MAXN] = {};
    bfsReverse(tr, tc, canReachT);

    // Step 3：统计"从 S 可达 && 不能到达 T"的格子
    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (fromS[i][j] && !canReachT[i][j])
                ans++;

    cout << ans << endl;
    return 0;
}