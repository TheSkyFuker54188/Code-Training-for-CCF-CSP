#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据给定的向量创建二叉树
TreeNode* buildTree(const vector<int>& values, int index) {
    if (index >= values.size()) return nullptr;  // 如果索引超出范围，返回空
    TreeNode* root = new TreeNode(values[index]);
    root->left = buildTree(values, 2 * index + 1);   // 左子节点
    root->right = buildTree(values, 2 * index + 2);  // 右子节点
    return root;
}

// 中序遍历，记录节点的父节点和当前节点的顺序
void inorder(TreeNode* root, TreeNode* parent, vector<TreeNode*>& inorderList) {
    if (root == nullptr) return;
    inorder(root->left, root, inorderList);  // 先遍历左子树
    inorderList.push_back(root);  // 然后访问根节点
    inorder(root->right, root, inorderList);  // 最后遍历右子树
}

// 找到目标节点的前驱和后继
void findPredecessorSuccessor(TreeNode* root, int key) {
    vector<TreeNode*> inorderList;
    inorder(root, nullptr, inorderList);  // 获取中序遍历顺序

    TreeNode* predecessor = nullptr;
    TreeNode* successor = nullptr;
    
    // 查找目标节点的前驱和后继
    for (int i = 0; i < inorderList.size(); ++i) {
        if (inorderList[i]->val == key) {
            if (i > 0) predecessor = inorderList[i - 1];  // 前驱节点
            if (i < inorderList.size() - 1) successor = inorderList[i + 1];  // 后继节点
            break;
        }
    }

    // 输出前驱和后继节点的值
    if (predecessor) cout << predecessor->val << " ";
    else cout << -1 << " ";  // 如果没有前驱节点，输出 -1
    if (successor) cout << successor->val << endl;
    else cout << -1 << endl;  // 如果没有后继节点，输出 -1
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    int key;
    cin >> key;

    // 构建二叉树
    TreeNode* root = buildTree(values, 0);

    // 查找前驱和后继节点
    findPredecessorSuccessor(root, key);

    return 0;
}
