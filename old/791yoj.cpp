#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct KDNode
{
    Point point;
    int axis; // 0表示按x划分，1表示按y划分
    KDNode *left;
    KDNode *right;

    KDNode(const Point &p, int _axis) : point(p), axis(_axis), left(nullptr), right(nullptr) {}
};

// 计算两点间距离的平方
long long distanceSquared(const Point &p1, const Point &p2)
{
    long long dx = (long long)p1.x - p2.x;
    long long dy = (long long)p1.y - p2.y;
    return dx * dx + dy * dy;
}

// 按照指定轴进行比较的函数
bool compareX(const Point &a, const Point &b) { return a.x < b.x; }
bool compareY(const Point &a, const Point &b) { return a.y < b.y; }

// 构建KD树
KDNode *buildKDTree(vector<Point> &points, int start, int end, int depth)
{
    if (start >= end)
        return nullptr;

    int axis = depth % 2; // 交替使用x轴和y轴

    // 按当前轴排序
    if (axis == 0)
    {
        sort(points.begin() + start, points.begin() + end, compareX);
    }
    else
    {
        sort(points.begin() + start, points.begin() + end, compareY);
    }

    int mid = start + (end - start) / 2;
    KDNode *node = new KDNode(points[mid], axis);

    node->left = buildKDTree(points, start, mid, depth + 1);
    node->right = buildKDTree(points, mid + 1, end, depth + 1);

    return node;
}

// 在KD树中搜索最近点
void nearestNeighbor(KDNode *root, const Point &query, long long &bestDist)
{
    if (!root)
        return;

    // 计算当前点到查询点的距离
    long long dist = distanceSquared(root->point, query);

    // 更新最近距离
    if (dist < bestDist && dist > 0)
    { // dist > 0 确保不选择查询点本身(如果它在集合中)
        bestDist = dist;
    }

    // 决定先搜索哪个子树
    int axis = root->axis;
    KDNode *first, *second;
    long long axisDistance;

    if ((axis == 0 && query.x < root->point.x) ||
        (axis == 1 && query.y < root->point.y))
    {
        first = root->left;
        second = root->right;
    }
    else
    {
        first = root->right;
        second = root->left;
    }

    // 递归搜索更可能包含最近点的子树
    nearestNeighbor(first, query, bestDist);

    // 检查是否需要搜索另一个子树
    if (axis == 0)
    {
        axisDistance = (long long)(query.x - root->point.x) * (query.x - root->point.x);
    }
    else
    {
        axisDistance = (long long)(query.y - root->point.y) * (query.y - root->point.y);
    }

    if (axisDistance < bestDist)
    {
        nearestNeighbor(second, query, bestDist);
    }
}

// 释放KD树内存
void deleteKDTree(KDNode *node)
{
    if (!node)
        return;
    deleteKDTree(node->left);
    deleteKDTree(node->right);
    delete node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    // 构建KD树
    KDNode *root = buildKDTree(points, 0, n, 0);

    int q;
    cin >> q;
    while (q--)
    {
        Point query;
        cin >> query.x >> query.y;

        long long bestDist = LLONG_MAX;
        nearestNeighbor(root, query, bestDist);

        cout << bestDist << '\n';
    }

    // 清理内存
    deleteKDTree(root);

    return 0;
}
