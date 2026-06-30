#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <limits>

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
void inorder(TreeNode *node, vector<int> &seq)
{
    if (node == nullptr)
        return;
    inorder(node->left, seq);
    seq.push_back(node->val);
    inorder(node->right, seq);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> seq;
    inorder(root, seq);
    return seq[k - 1];
}
// =====================================

int main()
{
    // 读取第一行：n 和 k
    int n, k;
    cin >> n >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略换行符，准备读取下一行

    // 读取第二行：层序遍历序列
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建二叉搜索树
    TreeNode *root = buildTree(nodes);

    // 输出第 k 小的元素
    cout << kthSmallest(root, k) << endl;

    return 0;
}