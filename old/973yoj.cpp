#include <iostream>
#include <vector>
#include <queue>

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

// 层次遍历
void levelOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
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

    // 层次遍历并输出结果
    vector<int> levelOrderResult;
    levelOrder(root, levelOrderResult);

    for (int i = 0; i < levelOrderResult.size(); i++)
    {
        cout << levelOrderResult[i] << (i == levelOrderResult.size() - 1 ? "\n" : " ");
    }

    return 0;
}
