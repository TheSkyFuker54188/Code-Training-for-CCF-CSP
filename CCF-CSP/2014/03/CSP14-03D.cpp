// 2014年03月 第D题
// 算法 + 数据结构）

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1 + 100 + 100 + 5;

struct Point
{
    long long x, y;
    bool is_extra;
};

struct Node
{
    int id;   // 当前节点编号
    int cnt;  // 已使用的增设路由器数量
    int dist; // 当前路径的总步数
};

Point point[MAX];
bool visited[MAX][MAX];
//            ID  增数
//*      （ID去重  增数防超）

int main()
{
    int n, m, k;
    long long r;
    if (!(cin >> n >> m >> k >> r))
        return 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> point[i].x >> point[i].y;
        point[i].is_extra = false;
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        cin >> point[i].x >> point[i].y;
        point[i].is_extra = true;
    }

    queue<Node> q;
    q.push({1, 0, -1});
    visited[1][0] = true;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();

        if (curr.id == 2)
        {
            cout << curr.dist << endl;
            return 0;
        }

        for (int i = 1; i <= n + m; i++)
        {
            long long dx = point[curr.id].x - point[i].x;
            long long dy = point[curr.id].y - point[i].y;

            if (dx * dx + dy * dy <= r * r)
            {
                int next_id = i;
                int next_cnt = curr.cnt + point[i].is_extra;
                int next_dist = curr.dist + 1;
                if (next_cnt <= k && visited[next_id][next_cnt] != true)
                {
                    q.push({next_id,
                            next_cnt,
                            next_dist});
                    visited[next_id][next_cnt] = true;
                }
            }
        }
    }
    return 0;
}
