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

    LinkNode *l1 = new LinkNode(an[0]);
    LinkNode *cur1 = l1;
    for (int i = 1; i < n; i++)
    {
        cur1->next = new LinkNode(an[i]);
        cur1 = cur1->next;
    }
    LinkNode *l2 = new LinkNode(am[0]);
    LinkNode *cur2 = l2;
    for (int i = 1; i < m; i++)
    {
        cur2->next = new LinkNode(am[i]);
        cur2 = cur2->next;
    }

    LinkNode *head = NULL;
    LinkNode *cur = head;
    LinkNode *p1 = l1;
    LinkNode *p2 = l2;
    if (p1->val < p2->val)
    {
        head = p1;
        cur = p1;
        p1 = p1->next;
    }
    else
    {
        head = p2;
        cur = p2;
        p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val < p2->val)
        {
            cur->next = p1;
            cur = cur->next;
            p1 = p1->next;
        }
        else
        {
            cur->next = p2;
            cur = cur->next;
            p2 = p2->next;
        }
    }

    // 连接剩余部分
    if (p1)
        cur->next = p1;
    if (p2)
        cur->next = p2;

    LinkNode *prt = head;
    for (int i = 0; i < n + m; i++)
    {
        cout << prt->val << " ";
        prt = prt->next;
    }
}