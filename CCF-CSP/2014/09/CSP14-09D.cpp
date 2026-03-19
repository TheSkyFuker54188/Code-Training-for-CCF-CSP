// 2014年09月 第D题
// 算法 + 数据结构）

// 【核心思路：多源 BFS (Multi-source BFS)】
// 题意求：所有客户到达【任意一个最近分店】的距离 * 订餐量 的总和。
//! 常规思路：对每个分店跑一次 BFS（O(m * n^2)），分店多时必超时。
// todo 优化思路：我们不需要知道客户具体离“哪一个”分店近，只需要知道“最近距离”。
// todo 因此，可以在起步时，把【所有分店】同时放入队列，距离设为 0。
//  这样就像是所有的分店同时向外辐射扩散（像丢了多颗石子进水池激起的涟漪），
//  任何一个格子第一次被访问到时，就是它离所有分店中最近的一个分店的最短距离。
//  这样全图只需完整跑一次 BFS，总时间复杂度降为 O(n^2)。

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 1000 + 5;

//! 建一个强大的 struct Point
// todo 好习惯：把每个格子的不同属性平铺成独立的二维数组
//  设计状态时，将不同的属性用独立的二维数组分开存储，逻辑清晰，不容易串车
int n, m, k, d;
bool blocked[MAXN][MAXN];  // 障碍物地图
int demand[MAXN][MAXN];    // 资源地图（存这里累加的需求量）
int dista[MAXN][MAXN];     // 距离状态图（兼具 visited 的作用，如果是 -1 则没访问过； >=0 则访问过了，存着最短距离）
bool is_store[MAXN][MAXN]; // 发源地地图

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

    // BFS 核心队列：存入坐标 (y, x)。因为我们有全局的 dista 数组记距离，所以不用再用 pair 存距离了
    queue<pair<int, int>> q;

    // 1. 初始化距离数组为 -1，代表尚未被 BFS 遍历到
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            dista[y][x] = -1;
        }
    }

    // 2. 读入分店位置（作为 BFS 的发源地）
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        is_store[y][x] = true;
    }

    // 3. 读入客户位置和需求量并【累加】（同一个点可能有多个不同客户）
    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        demand[y][x] += c;
    }

    // 4. 读入不能经过的障碍物点
    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        blocked[y][x] = true;
    }

    // 5. 【多源 BFS 点火】：将所有合法的分店作为源点同时入队
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (is_store[y][x] && !blocked[y][x])
            {
                dista[y][x] = 0; // 分店到自身的距离为 0
                q.push({y, x});
            }
        }
    }

    // 6. 执行 BFS 过程
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        // 向 4 个方向扩展
        for (int dir = 0; dir < 4; dir++)
        {
            //! 注意：一定要用局部变量 ny, nx，不要污染现有的 y, x
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 剪枝 1：判断越界
            if (!in_grid(ny, nx))
                continue;
            // 剪枝 2：判断是否为障碍物
            if (blocked[ny][nx])
                continue;
            // 剪枝 3：如果 dista != -1，说明这个点之前已经被搜索过了，这就是由于 BFS 的性质，
            //? 第一次到达该点的一定是最短距离，后续再到这肯定更远，直接跳过
            if (dista[ny][nx] != -1)
                continue;

            // 核心状态转移：邻居点的最短距离 = 父亲点的距离 + 1
            dista[ny][nx] = dista[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // 7. 统计最终结果
    long long ans = 0; // 金钱和距离相乘，容易超出 int 范围，必须定为 long long
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (demand[y][x] == 0) // 没有客户的地方不需要算总花费
                continue;

            // 花费 = 该点的总订餐量 * 到最近分店的最短距离
            // 乘以 1LL 是为了在计算时强制转换成 long long 运算，防止溢出
            ans += 1LL * demand[y][x] * dista[y][x];
        }
    }

    cout << ans;
    return 0;
}