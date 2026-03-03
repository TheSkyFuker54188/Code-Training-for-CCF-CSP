#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 定义事件类型
struct Event
{
    int x;
    int type;   // 0 - 点事件，1 - 查询事件
    int y;      // 对于点事件的 y 坐标
    int y0, y1; // 对于查询事件的 y 范围
    int id;     // 查询的编号
    int coeff;  // 系数，查询事件时使用，+1 或 -1
};

// 树状数组
class BIT
{
public:
    BIT(int size) : n(size)
    {
        tree.assign(n + 1, 0);
    }
    void update(int idx, int val)
    {
        while (idx <= n)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    int query(int idx) const
    {
        int res = 0;
        while (idx > 0)
        {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int queryRange(int l, int r) const
    {
        return query(r) - query(l - 1);
    }

private:
    int n;
    vector<int> tree;
};

int main()
{
    // 读取点的数量
    int n;
    cin >> n;
    vector<Event> events;
    vector<int> ys; // 用于坐标压缩的 y 坐标
    // 读取所有点，并创建点事件
    for (int i = 0; i < n; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        events.push_back({xi, 0, yi, 0, 0, 0});
        ys.push_back(yi);
    }
    // 读取查询的数量
    int m;
    cin >> m;
    vector<int> ans(m, 0);
    for (int i = 0; i < m; ++i)
    {
        int x0, x1, y0, y1;
        cin >> x0 >> x1 >> y0 >> y1;
        // 在 x0-1 处添加系数为 -1 的查询事件
        events.push_back({x0 - 1, 1, 0, y0, y1, i, -1});
        // 在 x1 处添加系数为 +1 的查询事件
        events.push_back({x1, 1, 0, y0, y1, i, +1});
        ys.push_back(y0);
        ys.push_back(y1);
    }
    // 对 y 坐标进行压缩
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    map<int, int> yCompress;
    for (int i = 0; i < ys.size(); ++i)
    {
        yCompress[ys[i]] = i + 1; // 树状数组的索引从 1 开始
    }
    // 更新事件中的 y 坐标（压缩后的）
    for (auto &event : events)
    {
        if (event.type == 0)
        {
            event.y = yCompress[event.y];
        }
        else
        {
            event.y0 = yCompress[event.y0];
            event.y1 = yCompress[event.y1];
        }
    }
    // 按照 x 从小到大排序事件
    sort(events.begin(), events.end(), [](const Event &a, const Event &b)
         {
        if (a.x != b.x) return a.x < b.x;
        // 若 x 相同，点事件优先
        return a.type < b.type; });
    // 初始化树状数组
    BIT bit(ys.size());
    // 扫描处理事件
    for (const auto &event : events)
    {
        if (event.type == 0)
        {
            // 点事件，更新树状数组
            bit.update(event.y, 1);
        }
        else
        {
            // 查询事件，计算当前 y0 到 y1 范围内的点数
            int cnt = bit.queryRange(event.y0, event.y1);
            ans[event.id] += event.coeff * cnt;
        }
    }
    // 输出答案
    for (int i = 0; i < m; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}