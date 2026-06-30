//? 自顶向下的DFS
//todo 把答案“往下带”, 在叶子节点“收割”答案
//? 无需定义递归函数的返回值，使用全局变量记录答案。但是需要在递归函数中记录当前搜寻的状态
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

int ans = 0;

// ========== 你需要完成的部分 ==========
void maxDepth(TreeNode *root, int depth)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (depth > ans)
            ans = depth;
        return;
    }
    maxDepth(root->left, depth + 1);
    maxDepth(root->right, depth + 1);
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建树，计算深度，输出结果
    TreeNode *root = buildTree(nodes);
    maxDepth(root,1);
    cout << ans << endl;

    return 0;
}