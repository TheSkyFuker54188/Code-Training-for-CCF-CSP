//? 节点（指针）传递，通过判断是不是NULL来看
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
// 你需要完成的部分：寻找 p 和 q 的最近公共祖先
// ==================================================
// 参数:
//   root: 二叉树的根节点
//   p:    第一个节点的值
//   q:    第二个节点的值
// 返回值: 最近公共祖先节点

int p, q;

TreeNode *LCA(TreeNode *root)
{
    if (!root)
        return nullptr;

    if (root->val == p)
    {
        return root;
    }
    if (root->val == q)
    {
        return root;
    } // 这两个if放在递归函数之后也是对的，但放在前面能起到“剪枝”的效果

    TreeNode *l = LCA(root->left);
    TreeNode *r = LCA(root->right);

    if (l && r) // 发现LCA!
        return root;

    if (l) // 不必担心覆盖正确答案，因为只有LCA能做到l r都非空
        return l;
    if (r)
        return r;

    return nullptr;
}
// ==================================================

int main()
{
    // 读取第一行：层序遍历序列
    string line;
    getline(cin, line);
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    // 读取第二行：两个节点值
    // int p, q;
    cin >> p >> q;

    // 构建二叉树
    TreeNode *root = buildTree(tokens);

    TreeNode *ans = LCA(root);
    // 输出结果
    cout << ans->val << endl;

    return 0;
}