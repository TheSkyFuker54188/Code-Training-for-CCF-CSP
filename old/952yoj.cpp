#include <iostream>
#include <unordered_map>
#include <vector>

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

    // 查找给定值的节点，返回该节点的指针
    ListNode *find(int const &e)
    {
        ListNode *p = header->succ;
        while (p != nullptr)
        {
            if (p->data == e)
            {
                return p;
            }
            p = p->succ;
        }
        return nullptr;
    }

    // 对无序列表进行去重，保留最后一个出现的数字
    void deduplicate()
{
    std::unordered_map<int, ListNode *> lastOccurrences;
    ListNode *p = header->succ;
    ListNode *prev = header;

    while (p != nullptr)
    {
        if (lastOccurrences.count(p->data))
        {
            // 如果当前节点是重复节点，删除上一次存储的节点
            ListNode *toRemove = lastOccurrences[p->data]; // 获取之前出现的节点
            ListNode *toRemovePrev = header;

            // 找到 toRemove 节点的前驱节点
            while (toRemovePrev->succ != toRemove)
            {
                toRemovePrev = toRemovePrev->succ;
            }

            // 删除之前的重复节点
            toRemovePrev->succ = toRemove->succ; // 跳过之前的节点
            delete toRemove; // 删除之前的节点
        }

        // 更新 lastOccurrences 映射，以指向当前节点
        lastOccurrences[p->data] = p;
        prev = p; // 更新前驱节点为当前节点
        p = p->succ; // 移动到下一个节点
    }
}


    // 输出去重后的列表
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
    int n;
    std::cin >> n;
    List myList;

    // 输入列表节点的值
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        myList.insertAsLast(value);
    }

    // 对无序列表去重
    myList.deduplicate();

    // 输出去重后的列表
    myList.print();

    return 0;
}
