// todo 重要结论：由于直径是最长的路径，那么它的两个端点不可能是二叉树的内部节点
// todo 只能是根 / 叶子节点

//? 自底向上的DFS
//? 枚举每个节点作为拐点，计算经过该拐点的最长路径长度
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

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
// ans 记录全局最长路径长度，路径长度按边数计算
int ans = 0;

int maxD(TreeNode *root)
{
    if (root == nullptr)
        return -1;
    int left_max = maxD(root->left);
    int right_max = maxD(root->right);
    int cur = left_max + right_max + 2;
    if (cur > ans)
        ans = cur;

    if (left_max > right_max)
        return left_max + 1;
    return right_max + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    maxD(root);
    return ans;
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    if (line.empty())
    {
        cout << 0 << endl; // 空树直径为0
        return 0;
    }

    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建树，计算直径，输出结果
    TreeNode *root = buildTree(nodes);
    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}