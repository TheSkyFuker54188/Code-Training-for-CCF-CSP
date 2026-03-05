#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    long long x, y;
    bool is_extra;
};

struct Node
{
    int id;
    int cnt;
    int dist;
};

Point points[205];
bool visited[205][205];

int main()
{
    int n, m, k;
    long long r;
    if (!(cin >> n >> m >> k >> r))
        return 0;

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].is_extra = false;
    }
    for (int i = n; i < n + m; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].is_extra = true;
    }

    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();

        if (curr.id == 1)
        {
            cout << curr.dist - 1 << endl;
            return 0;
        }

        for (int i = 0; i < n + m; i++)
        {
            long long dx = points[curr.id].x - points[i].x;
            long long dy = points[curr.id].y - points[i].y;
            if (dx * dx + dy * dy <= r * r)
            {
                int next_cnt = curr.cnt + (points[i].is_extra ? 1 : 0);
                if (next_cnt <= k && !visited[i][next_cnt])
                {
                    visited[i][next_cnt] = true;
                    q.push({i, next_cnt, curr.dist + 1});
                }
            }
        }
    }
    return 0;
}
