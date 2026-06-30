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
{ // 处理空树
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    // 创建根节点，并把它放入队列
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    // 用 idx 遍历数组，为队列中的节点依次挂接孩子
    int idx = 1;
    int n = nodes.size();

    while (!q.empty() && idx < n)
    { // 循环：取出队头节点，为它挂左、右孩子
        TreeNode *cur = q.front();
        q.pop();
        // 左子节点
        if (idx < n && nodes[idx] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[idx]));
            // 因为左孩子未来也会有它自己的子节点，所以也要排队等待处理
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

// 递归中序遍历
void inorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

int main()
{
    string line;
    getline(cin, line);

    // 分割输入字符串
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    TreeNode *root = buildTree(tokens);

    vector<int> res;
    inorder(root, res);

    // 输出结果
    for (int i = 0; i < res.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << res[i];
    }
    cout << endl;

    return 0;
}