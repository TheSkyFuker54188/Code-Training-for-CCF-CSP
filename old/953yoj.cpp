#include <iostream>

// 定义列表节点的结构体
struct ListNode
{
    int data;
    ListNode *succ; // 后继节点

    // 构造函数
    ListNode(int e = 0, ListNode *s = nullptr)
        : data(e), succ(s) {}
};

// 定义列表类
class List
{
private:
    ListNode *header; // 头节点

    // 初始化列表
    void init()
    {
        header = new ListNode();
    }

public:
    // 构造函数
    List() { init(); }

    // 在列表末尾插入元素
    void insertAsLast(int const &e)
    {
        ListNode *p = header;
        while (p->succ != nullptr)
        {
            p = p->succ;
        }
        p->succ = new ListNode(e);
    }

    // 对有序列表进行去重，保留每个元素第一次出现
    void deduplicate()
    {
        ListNode *p = header->succ;
        while (p != nullptr && p->succ != nullptr)
        {
            if (p->data == p->succ->data)
            {
                ListNode *toRemove = p->succ;
                p->succ = toRemove->succ; // 跳过重复节点
                delete toRemove;
            }
            else
            {
                p = p->succ; // 移动到下一个节点
            }
        }
    }

    // 删除值为m的节点
    void removeValue(int m)
    {
        ListNode *p = header;
        while (p->succ != nullptr)
        {
            if (p->succ->data == m)
            {
                ListNode *toRemove = p->succ;
                p->succ = toRemove->succ; // 删除值为m的节点
                delete toRemove;
            }
            else
            {
                p = p->succ; // 移动到下一个节点
            }
        }
    }

    // 输出最终的有序列表
    void print() const
    {
        ListNode *p = header->succ;
        while (p != nullptr)
        {
            std::cout << p->data << (p->succ ? " " : "");
            p = p->succ;
        }
        std::cout << std::endl;
    }
};

int main()
{
    int n, m;
    std::cin >> n;
    List myList;

    // 输入列表节点的值
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        myList.insertAsLast(value);
    }

    std::cin >> m;

    // 对有序列表去重
    myList.deduplicate();

    // 删除值为m的节点
    myList.removeValue(m);

    // 输出最终的有序列表
    myList.print();

    return 0;
}
