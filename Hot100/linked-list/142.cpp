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
    if (n == 0)
    {
        cout << -1;
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int pos;
    cin >> pos;

    LinkNode *head = new LinkNode(a[0]);
    LinkNode *cur = head;
    LinkNode *ist = NULL;
    for (int i = 1; i < n; i++)
    {
        cur->next = new LinkNode(a[i]);
        cur = cur->next;
        if (i == pos)
            ist = cur;
    }
    if (pos == 0)
        cur->next = head;
    else
        cur->next = ist;

    LinkNode *slow = head;
    LinkNode *fast = head;
    LinkNode *ans = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            ans = fast;
            LinkNode *p = head;
            for (int i = 0; i < n; i++)
            {
                if (p == ans)
                {
                    cout << i;
                    return 0;
                }
                p = p->next;
            }
        }
    }

    cout << -1;
}