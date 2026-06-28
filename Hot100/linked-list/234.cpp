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
    if (n == 1)
    {
        cout << "true";
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++)
    {
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *prev = NULL;
    ListNode *now = slow;
    ListNode *nxt = NULL;
    for (int i = 0; i < n / 2; i++)
    {
        nxt = now->next;
        now->next = prev;
        prev = now;
        now = nxt;
    }

    ListNode *left = head;
    ListNode *right = prev;
    for (int i = 0; i < n / 2; i++)
    {
        if (left->val != right->val)
        {
            cout << "false";
            return 0;
        }

        left = left->next;
        right = right->next;
    }
    cout << "true";
}