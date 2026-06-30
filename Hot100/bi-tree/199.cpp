/* 右视图 本质是 从上到下输出 层序遍历中的每一层最右侧的那个节点。
所以在 LeetCode 102. 二叉树的层序遍历的方法一的基础上
只需要每次将本层最后一个节点放入res , 而不是整行放入 即可。 */
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
// 返回二叉树的右视图（从上到下的节点值）
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    // 使用标准队列，存储当前层所有节点
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // 当前层节点数
        vector<int> val_arr;      // 存放当前层所有节点的值

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            val_arr.push_back(node->val); // 记录当前层值
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        // 当前层最右侧节点值加入结果
        res.push_back(val_arr.back());
    }
    return res;
}
// =====================================

int main()
{
    // 读取第一行：n
    int n;
    cin >> n;
    if (n == 0)
    {
        // 空树，输出空行
        cout << endl;
        return 0;
    }

    // 读取第二行：层序遍历序列
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略换行符
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> nodes;
    string token;
    while (iss >> token)
    {
        nodes.push_back(token);
    }

    // 构建二叉树
    TreeNode *root = buildTree(nodes);

    // 获取右视图并输出
    vector<int> view = rightSideView(root);
    for (size_t i = 0; i < view.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << view[i];
    }
    cout << endl;

    return 0;
}