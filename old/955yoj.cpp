#include <iostream>

// 定义列表节点的结构体
struct ListNode {
    int data;
    ListNode *succ; // 后继节点

    // 构造函数
    ListNode(int e = 0, ListNode *s = nullptr)
        : data(e), succ(s) {}
};

// 定义列表类
class List {
private:
    ListNode *header; // 头节点

    // 初始化列表
    void init() {
        header = new ListNode(); // 创建一个头节点
    }

public:
    // 构造函数
    List() { init(); }

    // 在列表末尾插入元素
    void insertAsLast(int const &e) {
        ListNode *p = header;
        while (p->succ != nullptr) {
            p = p->succ;
        }
        p->succ = new ListNode(e);
    }

    // 选择排序算法
    void selectionSort() {
        for (ListNode *sortedEnd = header; sortedEnd->succ != nullptr; sortedEnd = sortedEnd->succ) {
            ListNode *minNode = sortedEnd->succ;
            ListNode *current = minNode->succ;

            // 找到未排序部分的最小节点
            while (current != nullptr) {
                if (current->data < minNode->data) {
                    minNode = current;
                }
                current = current->succ;
            }

            // 如果找到的最小节点不是当前节点，则交换数据
            if (minNode != sortedEnd->succ) {
                std::swap(minNode->data, sortedEnd->succ->data);
            }
        }
    }

    // 输出最终的有序列表
    void print() const {
        ListNode *p = header->succ;
        while (p != nullptr) {
            std::cout << p->data << (p->succ ? " " : "");
            p = p->succ;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;
    List myList;

    // 输入列表节点的值
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        myList.insertAsLast(value);
    }

    // 对列表进行选择排序
    myList.selectionSort();

    // 输出排序后的列表
    myList.print();

    return 0;
}
