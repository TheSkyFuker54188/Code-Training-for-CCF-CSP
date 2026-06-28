#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
    int n, skipA;
    cin >> n >> skipA;

    vector<int> vecA(n);
    for (int i = 0; i < n; i++)
        cin >> vecA[i];

    int m, skipB;
    cin >> m >> skipB;

    vector<int> vecB(m);
    for (int i = 0; i < m; i++)
        cin >> vecB[i];

    ListNode *headA = new ListNode(vecA[0]);
    ListNode *curA = headA;

    vector<ListNode *> nodesA;
    nodesA.push_back(headA);
    for (int i = 1; i < n; i++)
    {
        curA->next = new ListNode(vecA[i]);
        curA = curA->next;
        nodesA.push_back(curA);
    }

    ListNode *headB = new ListNode(vecB[0]);
    ListNode *curB = headB;
    for (int i = 1; i < m; i++)
    {
        if (i == skipB)
        {
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
        delete headB;
        headB = nodesA[skipA];
    }

    //? 核心算法
    ListNode *intersect = NULL;
    if (headA && headB)
    {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB)
        {
            pA = (pA == NULL ? headB : pA->next);
            pB = (pB == NULL ? headA : pB->next);
        }
        intersect = pA;
    }

    if (intersect)
        cout << intersect->val << '\n';

    else
        cout << 0 << '\n';

    return 0;
}