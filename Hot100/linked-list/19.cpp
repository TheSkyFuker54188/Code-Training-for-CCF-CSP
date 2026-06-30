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
    // 快指针先走 n 步
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // 如果 fast 已经为空，说明要删除的是头节点
    if (fast == NULL)
    {
        LinkNode *temp = head;
        head = head->next;
        delete temp; // 释放旧头节点（可选，OJ 可不写）
    }
    else
    {
        LinkNode *slow = head;
        // 快慢指针同时移动，直到 fast 走到最后一个节点
        while (fast->next != NULL) // 注意条件，保证 slow 停在待删节点的前驱
        {
            slow = slow->next;
            fast = fast->next;
        }
        // 删除 slow->next
        LinkNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp; // 释放被删节点（可选）
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