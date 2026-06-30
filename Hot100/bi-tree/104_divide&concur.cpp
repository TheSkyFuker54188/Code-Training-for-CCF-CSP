//? 自底向上的DFS
// todo 把问题“往上抛”, 递归函数有返回值，返回的就是这个子树的最大深度。
//? 让递归函数先去算子问题的解，最后将子问题合并
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

// ========== 你需要完成的部分 ==========
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDep = maxDepth(root->left);
    int rightDep = maxDepth(root->right);

    if (leftDep > rightDep)
        return leftDep + 1;
    else
        return rightDep + 1;
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
    cout << maxDepth(root) << endl;

    return 0;
}