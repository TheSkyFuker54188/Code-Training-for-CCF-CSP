//? 哈希表 + 双向链表
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// 双向链表节点
struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, DLinkedNode *> cache; // key -> 节点指针
    DLinkedNode *head;                       // 虚拟头
    DLinkedNode *tail;                       // 虚拟尾
    int capacity;
    int size;

    // 将节点从链表中移除
    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 将节点插入到头部（最近使用）
    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 将节点移动到头部
    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    // 移除尾部节点（最久未使用）
    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) : capacity(cap), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node); // 标记为最近使用
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            // 已存在，更新值并移到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            // 新节点
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                // 移除最久未使用
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    cin.ignore(); // 忽略换行

    LRUCache cache(capacity);
    string line;

    while (getline(cin, line))
    {
        if (line.empty())
            continue;
        istringstream iss(line);
        string op;
        iss >> op;

        if (op == "get")
        {
            int key;
            iss >> key;
            cout << cache.get(key) << endl;
        }
        else if (op == "put")
        {
            int key, value;
            iss >> key >> value;
            cache.put(key, value);
            // put 无输出
        }
    }

    return 0;
}