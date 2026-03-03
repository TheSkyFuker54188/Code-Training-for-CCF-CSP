#include <iostream>

// 定义列表节点的结构体
struct ListNode {
    int data;
    ListNode* pred; // 前驱节点
    ListNode* succ; // 后继节点

    // 构造函数
    ListNode(int e = 0, ListNode* p = nullptr, ListNode* s = nullptr) 
        : data(e), pred(p), succ(s) {}
};

// 定义列表类
class List {
private:
    int _size;
    ListNode* header;
    ListNode* trailer;

    // 初始化列表
    void init() {
        header = new ListNode();
        trailer = new ListNode();
        header->succ = trailer;
        trailer->pred = header;
        _size = 0;
    }

public:
    // 构造函数
    List() { init(); }

    // 获取列表大小
    int size() const { return _size; }

    // 在列表末尾插入元素
    void insertAsLast(int const& e) {
        ListNode* newNode = new ListNode(e, trailer->pred, trailer);
        trailer->pred->succ = newNode;
        trailer->pred = newNode;
        ++_size;
    }

    // 在指定位置插入新节点
    void insertAfterRank(int r, int m) {
        ListNode* p = header->succ;
        for (int i = 1; i < r; ++i) {
            p = p->succ;
        }
        ListNode* newNode = new ListNode(m, p, p->succ);
        p->succ->pred = newNode;
        p->succ = newNode;
        ++_size;
    }

    // 删除第r个节点的前驱节点
    void removePredOfRank(int r) {
        ListNode* p = header->succ;
        for (int i = 1; i < r; ++i) {
            p = p->succ;
        }
        if (p->pred != header) { // 确保前驱存在
            ListNode* toRemove = p->pred;
            toRemove->pred->succ = p;
            p->pred = toRemove->pred;
            delete toRemove;
            --_size;
        }
    }

    // 输出列表
    void print() const {
        ListNode* p = header->succ;
        while (p != trailer) {
            std::cout << p->data << (p->succ != trailer ? " " : "");
            p = p->succ;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n, r, m;
    std::cin >> n;
    List myList;

    // 输入列表节点的值
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        myList.insertAsLast(value);
    }

    std::cin >> r >> m;

    // 插入节点并删除前驱节点
    myList.insertAfterRank(r, m);
    myList.removePredOfRank(r);

    // 输出列表
    myList.print();

    return 0;
}
