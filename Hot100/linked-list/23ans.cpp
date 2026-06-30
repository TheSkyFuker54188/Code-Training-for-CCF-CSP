#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue> //?  用小顶堆（优先队列）

using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

// 自定义比较器：按节点值升序，用于构建小顶堆
struct Compare
{
    bool operator()(LinkNode *a, LinkNode *b)
    {
        return a->val > b->val; // > 表示值大的优先级低，堆顶是最小值
    }
};

int main()
{
    // ========== 输入 ==========
    int k;
    cin >> k;
    cin.ignore(); // 忽略换行

    vector<LinkNode *> lists(k, NULL);

    for (int i = 0; i < k; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<int> vals;
        int num;
        while (iss >> num)
            vals.push_back(num);

        if (!vals.empty())
        {
            lists[i] = new LinkNode(vals[0]);
            LinkNode *cur = lists[i];
            for (int j = 1; j < (int)vals.size(); j++)
            {
                cur->next = new LinkNode(vals[j]);
                cur = cur->next;
            }
        }
    }

    // ==================== 核心算法：用小顶堆合并 K 个升序链表 ====================
    priority_queue<LinkNode *, vector<LinkNode *>, Compare> pq;

    // 将每个非空链表的头节点入堆
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != NULL)
            pq.push(lists[i]);
    }

    LinkNode dummy(0);
    LinkNode *cur = &dummy;

    while (!pq.empty())
    {
        LinkNode *minNode = pq.top();
        pq.pop();
        cur->next = minNode;
        cur = cur->next;

        if (minNode->next != NULL)
            pq.push(minNode->next);
    }

    LinkNode *head = dummy.next;

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