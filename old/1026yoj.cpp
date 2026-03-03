#include <iostream>
using namespace std;

const int MAXN = 100005;
typedef long long ll;

struct Node
{
    ll sum;  // 区间和
    ll lazy; // 懒标记
} tree[MAXN * 4];

int n, m;
ll arr[MAXN];

// 向上更新区间和
void pushup(int node)
{
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

// 构建线段树
void build(int node, int start, int end)
{
    tree[node].lazy = 0;
    if (start == end)
    {
        tree[node].sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    pushup(node);
}

// 下传懒标记
void pushdown(int node, int start, int end)
{
    if (tree[node].lazy != 0)
    {
        int mid = (start + end) / 2;
        // 左子节点
        tree[node * 2].sum += tree[node].lazy * (mid - start + 1);
        tree[node * 2].lazy += tree[node].lazy;
        // 右子节点
        tree[node * 2 + 1].sum += tree[node].lazy * (end - mid);
        tree[node * 2 + 1].lazy += tree[node].lazy;
        // 清除当前节点的懒标记
        tree[node].lazy = 0;
    }
}

// 区间修改
void update(int node, int start, int end, int l, int r, ll val)
{
    if (l <= start && end <= r)
    {
        tree[node].sum += val * (end - start + 1);
        tree[node].lazy += val;
        return;
    }
    pushdown(node, start, end);
    int mid = (start + end) / 2;
    if (l <= mid)
        update(node * 2, start, mid, l, r, val);
    if (r > mid)
        update(node * 2 + 1, mid + 1, end, l, r, val);
    pushup(node);
}

// 区间查询
ll query(int node, int start, int end, int l, int r)
{
    if (l <= start && end <= r)
    {
        return tree[node].sum;
    }
    pushdown(node, start, end);
    int mid = (start + end) / 2;
    ll sum = 0;
    if (l <= mid)
        sum += query(node * 2, start, mid, l, r);
    if (r > mid)
        sum += query(node * 2 + 1, mid + 1, end, l, r);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            ll k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}