#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> freq(n);

    // 读取字符频率
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    // 使用最小堆来构建霍夫曼树
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 初始化堆，把每个频率放入堆中
    for (int f : freq) {
        if (f > 0) {  // 只处理出现频率大于0的字符
            minHeap.push(f);
        }
    }

    // 如果只有一个节点且频率大于零，直接返回它的编码长度
    if (minHeap.size() == 1) {
        cout << minHeap.top() << endl;
        return 0;
    }

    // 计算霍夫曼编码总长度
    long long totalLength = 0;

    // 构建霍夫曼树
    while (minHeap.size() > 1) {
        // 取出两个最小频率的节点
        int left = minHeap.top(); minHeap.pop();
        int right = minHeap.top(); minHeap.pop();

        // 合并两个节点，生成新的父节点
        int parent = left + right;

        // 累加编码长度
        totalLength += parent;  // 每次合并都会增加总长度

        // 将新节点放回堆中
        minHeap.push(parent);
    }

    // 输出编码总长度
    cout << totalLength << endl;

    return 0;
}
