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

    // 插入排序算法
    void insertionSort() {
        if (!header->succ || !header->succ->succ) // 列表为空或只有一个元素时不需要排序
            return;

        ListNode *sorted = header->succ; // 已排序部分的尾节点
        ListNode *current = sorted->succ; // 当前待插入的节点

        while (current != nullptr) {
            if (current->data >= sorted->data) { // 如果当前节点已经在正确位置
                sorted = current;
            } else { // 否则，将当前节点插入到已排序部分的正确位置
                ListNode *prev = header;
                while (prev->succ != nullptr && prev->succ->data < current->data) {
                    prev = prev->succ;
                }

                // 将current插入到prev之后
                sorted->succ = current->succ; // 从原位置移除当前节点
                current->succ = prev->succ; // 插入到新位置
                prev->succ = current; // 更新链接
            }
            current = sorted->succ; // 处理下一个节点
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

    // 对列表进行插入排序
    myList.insertionSort();

    // 输出排序后的列表
    myList.print();

    return 0;
}
