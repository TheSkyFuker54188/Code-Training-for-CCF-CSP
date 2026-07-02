//? 递归划分区间（DFS + 哈希表）
#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

// 方便找根
// idx[val] = 在 inorder 中的位置
unordered_map<int, int> idx;

// ==================================================
// 你需要完成的部分：根据前序和中序遍历构造二叉树
// ==================================================
// 参数:
//   preorder: 前序遍历序列
//   inorder:  中序遍历序列
// 返回值: 构造出的二叉树的根节点

// dfs(preL, preR, inL, inR):
// 当前子树的先序区间是 [preL, preR]
// 当前子树的中序区间是 [inL, inR]
TreeNode *dfs(int preL, int preR, int inL, int inR,
              vector<int> &preorder, vector<int> &inorder)
{
    if (preL > preR)
        return nullptr;

    int rootVal = preorder[preL];
    TreeNode *root = new TreeNode(rootVal);

    int k = idx[rootVal];
    int leftsize = k - inL; // 根节点左边都是左子树，所以可以得到左子树节点个数
    root->left = dfs(preL + 1, preL + leftsize, inL, k - 1, preorder, inorder);
    root->right = dfs(preL + leftsize + 1, preR, k + 1, inR, preorder, inorder);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // TODO: 在这里实现你的算法
    // 提示：preorder[0] 是根节点，在中序中找到根的位置，
    //       然后递归构造左子树和右子树
    int n = preorder.size();
    if (n == 0)
        return nullptr;

    // 记录中序遍历中每个值的位置，方便 O(1) 找到根节点下标
    for (int i = 0; i < n; i++)
        idx[inorder[i]] = i;

    return dfs(0, n - 1, 0, n - 1, preorder, inorder);
}
// ==================================================

// 层序遍历输出（包含 null，去掉末尾多余的 null）
void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    vector<string> result;

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (cur == nullptr)
        {
            result.push_back("null");
        }
        else
        {
            result.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
    }

    // 去掉末尾所有的 "null"
    while (!result.empty() && result.back() == "null")
    {
        result.pop_back();
    }

    // 输出
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> preorder(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> preorder[i];
    }

    vector<int> inorder(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> inorder[i];
    }

    TreeNode *root = buildTree(preorder, inorder);

    printTree(root);

    return 0;
}