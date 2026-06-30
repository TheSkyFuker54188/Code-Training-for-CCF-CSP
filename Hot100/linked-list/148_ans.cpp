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

// 辅助函数：找到链表中点（快慢指针）
LinkNode *getMiddle(LinkNode *head)
{
    if (!head)
        return head;
    LinkNode *slow = head;
    LinkNode *fast = head->next;//如果都以head为起点，则偶数个会导致slow指向“取上整”；偶数个就取前者为中点，因此这里的fast要先走一步，变相使得slow向前一步
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 辅助函数：合并两个有序链表（升序）
LinkNode *merge(LinkNode *l1, LinkNode *l2)
{
    LinkNode dummy(0);
    LinkNode *cur = &dummy;
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
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

// 归并排序
LinkNode *sortList(LinkNode *head)
{
    if (!head || !head->next)
        return head;
    LinkNode *mid = getMiddle(head);
    LinkNode *right = mid->next;
    mid->next = NULL; // 断开
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

    // ========== 排序 ==========
    head = sortList(head);

    // ========== 输出 ==========
    LinkNode *prt = head;
    if (prt == NULL)
    {
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