#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

int main()
{
    // ========== 输入 ==========
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> randomIdx(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i] >> randomIdx[i];
    }

    // ========== 构造原链表（带 random 指针） ==========
    Node *head = NULL;
    vector<Node *> nodeRef(n, NULL); // 存储每个节点的地址，方便设置 random
    if (n > 0)
    {
        head = new Node(vals[0]);
        nodeRef[0] = head;
        Node *cur = head;
        for (int i = 1; i < n; i++)
        {
            cur->next = new Node(vals[i]);
            cur = cur->next;
            nodeRef[i] = cur;
        }
        // 设置 random 指针
        cur = head;
        for (int i = 0; i < n; i++)
        {
            int idx = randomIdx[i];
            if (idx != -1)
                cur->random = nodeRef[idx];
            else
                cur->random = NULL;
            cur = cur->next;
        }
    }

    // ==================== 核心算法：深拷贝链表 ====================
    // 要求：新链表每个节点值对应原节点值，next 和 random 指针指向新链表内部节点
    //
    // 常用方法：
    // 1. 哈希表法：原节点 -> 新节点映射，两趟遍历
    // 2. 原地复制法：每个原节点后插入新节点，设置 random 后拆分
    //
    // 请在下面编写你的深拷贝代码，将结果链表头节点存入 copyHead
    Node *copyHead = NULL;
    unordered_map<Node *, Node *> m;
    Node *ptr = head;
    for (int i = 0; i < n; i++)
    {
        m[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    for (int i = 0; i < n; i++)
    {
        m[ptr]->next = ptr->next;
        m[ptr]->random = ptr->random;
    }
    copyHead = m[head];

    // ==================== 输出 ====================
    // 为了输出随机指针的索引，需要建立 新节点 -> 索引 的映射

    vector<Node *> copyRef; // 新链表节点顺序
    Node *cur = copyHead;
    while (cur)
    {
        copyRef.push_back(cur);
        cur = cur->next;
    }
    // 建立 新节点地址 -> 索引 的映射
    unordered_map<Node *, int> addrToIdx;
    for (int i = 0; i < (int)copyRef.size(); i++)
    {
        addrToIdx[copyRef[i]] = i;
    }

    cur = copyHead;
    while (cur)
    {
        cout << cur->val << " ";
        if (cur->random)
            cout << addrToIdx[cur->random]; // 输出在新链表中的索引
        else
            cout << -1;
        cout << endl;
        cur = cur->next;
    }

    return 0;
}