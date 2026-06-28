#include <iostream>
#include <vector>
using namespace std;

// 链表节点定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main()
{
    // 读入数据
    int n, skipA;
    cin >> n >> skipA;
    vector<int> vecA(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vecA[i];
    }

    int m, skipB;
    cin >> m >> skipB;
    vector<int> vecB(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vecB[i];
    }

    // 构造链表 A
    ListNode *headA = new ListNode(vecA[0]);
    ListNode *curA = headA;
    vector<ListNode *> nodesA; // 保存 A 每个节点的地址
    nodesA.push_back(headA);
    for (int i = 1; i < n; i++)
    {
        curA->next = new ListNode(vecA[i]);
        curA = curA->next;
        nodesA.push_back(curA);
    }

    // 构造链表 B，并在指定位置连接交点
    ListNode *headB = nullptr;
    ListNode *curB = nullptr;
    if (m > 0)
    {
        headB = new ListNode(vecB[0]);
        curB = headB;
    }
    for (int i = 1; i < m; i++)
    {
        if (i == skipB && skipA < n)
        { // 连接到 A 的交点
            curB->next = nodesA[skipA];
            break;
        }
        else
        {
            curB->next = new ListNode(vecB[i]);
            curB = curB->next;
        }
    }

    // 特殊情况：skipB == 0 表示 B 的头节点就是交点
    if (skipB == 0 && skipA < n)
    {
        delete headB;          // 释放原来错误的头节点
        headB = nodesA[skipA]; // B 直接指向交点
    }

    ListNode *intersect = nullptr;
    if (headA && headB)
    {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB)
        {
            pA = (pA == nullptr ? headB : pA->next);
            pB = (pB == nullptr ? headA : pB->next);
        }
        intersect = pA;
    }

    // 输出结果
    if (intersect)
        cout << intersect->val << "\n";
    
    else
        cout << 0 << "\n";

    return 0;
}