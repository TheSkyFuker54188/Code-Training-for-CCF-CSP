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

TreeNode *LCA(TreeNode *root, int p, int q)
{
    // TODO: 在这里实现你的算法
    // 提示：递归在左右子树中查找 p 和 q
    //    如果左右子树各找到一个，当前节点就是 LCA
    //    如果只在一侧找到，则那一侧的结果就是 LCA
    if (root == nullptr)
        return nullptr;

    //! 如果题目不保证存在，这个写法在“只有一个节点存在”时会给出一个错误的假 LCA
    if (root->val == p || root->val == q)
        return root;

    TreeNode *l = LCA(root->left, p, q);
    TreeNode *r = LCA(root->right, p, q);

    // 左右各找到一个，说明当前节点就是 LCA
    if (l != nullptr && r != nullptr)
        return root;
    // 否则，哪边非空就把那个结果往上传递
    if (l != nullptr)
        return l;
    if (r != nullptr)
        return r;
    // 两边都空，当前子树没有 p 也没有 q
    return nullptr;
}
// todo 如果题目不保证一定有解，那么下面这种判断方法才是对的
/* TreeNode *LCA(TreeNode *root, int p, int q, bool &foundP, bool &foundQ)
{
    if (!root)
        return nullptr;

    // 先递归，再处理当前节点（确保整棵树都被访问）
    TreeNode *l = LCA(root->left, p, q, foundP, foundQ);
    TreeNode *r = LCA(root->right, p, q, foundP, foundQ);

    if (root->val == p)
    {
        foundP = true;
        return root;
    }
    if (root->val == q)
    {
        foundQ = true;
        return root;
    }

    if (l && r)
        return root;
    return l ? l : r;
} */
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
    int p, q;
    cin >> p >> q;

    // 构建二叉树
    TreeNode *root = buildTree(tokens);

    TreeNode *ans = LCA(root, p, q);
    // 输出结果
    cout << ans->val << endl;

    return 0;
}