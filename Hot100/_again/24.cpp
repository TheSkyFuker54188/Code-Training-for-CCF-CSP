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

    // ========== 构造链表（允许空链表） ==========
    LinkNode *head = NULL;
    if (sz > 0)
    {
        head = new LinkNode(a[0]);
        LinkNode *cur = head;
        for (int i = 1; i < sz; i++)
        {
            cur->next = new LinkNode(a[i]);
            cur = cur->next;
        }
    }

    // ===================================================================
    LinkNode *dum = new LinkNode(0);
    dum->next = head;

    LinkNode *pre = dum;
    while (pre->next != nullptr && pre->next->next != nullptr)
    {//! “先定位本轮状态，再执行操作”
        //todo 直观思路中，先执行本轮操作，再更新状态。
        //todo 但实际上写代码反着来往往更健壮（每轮的一开始就设置更新状态，再执行核心操作）
        LinkNode *first = pre->next;
        LinkNode *second = first->next;

        first->next = second->next;
        second->next = first;
        pre->next = second;

        pre = first;
    }
    head = dum->next;

    // ===================================================================

    LinkNode *prt = head;
    if (prt == NULL)
    {
        // 空链表输出空行
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