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
// 返回按层收集的节点值，每一层为一个 vector<int>
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return vector<vector<int>>();

    // 使用标准队列进行层序遍历
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;

    while (!q.empty())
    {
        // 记录当前层的节点数量（关键：用 size 锁定这一层的边界）
        int levelSize = q.size();
        vector<int> val_arr;

        // 依次处理当前层的所有节点
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            // 收集当前层节点的值
            val_arr.push_back(node->val);
            // 将下一层的节点加入队列（等待下一轮循环处理）
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }

        // 当前层处理完毕，保存结果
        res.push_back(val_arr);
    }

    return res;
}
// =====================================

int main()
{
    // 读取一行输入，按空格拆分成字符串数组
    string line;
    getline(cin, line);
    if (line.empty())
    {
        // 空树 → 输出空行
        cout << endl;
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

    // 获取层序遍历结果
    vector<vector<int>> ans = levelOrder(root);

    // 按层输出
    for (size_t i = 0; i < ans.size(); ++i)
    {
        for (size_t j = 0; j < ans[i].size(); ++j)
        {
            if (j > 0)
                cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}