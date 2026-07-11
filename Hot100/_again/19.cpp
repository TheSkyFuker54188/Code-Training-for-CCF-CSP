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
    int sz;
    cin >> sz;
    vector<int> a(sz);
    for (int i = 0; i < sz; i++)
        cin >> a[i];
    int n;
    cin >> n;

    // ========== 构造链表（正序） ==========
    LinkNode *head = new LinkNode(a[0]);
    LinkNode *cur = head;
    for (int i = 1; i < sz; i++)
    {
        cur->next = new LinkNode(a[i]);
        cur = cur->next;
    }

    // =============================================
    LinkNode *fast = head;
    LinkNode *slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (fast == nullptr)//! 删除头节点
    {
        LinkNode *del = head;
        head=head->next;
        free(del);
    }
    else
    {
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        LinkNode *del = slow->next;
        slow->next = slow->next->next;
        free(del);
    }
    // =============================================

    LinkNode *prt = head;
    if (prt == NULL)
    {
        // 链表为空，输出空行
        cout << endl;
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
        cout << endl;
    }

    return 0;
}