#include <iostream>
#include <vector>

class CircularQueue
{
private:
    std::vector<int> data; // 存储队列的数组
    int front;             // 队首索引
    int rear;              // 队尾索引
    int size;              // 当前队列的大小
    int capacity;          // 队列的最大容量

public:
    CircularQueue(int n) : capacity(n), front(0), rear(0), size(0)
    {
        data.resize(n);
    }

    // 从队首获取元素
    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[front];
    }

    // 获取队尾元素
    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[(rear - 1 + capacity) % capacity];
    }

    // 向循环队列插入一个元素
    bool enQueue(int value)
    {
        if (isFull())
        {
            return false; // 队列已满
        }
        data[rear] = value;
        rear = (rear + 1) % capacity; // 循环移动队尾
        size++;
        return true;
    }

    // 从循环队列中删除一个元素
    bool deQueue()
    {
        if (isEmpty())
        {
            return false; // 队列为空
        }
        front = (front + 1) % capacity; // 循环移动队首
        size--;
        return true;
    }

    // 检查循环队列是否为空
    bool isEmpty()
    {
        return size == 0;
    }

    // 检查循环队列是否已满
    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m; // 队列长度和操作个数
    CircularQueue queue(n);
    std::vector<int> results;

    for (int i = 0; i < m; ++i)
    {
        int operation;
        std::cin >> operation; // 操作类型

        if (operation == 0)
        { // Front
            results.push_back(queue.Front());
        }
        else if (operation == 1)
        { // Rear
            results.push_back(queue.Rear());
        }
        else if (operation == 2)
        { // enQueue
            int value;
            std::cin >> value;
            results.push_back(queue.enQueue(value) ? 1 : 0);
        }
        else if (operation == 3)
        { // deQueue
            results.push_back(queue.deQueue() ? 1 : 0);
        }
        else if (operation == 4)
        { // isEmpty
            results.push_back(queue.isEmpty() ? 1 : 0);
        }
        else if (operation == 5)
        { // isFull
            results.push_back(queue.isFull() ? 1 : 0);
        }
    }

    // 输出结果
    for (int result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}
