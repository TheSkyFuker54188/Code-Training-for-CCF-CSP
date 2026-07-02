#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

// 二叉树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int ans = INT_MIN;
// 根据层序遍历序列构建二叉树
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

// ==================================================
// 你需要完成的部分：计算二叉树的最大路径和
// ==================================================
// 参数:
//   root: 二叉树的根节点
// 返回值: 最大路径和（路径至少包含一个节点，不一定经过根）
int maxPathSum(TreeNode *root)
{
    // TODO: 在这里实现你的算法
    // 提示：可以使用递归，定义一个辅助函数 dfs(node)
    //       dfs(node) 返回以 node 为起点向下延伸的最大单边路径和
    //       在递归过程中，计算经过 node 的路径和（左单边 + 右单边 + node->val）
    //       并用一个全局或引用变量记录全局最大值
    if (root == nullptr)
        return 0;

    int left_best = maxPathSum(root->left);
    if (left_best < 0)
        left_best = 0;
    int right_best = maxPathSum(root->right);
    if (right_best < 0)
        right_best = 0;

    int cur = left_best + root->val + right_best;
    if (cur > ans)
        ans = cur;

    // 返回给父节点时，只能选择一条向下的单链
    if (left_best > right_best)
        return left_best + root->val;
    else
        return right_best + root->val;
}
// ==================================================

int main()
{
    // 读取一整行层序遍历序列
    string line;
    getline(cin, line);
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    TreeNode *root = buildTree(tokens);

    maxPathSum(root);
    cout << ans << endl;

    return 0;
}