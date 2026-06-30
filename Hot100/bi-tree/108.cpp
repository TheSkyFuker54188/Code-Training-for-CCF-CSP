//? 自底向上的DFS
//? 由于这个数组本身就是有序的
//? 所以可以每次取区间的中间位置的值作为根节点
//? 然后递归左右两边的区间进行建树即可。

/* 为什么就”平衡“了？
取数组的中间元素作为根节点，是让左右子树节点数量尽可能相等的最直接办法。
平衡的定义是：任意节点的左右子树高度差 ≤ 1。我们就是利用“数量平衡”来保证“高度平衡”。 
*/

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

// 将有序数组 nums 转换为平衡二叉搜索树，返回根节点
TreeNode *dfs(const vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = dfs(nums,l, mid - 1);
    root->right = dfs(nums,mid + 1, r);
    return root;
}
TreeNode *sortedArrayToBST(const vector<int> &nums)
{
    return dfs(nums,0, (int)nums.size() - 1);
}
// =====================================

// 层序遍历输出（去掉末尾 null）
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
    // 读取数组长度 n
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // 构建平衡二叉搜索树
    TreeNode *root = sortedArrayToBST(nums);

    // 层序输出
    printTree(root);

    return 0;
}