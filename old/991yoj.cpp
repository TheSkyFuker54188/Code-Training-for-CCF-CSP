#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    int height;
    Node *left;
    Node *right;
    Node(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    void updateHeight(Node *node)
    {
        if (node)
        {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // 3+4重构
    Node *connect34(Node *a, Node *b, Node *c,
                    Node *T0, Node *T1, Node *T2, Node *T3)
    {
        a->left = T0;
        a->right = T1;
        c->left = T2;
        c->right = T3;
        b->left = a;
        b->right = c;

        updateHeight(a);
        updateHeight(c);
        updateHeight(b);

        return b;
    }

    // 重平衡操作
    Node *rebalance(Node *node)
    {
        if (!node)
            return nullptr;

        Node *a, *b, *c;
        Node *T0, *T1, *T2, *T3;

        if (getBalanceFactor(node) > 1)
        { // L
            if (getBalanceFactor(node->left) >= 0)
            { // LL
                a = node->left->left;
                b = node->left;
                c = node;
                T0 = a ? a->left : nullptr;
                T1 = a ? a->right : nullptr;
                T2 = b->right;
                T3 = c->right;
            }
            else
            { // LR
                a = node->left;
                b = node->left->right;
                c = node;
                T0 = a->left;
                T1 = b ? b->left : nullptr;
                T2 = b ? b->right : nullptr;
                T3 = c->right;
            }
        }
        else if (getBalanceFactor(node) < -1)
        { // R
            if (getBalanceFactor(node->right) <= 0)
            { // RR
                a = node;
                b = node->right;
                c = node->right->right;
                T0 = a->left;
                T1 = b->left;
                T2 = c ? c->left : nullptr;
                T3 = c ? c->right : nullptr;
            }
            else
            { // RL
                a = node;
                b = node->right->left;
                c = node->right;
                T0 = a->left;
                T1 = b ? b->left : nullptr;
                T2 = b ? b->right : nullptr;
                T3 = c->right;
            }
        }
        else
        {
            return node;
        }

        return connect34(a, b, c, T0, T1, T2, T3);
    }

    Node *insertRec(Node *node, int val)
    {
        if (!node)
            return new Node(val);

        if (val < node->val)
            node->left = insertRec(node->left, val);
        else if (val > node->val)
            node->right = insertRec(node->right, val);
        else
            return node;

        updateHeight(node);
        return rebalance(node);
    }

    Node *findMin(Node *node)
    {
        return node->left ? findMin(node->left) : node;
    }

    Node *deleteRec(Node *node, int val)
    {
        if (!node)
            return nullptr;

        if (val < node->val)
            node->left = deleteRec(node->left, val);
        else if (val > node->val)
            node->right = deleteRec(node->right, val);
        else
        {
            if (!node->left || !node->right)
            {
                Node *temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->val = temp->val;
                node->right = deleteRec(node->right, temp->val);
            }
        }

        if (!node)
            return nullptr;

        updateHeight(node);
        return rebalance(node);
    }

    void preorderRec(Node *node)
    {
        if (node)
        {
            cout << node->val;
            cout << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int val)
    {
        root = insertRec(root, val);
    }

    void remove(int val)
    {
        root = deleteRec(root, val);
    }

    void preorder()
    {
        preorderRec(root);
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    AVLTree tree;
    for (int i = 0; i < n; i++)
    {
        int op, val;
        cin >> op >> val;
        if (op == 1)
            tree.insert(val);
        else
            tree.remove(val);
    }

    tree.preorder();
    return 0;
}