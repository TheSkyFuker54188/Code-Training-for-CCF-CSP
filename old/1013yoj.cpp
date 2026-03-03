#include <cstdio>
#include <vector>

using namespace std;

// 树状数组类
class FenwickTree
{
private:
    vector<long long> tree;
    int n;

public:
    FenwickTree(int size) : n(size)
    {
        tree.resize(n + 1, 0);
    }

    // 单点更新：将 idx 位置加上 delta
    void update(int idx, long long delta)
    {
        while (idx <= n)
        {
            tree[idx] += delta;
            idx += idx & -idx; // 低位掩码
        }
    }

    // 前缀和查询：查询 [1, idx] 的区间和
    long long query(int idx)
    {
        long long sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    // 区间和查询：[l, r] 的区间和
    long long rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    // 初始化数列和树状数组
    vector<int> a(n + 1);
    FenwickTree fenwick(n);

    // 读取初始数列并建立树状数组
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        fenwick.update(i, a[i]); // 将 a[i] 加入树状数组
    }

    // 处理操作
    for (int i = 0; i < q; ++i)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int idx, x;
            scanf("%d %d", &idx, &x);
            fenwick.update(idx, x); // 单点更新
        }
        else if (type == 2)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", fenwick.rangeQuery(l, r)); // 区间和查询
        }
    }

    return 0;
}
