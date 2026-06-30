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
    LinkNode dummy(0);
    dummy.next = head;
    LinkNode *prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL)
    {
        LinkNode *first = prev->next;   // 当前对的第一个节点
        LinkNode *second = first->next; // 当前对的第二个节点

        // 交换
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // 移动 prev 到下一对的前驱（即原来的 first，现在在 second 后面）
        prev = first;
    }

    head = dummy.next; // 关键！更新头节点

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