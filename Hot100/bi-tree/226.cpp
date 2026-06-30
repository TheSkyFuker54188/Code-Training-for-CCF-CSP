#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// 树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据层序遍历序列构建二叉树（已实现，直接使用）
TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int idx = 1;
    int n = nodes.size();

    while (!q.empty() && idx < n)
    {
        TreeNode *cur = q.front();
        q.pop();

        // 左子节点
        if (idx < n && nodes[idx] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[idx]));
            q.push(cur->left);
        }
        idx++;

        // 右子节点
        if (idx < n && nodes[idx] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[idx]));
            q.push(cur->right);
        }
        idx++;
    }
    return root;
}

// 层序遍历输出二叉树（已实现，直接使用）
void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << endl; // 空树输出空行
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    vector<string> result;

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        // 只记录真实节点的值，不记录 null
        result.push_back(to_string(cur->val));

        // 只有非空孩子才入队，避免无效循环
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }

    // 输出，末尾不会有多余空格
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;
}

// ========== 你需要完成的部分 ==========
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    invertTree(root->left);
    invertTree(root->right);

    TreeNode *tem = root->left;
    root->left = root->right;
    root->right = tem;

    return root;
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    if (line.empty())
    { // 空输入
        cout << endl;
        return 0;
    }

    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建树 → 翻转 → 输出
    TreeNode *root = buildTree(nodes);
    root = invertTree(root);
    printTree(root);

    return 0;
}