#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

LinkNode *getMid(LinkNode *head)
{
    if (!head)
        return head;
    LinkNode *slow = head;
    LinkNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

LinkNode *merge(LinkNode *l1, LinkNode *l2)
{
    LinkNode *dum = new LinkNode(0);
    LinkNode *cur = dum;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    return dum->next;
}

LinkNode *sortList(LinkNode *head)
{
    if (!head || !head->next)
        return head;
    LinkNode *mid = getMid(head);
    LinkNode *right = mid->next;
    mid->next = NULL;
    LinkNode *leftSorted = sortList(head);
    LinkNode *rightSorted = sortList(right);
    return merge(leftSorted, rightSorted);
}

int main()
{
    // ========== 输入 ==========
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> a;
    int num;
    while (iss >> num)
        a.push_back(num);

    int n = a.size();

    // ========== 构造链表 ==========
    LinkNode *head = NULL;
    if (n > 0)
    {
        head = new LinkNode(a[0]);
        LinkNode *cur = head;
        for (int i = 1; i < n; i++)
        {
            cur->next = new LinkNode(a[i]);
            cur = cur->next;
        }
    }

    // ==================== 核心算法：链表排序 ====================
    // 要求：将链表按升序排列，返回排序后的头节点。
    // 提示：
    //   - 常用的 O(n log n) 方法有：归并排序（推荐）、快速排序。
    //   - 归并排序步骤：找中点 → 断开 → 递归排序两半 → 合并有序链表。
    //   - 可以使用 dummy 节点简化合并过程。
    //
    // 在这里编写你的排序代码，结果赋给 head 即可。
    head = sortList(head);

    // ==================== 输出 ====================
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