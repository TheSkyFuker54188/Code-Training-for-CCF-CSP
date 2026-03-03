#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    // 插入节点的递归实现
    Node *insertRec(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }

        if (val < node->val)
        {
            node->left = insertRec(node->left, val);
        }
        else if (val > node->val)
        {
            node->right = insertRec(node->right, val);
        }

        return node;
    }

    // 查找最小值节点
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // 删除节点的递归实现
    Node *deleteRec(Node *node, int val)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (val < node->val)
        {
            node->left = deleteRec(node->left, val);
        }
        else if (val > node->val)
        {
            node->right = deleteRec(node->right, val);
        }
        else
        {
            // 找到要删除的节点

            // 情况1：叶子节点
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            // 情况2：只有一个子节点
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // 情况3：有两个子节点
            else
            {
                Node *temp = findMin(node->right);               // 找到右子树中最小的节点
                node->val = temp->val;                           // 用右子树中最小的节点值替换当前节点
                node->right = deleteRec(node->right, temp->val); // 删除右子树中的最小节点
            }
        }
        return node;
    }

    // 先序遍历的递归实现
    void preorderRec(Node *node, int &count)
    {
        if (node != nullptr)
        {
            cout << node->val;
            count++;
            cout << " ";
            preorderRec(node->left, count);
            preorderRec(node->right, count);
        }
    }

public:
    BST() : root(nullptr) {}

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

    BST tree;

    for (int i = 0; i < n; i++)
    {
        int op, val;
        cin >> op >> val;

        if (op == 1)
        {
            tree.insert(val);
        }
        else
        {
            tree.remove(val);
        }
    }

    tree.preorder();

    return 0;
}