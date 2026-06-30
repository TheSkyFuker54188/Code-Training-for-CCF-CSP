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
bool isMirror(TreeNode *a, TreeNode *b)
{
    /*
    1.左子树的根值 == 右子树的根值
    2.左子树的左孩子 和 右子树的右孩子 互为镜像
    3.左子树的右孩子 和 右子树的左孩子 互为镜像
    */
    if (a == nullptr && b == nullptr)
    {
        return true;
    }
    // 一边为空，一边不为空，说明不对称
    else if (a == nullptr || b == nullptr)
    {
        return false;
    }
    else if (a->val != b->val)
    {
        return false;
    }
    return (isMirror(a->left, b->right) && isMirror(a->right, b->left));
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return isMirror(root->left, root->right);
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    if (line.empty())
    {
        cout << "false" << endl; // 空树按题意不出现，但防御一下
        return 0;
    }

    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建树，判断对称性，输出结果
    TreeNode *root = buildTree(nodes);
    cout << (isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}