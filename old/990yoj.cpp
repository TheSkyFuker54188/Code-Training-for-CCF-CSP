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

    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node *node)
    {
        if (node)
        {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
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

        int balance = getBalanceFactor(node);

        // 左左情况
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && val > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && val < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
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
                if (!temp)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
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

        int balance = getBalanceFactor(node);

        // 左左情况
        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preorderRec(Node *node, int &count)
    {
        if (node)
        {
            cout << node->val;
            count++;
            cout << " ";
            preorderRec(node->left, count);
            preorderRec(node->right, count);
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
        int count = 0;
        preorderRec(root, count);
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