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
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int pos;
    cin >> pos;

    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;

    if (pos == -1)
    {
        cout << "false";
        return 0;
    }

    ListNode *back = NULL;
    for (int i = 1; i < n; i++)
    {
        cur->next = new ListNode(a[i]);
        cur = cur->next;
        if (pos == i)
        {
            back = cur;
        }
    }
    if (pos == 0)
        cur->next = head;
    else
        cur->next = back;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}