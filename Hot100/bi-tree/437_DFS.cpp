// 枚举每个节点作为根节点，向下搜寻所有的路径中：和恰好为target的路径
// 此时我们需要两个递归函数，一个用来枚举所有点，一个用来寻找合法路径
//! 为什么需要两个函数？  只用一个递归函数,只能自然地处理“从根节点出发”的路径,没办法自动地“换一个起点”
/*
第一个函数（外层 - pathSum）：枚举所有可能的起点
它遍历整棵树的每一个节点，每到一个节点就说：“好，现在以你为起点，向下找合法路径”。
第二个函数（内层 - findTarget）：从某个固定起点出发，向下穷举所有可能的路径
它只负责从当前节点往下走，边走边累加和，看看有没有等于 targetSum 的。
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// 二叉树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;
int targetSum;

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
// 你需要完成的部分：计算路径和等于 targetSum 的路径数量
// ==================================================
// 参数:
//   root:      二叉树的根节点
//   targetSum: 目标路径和
// 返回值: 路径数量
void findTarget(TreeNode *node, long long curSum)
{ // 从 node 出发，向下搜索路径和等于 targetSum 的路径
    if (node == nullptr)
        return;

    curSum += node->val;
    if (curSum == targetSum)
        ans++;

    findTarget(node->left, curSum);
    findTarget(node->right, curSum);
}

void pathSum(TreeNode *root)
{
    // TODO: 在这里实现你的算法
    // 路径方向向下（只能从父节点到子节点）
    // 路径不需要从根节点开始，也不需要在叶子节点结束
    if (root == nullptr)
        return;

    findTarget(root, 0);
    pathSum(root->left);
    pathSum(root->right);
}
// ==================================================

int main()
{
    int n;
    cin >> n;

    // 消耗掉第一行的换行符
    cin.ignore();

    vector<string> tokens;
    if (n > 0)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }
    }

    cin >> targetSum;

    TreeNode *root = buildTree(tokens);

    pathSum(root);
    cout << ans << endl;

    return 0;
}