#include <iostream>
#include <vector>

using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

int main()
{
    // ========== 输入 ==========
    int n;
    cin >> n;
    vector<int> an(n);
    for (int i = 0; i < n; i++)
        cin >> an[i];

    int m;
    cin >> m;
    vector<int> am(m);
    for (int i = 0; i < m; i++)
        cin >> am[i];

    // ========== 构造链表 L1 ==========
    LinkNode *l1 = new LinkNode(an[0]);
    LinkNode *cur1 = l1;
    for (int i = 1; i < n; i++)
    {
        cur1->next = new LinkNode(an[i]);
        cur1 = cur1->next;
    }

    // ========== 构造链表 L2 ==========
    LinkNode *l2 = new LinkNode(am[0]);
    LinkNode *cur2 = l2;
    for (int i = 1; i < m; i++)
    {
        cur2->next = new LinkNode(am[i]);
        cur2 = cur2->next;
    }

    // =============================================
    LinkNode *p1 = l1;
    LinkNode *p2 = l2;

    int sum = p1->val + p2->val;
    bool carry = (sum >= 10);

    LinkNode *head = new LinkNode(sum % 10); // 结果链表的头节点
    LinkNode *cur = head;
    p1 = p1->next;
    p2 = p2->next;

    while (p1 != NULL || p2 != NULL || carry != false)
    {
        int v = carry;
        if (p1 != NULL)
        {
            v += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            v += p2->val;
            p2 = p2->next;
        }
        carry = (v >= 10);
        v = v % 10;
        cur->next = new LinkNode(v);
        cur = cur->next;
    }
    // =============================================

    LinkNode *prt = head;
    if (prt == NULL) // 理论上不会发生，除非你算法没造节点
    {
        cout << 0;
    }
    else
    {
        while (prt != NULL)
        {
            cout << prt->val;
            if (prt->next != NULL)
                cout << " ";
            prt = prt->next;
        }
    }
    cout << endl;

    return 0;
}