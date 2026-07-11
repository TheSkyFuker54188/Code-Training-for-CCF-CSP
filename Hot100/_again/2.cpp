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

    cur1 = l1;
    cur2 = l2;
    bool carry = false;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        int x = cur1->val + cur2->val + carry;
        if (x >= 10)
            carry = true;
        else
            carry = false;
        x = x % 10;
        cout << x << " ";

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while (cur1)
    {
        int x = cur1->val + carry;
        if (x >= 10)
            carry = true;
        else
            carry = false;
        x = x % 10;
        cout << x << " ";
        cur1 = cur1->next;
    }
    while (cur2)
    {
        int x = cur2->val + carry;
        if (x >= 10)
            carry = true;
        else
            carry = false;
        x = x % 10;
        cout << x << " ";
        cur2 = cur2->next;
    }
    if (carry)
        cout << 1;
}