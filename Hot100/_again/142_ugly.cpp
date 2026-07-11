#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    int idx;
    Node *next;
    Node(int x, int i) : val(x), idx(i), next(nullptr) {}
};

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    if (n == 0 )
    {
        cout << -1;
        return 0;
    }

    vector<int> tem(n);
    for (int i = 0; i < n; i++)
        cin >> tem[i];

    int end;
    cin >> end;

    Node *dum = new Node(0, -1);
    Node *head = new Node(tem[0], 0);
    Node *cur = head;
    Node *ist;
    dum->next = head;
    for (int i = 1; i < n; i++)
    {
        cur->next = new Node(tem[i], i);
        cur = cur->next;
    }

    cur = dum;
    if (end != -1)
    {
        for (int i = 0; i < n; i++)
        {
            cur = cur->next;
            if (i == end)
            {
                ist = cur;
            }
        }
        cur->next = ist;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            cout << fast->idx;
            return 0;
        }
    }

    cout << -1;
    return 0;
}