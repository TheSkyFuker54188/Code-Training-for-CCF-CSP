#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

typedef long long ll;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class KDTree
{
private:
    struct Node
    {
        Point point;
        Node *left, *right;
        Node(const Point &p) : point(p), left(nullptr), right(nullptr) {}
    };

    Node *root;

    // 计算两点间距离的平方
    ll distance2(const Point &a, const Point &b)
    {
        ll dx = (ll)a.x - b.x;
        ll dy = (ll)a.y - b.y;
        return dx * dx + dy * dy;
    }

    Node *buildTree(vector<Point> &points, int start, int end, int depth)
    {
        if (start > end)
            return nullptr;

        // 按照depth决定比较x还是y
        int axis = depth % 2;
        int mid = (start + end) / 2;

        // 选择合适的分割点
        nth_element(points.begin() + start, points.begin() + mid,
                    points.begin() + end + 1,
                    [axis](const Point &a, const Point &b)
                    {
                        return axis ? (a.y < b.y) : (a.x < b.x);
                    });

        Node *node = new Node(points[mid]);
        node->left = buildTree(points, start, mid - 1, depth + 1);
        node->right = buildTree(points, mid + 1, end, depth + 1);
        return node;
    }

    void searchNearest(Node *node, const Point &target, ll &best_dist, int depth)
    {
        if (!node)
            return;

        // 计算当前点到目标点的距离
        ll dist = distance2(node->point, target);
        best_dist = min(best_dist, dist);

        // 确定搜索方向
        int axis = depth % 2;
        ll delta = axis ? ((ll)target.y - node->point.y) : ((ll)target.x - node->point.x);
        Node *first = delta <= 0 ? node->left : node->right;
        Node *second = delta <= 0 ? node->right : node->left;

        // 递归搜索最可能的子树
        searchNearest(first, target, best_dist, depth + 1);

        // 如果另一个子树可能包含更近的点，则也要搜索
        if (delta * delta < best_dist)
        {
            searchNearest(second, target, best_dist, depth + 1);
        }
    }

public:
    KDTree() : root(nullptr) {}

    void build(vector<Point> &points)
    {
        root = buildTree(points, 0, points.size() - 1, 0);
    }

    ll findNearest(const Point &target)
    {
        ll best_dist = numeric_limits<ll>::max();
        searchNearest(root, target, best_dist, 0);
        return best_dist;
    }
};

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
    KDTree kdtree;
    kdtree.build(points);

    // 处理查询
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << kdtree.findNearest(Point(x, y)) << "\n";
    }

    return 0;
}