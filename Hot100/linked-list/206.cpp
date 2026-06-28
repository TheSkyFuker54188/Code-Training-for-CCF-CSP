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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ListNode *head = new ListNode(v[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++)
    {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }

    ListNode *prev = NULL;
    cur = head;
    ListNode *nxt = NULL;

    for (int i = 0; i < n; i++)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    for (int i = 0; i < n; i++)
    {
        cout << prev->val << " ";
        prev = prev->next;
    }
}