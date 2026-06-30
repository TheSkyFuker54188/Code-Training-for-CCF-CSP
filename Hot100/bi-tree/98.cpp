//? 中序遍历 + 序列校验
/* 利用 BST 的中序遍历严格递增性质
边遍历边比较当前值与前一个值(前一个值的赋值是在左子树递归到最后一个节点赋值成prev的)
一旦出现 <= 就不是 BST。 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <climits>

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
void inorder(TreeNode *node, vector<int> &seq)
{
    if (node == nullptr)
        return;
    inorder(node->left, seq);
    seq.push_back(node->val);
    inorder(node->right, seq);
}

bool isValidBST(TreeNode *root)
{
    vector<int> seq;
    inorder(root, seq);
    for (int i = 0; i + 1 < (int)seq.size(); i++)
    {
        if (seq[i] >= seq[i + 1])
            return false;
    }
    return true;
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    if (line.empty())
    {
        // 题目给定节点数 >= 1，但防御一下
        cout << "true" << endl;
        return 0;
    }

    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建树
    TreeNode *root = buildTree(nodes);

    // 判断并输出
    cout << (isValidBST(root) ? "true" : "false") << endl;

    return 0;
}