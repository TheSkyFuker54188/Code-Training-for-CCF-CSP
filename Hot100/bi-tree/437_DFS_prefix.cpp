//? 进阶的"前缀和"解法（树上的前缀和）
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <unordered_map>

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
unordered_map<long long, int> cnt;

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
void pref_Solve(TreeNode *node, long long curSum)
{ // 从 node 出发，向下搜索路径和等于 targetSum 的路径
    if (node == nullptr)
        return;

    curSum += node->val;
    ans += cnt[curSum - targetSum];

    cnt[curSum]++;

    pref_Solve(node->left, curSum);
    pref_Solve(node->right, curSum);

    // 回溯：离开当前节点时，撤销当前前缀和
    // 保证 cnt 中只保留当前递归路径上的信息
    cnt[curSum]--;
}

void pathSum(TreeNode *root)
{
    // TODO: 在这里实现你的算法
    // 路径方向向下（只能从父节点到子节点）
    // 路径不需要从根节点开始，也不需要在叶子节点结束
    if (root == nullptr)
        return;
    cnt[0] = 1;
    pref_Solve(root, 0);
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