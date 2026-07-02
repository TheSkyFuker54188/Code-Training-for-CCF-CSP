//? 自底向上的DFS
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
// 你需要完成的部分：二叉树展开为链表（先序顺序，原地）
// ==================================================
TreeNode *flatten(TreeNode *root)
{
    // TODO: 在这里实现你的算法
    // 要求：将二叉树原地展开为单链表，使用 right 指针指向下一个节点，left 指针置为 null
    // 链表顺序与二叉树的 先序遍历 顺序相同
    if (root == nullptr)
        return nullptr;

    // 先把左右子树摘出来，方便调整
    TreeNode *leftHead = root->left;
    TreeNode *rightHead = root->right;

    /*
    为什么要返回尾节点？
    因为当我们把左链表接到根节点后面之后
    还需要把右链表接到左链表的末尾，这时候就必须知道左链表的最后一个节点是谁
    */
    TreeNode *leftTail = flatten(root->left);
    TreeNode *rightTail = flatten(root->right);

    // 当前节点展开后应为：node -> 左链 -> 右链
    if (leftHead != nullptr)
    {
        root->right = leftHead;
        root->left = nullptr;
        leftTail->right = rightHead;
    }

    /*
    【返回逻辑】
    如果有右链表，尾节点就是右链表的尾（rightTail）；
    否则如果有左链表，尾节点就是左链表的尾（leftTail）；
    如果左右都为空，尾节点就是当前节点自己（node）。
    这样递归回到上层时，上层就能准确拿到自己这部分的链表尾部，继续拼接。 */
    if (rightTail != nullptr)
        return rightTail;
    if (leftTail != nullptr)
        return leftTail;
    else
        return root;
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

    flatten(root);

    // 输出展开后的结果
    printTree(root);

    return 0;
}
