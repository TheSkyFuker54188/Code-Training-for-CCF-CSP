#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

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
    cin.ignore(); // 忽略换行，准备读取每行链表

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

        // 构造当前链表（可能为空）
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

    // ==================== 核心算法：合并 K 个升序链表 ====================
    // 要求：将所有链表合并为一个升序链表，返回头节点。
    //
    // 常用方法：
    // 1. 逐一合并（两两合并，O(k * n) 时间）
    // 2. 分治法（归并，O(n log k) 时间）
    // 3. 优先队列（小顶堆，O(n log k) 时间）
    //
    // 提示：
    //   - 可以使用之前的 mergeTwoLists(l1, l2) 函数。
    //   - 使用优先队列需要自定义比较函数（按照节点值排序）。
    //   - 推荐使用 dummy 节点简化结果链表构建。
    //
    // 在这里编写你的代码，结果赋给 head 即可。
    priority_queue<LinkNode *, vector<LinkNode *>, Compare> pq;

    for (int i = 0; i < k; i++)
        if (lists[i] != NULL)
            pq.push(lists[i]); // 先把每条非空链表的 **头节点** 丢进堆里

    LinkNode *dum = new LinkNode(0);
    LinkNode *cur = dum;

    while (!pq.empty())
    {
        LinkNode *minNode = pq.top();
        pq.pop();
        cur->next = minNode;
        cur = cur->next; // 弹出堆顶（当前最小）接到结果后面

        if (minNode->next != NULL)
            pq.push(minNode->next);
    } // 如果它还有 next，就把 next 再入堆

    LinkNode *head = dum->next;

    // 例如（需实现合并逻辑）：
    // head = mergeKLists(lists);

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