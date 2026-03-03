#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits> // 添加此行，以使用 INT_MIN

using namespace std;

// 定义树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前向声明
TreeNode *deserializeHelper(stringstream &ss);

// 反序列化函数
TreeNode *deserialize(string &s)
{
    stringstream ss(s);
    return deserializeHelper(ss); // 调用 helper 函数
}

// 递归反序列化的辅助函数
TreeNode *deserializeHelper(stringstream &ss)
{
    string val;
    if (getline(ss, val, ','))
    {
        if (val == "#")
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(val)); // 将节点值转为整数
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }
    return NULL;
}

// 计算最大路径和
int maxPathSum(TreeNode *root, int &maxSum)
{
    if (!root)
    {
        return 0;
    }

    // 计算左右子树的最大路径和（如果小于0则不考虑）
    int left = max(0, maxPathSum(root->left, maxSum));   // 如果左子树路径和小于0，取0
    int right = max(0, maxPathSum(root->right, maxSum)); // 如果右子树路径和小于0，取0

    // 更新最大路径和
    maxSum = max(maxSum, left + right + root->val);

    // 返回当前节点的最大贡献值
    return root->val + max(left, right);
}

// 主函数，计算二叉树的最大路径和
int maxPathSum(string s)
{
    TreeNode *root = deserialize(s);
    int maxSum = INT_MIN; // 使用 INT_MIN 来初始化
    maxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    string s;
    cin >> s;
    cout << maxPathSum(s) << endl; // 输出 6
    return 0;
}
