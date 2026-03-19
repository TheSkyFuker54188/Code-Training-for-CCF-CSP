// 2014年09月 第D题
// 算法 + 数据结构）

// todo 多次调用bfs函数导致超时，这道题值得好好反思
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1 + 1000;
const char type[4] = {' ', 's', 't', 'b'};
//                     0    1    2    3
struct point
{
    int x;
    int y;
    char t = type[0];
    // 客户专属属性
    int amount = 0;
    int min_time = MAX * MAX;
};

int n;
point grid[MAX][MAX];
point p_m[MAX * MAX];
int k_x[MAX * MAX];
int k_y[MAX * MAX];
bool been[MAX][MAX];

/*
x+(0)
y+(1)
x-(2)
y-(3)
*/
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in(int y, int x)
{
    if ((y > 0 && y <= n) && (x > 0 && x <= n))
        return true;
    else
        return false;
}
bool can(int y, int x, int dir)
{
    int new_y = y + dy[dir];
    int new_x = x + dx[dir];
    if (in(new_y, new_x) && grid[new_y][new_x].t != type[3])
        return true;
    else
        return false;
}
void bfs(int m_id)
{
    queue<pair<pair<int, int>, int>> q; //! 队列里每个元素都带着它自己的距离 dist

    int sx = p_m[m_id].x;
    int sy = p_m[m_id].y;
    been[sy][sx] = true;
    q.push({{sy, sx}, 0}); //! 队列里每个元素都带着它自己的距离 dist

    while (!empty(q))
    {
        auto p = q.front();
        int y = p.first.first;
        int x = p.first.second;
        int tik = p.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (!can(y, x, i))
                continue;

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (grid[ny][nx].t == type[3])
                continue;
            if (been[ny][nx])
                continue;

            been[ny][nx] = true;
            int ntik = tik + 1; //! 队列里每个元素都带着它自己的距离 dist
            q.push({{ny, nx}, ntik});

            if (grid[ny][nx].t == type[2])
            {
                if (ntik < grid[ny][nx].min_time)
                {
                    grid[ny][nx].min_time = ntik;
                }
            }
        }
    }
}

int main()
{
    int m, k, d;
    cin >> n >> m >> k >> d;

    int tmp_x, tmp_y;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp_x >> tmp_y;

        p_m[i].x = tmp_x;
        p_m[i].y = tmp_y;
        p_m[i].t = type[1];
        grid[tmp_y][tmp_x] = p_m[i];
    }
    for (int i = 0; i < k; i++)
    {
        int amt;
        cin >> tmp_x >> tmp_y >> amt;

        k_x[i] = tmp_x;
        k_y[i] = tmp_y;

        grid[tmp_y][tmp_x].x = tmp_x;
        grid[tmp_y][tmp_x].y = tmp_y;
        grid[tmp_y][tmp_x].t = type[2];
        grid[tmp_y][tmp_x].amount += amt;
    }
    for (int i = 0; i < d; i++)
    {
        cin >> tmp_x >> tmp_y;

        grid[tmp_y][tmp_x].x = tmp_x;
        grid[tmp_y][tmp_x].y = tmp_y;
        grid[tmp_y][tmp_x].t = type[3];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int l = 1; l <= n; l++)
            {
                been[j][l] = false;
            }
        }
        bfs(i);
    }

    long long cost = 0;
    for (int i = 0; i < k; i++)
    {
        int kx = k_x[i];
        int ky = k_y[i];
        cost += 1LL * grid[ky][kx].amount * grid[ky][kx].min_time;
        grid[ky][kx].amount = 0;
    }
    cout << cost;
}

// todo   ReView
/*

**先说结论**
1. 你的主要问题不是一个点，而是 BFS 实现里几个典型“连锁 bug”。
2. 我已经按最小改动修正这些点，保留“每个分店跑一遍 BFS”的框架。
3. 这版逻辑正确后，仍可能在满数据超时，因为复杂度本身偏高（后面会讲如何避免这类设计误区）。

**错误定位 + 原因 + 改法**
! 1. `in()` 少了 `return false`
- 位置：`CSP14-09D-.cpp:35`、`CSP14-09D-.cpp:40`
- 原因：`else false;` 只是表达式，不返回值，属于未定义行为。
- 改法：改成 `return false;`。

! 2. 障碍判断类型不一致
- 位置：`CSP14-09D-.cpp:46`
- 原因：你之前拿 `char t` 和整数 `3` 比，语义不稳定。
- 改法：统一写成 `grid[new_y][new_x].t != type[3]`。

! 6. `been` 的类型不匹配导致编译错误
- 位置：`CSP14-09D-.cpp:24`、`CSP14-09D-.cpp:142`
- 原因：局部 `bool been[n+1][n+1]` 是 VLA，传给 `bool been[MAX][MAX]` 不匹配。
- 改法：改成全局固定数组 `bool been[MAX][MAX]`，每次 BFS 前清零。

! 7. 总费用可能溢出 `int`
- 位置：`CSP14-09D-.cpp:145`、`CSP14-09D-.cpp:150`
- 原因：需求量和点数都大，乘法和累加可能超 32 位。
- 改法：`long long cost`，并用 `1LL * ...`。

? 3. BFS 里把当前坐标 `x,y` 直接累加，导致方向循环串值
- 位置：`CSP14-09D-.cpp:73`
- 原因：`x += dx[i]` / `y += dy[i]` 会影响下一方向，扩展错误。
- 改法：每次用临时变量 `nx, ny`：`nx = x + dx[i]`，`ny = y + dy[i]`。

? 4. 距离计算方式错（`tik++` 不是最短路层数）
- 位置：`CSP14-09D-.cpp:82`
- 原因：访问点数不等于路径长度，会把 `min_time` 算错。
- 改法：队列里存 `(坐标, 当前距离)`，邻居距离 `ntik = tik + 1`。

? 5. 队列里压 `grid[y][x]` 会丢失空地坐标
- 位置：`CSP14-09D-.cpp:53`
- 原因：很多普通格点的 `grid[..].x/y` 没初始化，出队后坐标可能错。
- 改法：队列改成坐标队列（我用了 `queue<pair<pair<int,int>,int>>`）。

**核心直觉**
这三点本质上都在说一件事:
? `BFS` 里“队列中的每个元素”必须完整描述一个独立状态。
? 这个状态至少要有:
? 1. 当前位置 `(y, x)`
? 2. 到起点的距离 `dist`
! 你原来是把这两件事分散在外部变量里，导致互相污染或丢失。

**第 3 点: 为什么不能 `x += dx[i]`, `y += dy[i]`**
参考 `bfs` 在 `CSP14-09D-.cpp:51`。

如果你在 4 个方向循环里直接改 `x,y`，后一个方向会基于“已经改过的坐标”继续算。

举个小例子，当前点 `(5,5)`:
1. `i=0` 向右后，`x,y` 变成 `(6,5)`
2. `i=1` 本来想算“从原点向下”应是 `(5,6)`，但你会算成从 `(6,5)` 向下得到 `(6,6)`

这就不是“同一个父节点扩展 4 个邻居”，而是“走折线”了。
所以必须写成:
- `int nx = x + dx[i];`
- `int ny = y + dy[i];`

原点 `x,y` 保持不变，每个方向独立计算。

? **第 4 点: 为什么 `tik++` 不是最短路距离**
! `tik++` 统计的是“你处理过多少个节点”，不是“当前节点离起点几步”。

BFS 的正确距离规则是:
1. 起点距离 `0`
2. 邻居距离 = 当前点距离 `+1`

所以你现在写法里:
- 出队拿到 `tik`（当前距离）
- 扩展邻居得到 `ntik = tik + 1`
- 邻居入队时把 `ntik` 一起存起来

这样到任何点的第一次到达距离就是最短路（BFS 性质）。

**第 5 点: 为什么 `q.push(grid[y][x])` 有风险**
`grid[y][x]` 是一个 `point` 对象，但很多普通空地你从没给它赋过 `.x/.y`。
默认值可能是 `0`，那出队后坐标就错了，后续扩展全乱。

所以队列里不应依赖 `grid` 对象存坐标，应该直接存“真实坐标”。

你现在改成坐标队列后，这个问题就消失了。

**`queue<pair<pair<int,int>,int>>` 到底是什么**
它是“一个队列，元素长这样”:

- `pair<int,int>`: 坐标 `(y, x)`
- 外层再配一个 `int`: 距离 `dist`

等价语义:
- `((y, x), dist)`

你代码里这几行正好对应这个结构:
- `q.push({{sy, sx}, 0});`
- `int y = p.first.first;`
- `int x = p.first.second;`
- `int tik = p.second;`

如果你觉得这个类型太绕，可以换成结构体，更好读:

```cpp
struct Node {
    int y, x, dist;
};
queue<Node> q;
```


todo **你问的第 2 点：如何避免复杂题写崩**
给你一套我建议你固定执行的流程，能显著减少“设计歪 + 调试地狱”。

? 1. 先写“状态定义”，再写代码
- 明确：队列里放什么（坐标/距离/状态），`visited` 含义，`dist` 含义。
- 一旦定义清楚，很多 bug（比如 `tik++`）会直接被排除。

? 2. 优先选择“能全局一次求解”的模型
- 本题目标是“每个点到最近分店距离”，天然是多源 BFS 一次完成。
- 你这版多次 BFS 可修对，但复杂度风险高。先想“目标是最近源点还是指定源点”。

? 3. 写 BFS 时固定模板，不要临场改
- 模板关键不变：
  - 出队 `y,x,dist`
  - 四方向只用 `ny,nx`
  - 判边界/障碍/访问
  - 入队时就标记访问
- 你可以自己存一个“金模板 cpp 文件”，以后直接贴。

? 4. 每写完一层逻辑就做“小断言”
- 例如：
  - `in()` 专门测 4 个边界点
  - 单个分店单个客户，距离应为曼哈顿（无障碍时）
  - 有障碍时手画 5x5 小图验证

? 5. 调试时先“可视化关键数组”再上 gdb
- 这类题 gdb 单步很痛苦，优先打印：
  - 某次 BFS 的前 20 次出队 `(y,x,dist)`
  - 关键客户点 `min_time` 是否被更新
- 先把“数据流”看通，再定位具体语句。

? 6. 最后做复杂度体检（强制步骤）
- 估一下 `n=1000` 时循环次数。
- 如果超过 `1e8` 级别且常数不小，基本就该换思路了。
 */