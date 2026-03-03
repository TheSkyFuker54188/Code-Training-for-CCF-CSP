#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义二叉树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据给定的向量创建二叉树
TreeNode *buildTree(const vector<int> &values, int index)
{
    if (index >= values.size())
        return nullptr; // 如果索引超出范围，返回空
    TreeNode *root = new TreeNode(values[index]);
    root->left = buildTree(values, 2 * index + 1);  // 左子节点
    root->right = buildTree(values, 2 * index + 2); // 右子节点
    return root;
}

// 非递归前序遍历
void preorder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        result.push_back(node->val);
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

// 非递归中序遍历
void inorder(TreeNode *root, vector<int> &result)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
}

// 非递归后序遍历
void postorder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        result.push_back(s2.top()->val);
        s2.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // 构建二叉树
    TreeNode *root = buildTree(values, 0);

    // 遍历并输出结果
    vector<int> preResult, inResult, postResult;
    preorder(root, preResult);
    inorder(root, inResult);
    postorder(root, postResult);

    // 输出前序遍历结果
    for (int i = 0; i < preResult.size(); i++)
    {
        cout << preResult[i] << (i == preResult.size() - 1 ? "\n" : " ");
    }

    // 输出中序遍历结果
    for (int i = 0; i < inResult.size(); i++)
    {
        cout << inResult[i] << (i == inResult.size() - 1 ? "\n" : " ");
    }

    // 输出后序遍历结果
    for (int i = 0; i < postResult.size(); i++)
    {
        cout << postResult[i] << (i == postResult.size() - 1 ? "\n" : " ");
    }

    return 0;
}
