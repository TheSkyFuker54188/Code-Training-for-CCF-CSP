#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> a;
    int num;
    while (iss >> num)
        a.push_back(num);

    int k;
    cin >> k;

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

    // ==================== 核心算法：K 个一组翻转 ====================
    LinkNode dummy(0);
    dummy.next = head;
    LinkNode *group_prev = &dummy;

    while (true)
    {
        // 1. 检查是否还够 k 个节点，并定位本组的结束节点 group_end
        LinkNode *group_end = group_prev;
        bool enough = true;
        for (int i = 0; i < k; ++i)
        {
            group_end = group_end->next;
            if (group_end == NULL)
            {
                enough = false;
                break;
            }
        }

        // 不足 k 个，退出整个循环
        if (!enough)
            break;

        LinkNode *next_group = group_end->next;

        // 2. 组内翻转（头插法）
        LinkNode *prev = next_group;
        LinkNode *cur = group_prev->next;
        for (int i = 0; i < k; ++i)
        {
            LinkNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // 3. 拼接：原头变尾，prev 是新头
        LinkNode *old_head = group_prev->next;
        group_prev->next = prev;
        group_prev = old_head;   // 移动到下一组的前驱
    }

    head = dummy.next;   // 更新头节点

    // ==================== 输出 ====================
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