#include <iostream>
#include <vector>
using namespace std;

// 初始化游标列表函数
void initializeList(vector<int>& cursorList, int n, vector<int>& values) {
    cursorList = values;  // 初始化游标列表
}

// 插入操作函数，将整数q插入到位置p
void insertAtPosition(vector<int>& cursorList, int q, int p) {
    cursorList.insert(cursorList.begin() + (p - 1), q);  // 在游标列表的第p个位置插入q
}

// 删除操作函数，删除列表中第一个出现的整数q
void removeValue(vector<int>& cursorList, int q) {
    for (auto it = cursorList.begin(); it != cursorList.end(); ++it) {
        if (*it == q) {
            cursorList.erase(it);  // 删除第一个匹配到的q
            break;
        }
    }
}

int main() {
    int n, m;

    // 输入列表长度n
    cin >> n;
    vector<int> cursorList(n);

    // 输入n个整数作为初始列表
    for (int i = 0; i < n; ++i) {
        cin >> cursorList[i];
    }

    // 输入操作次数m
    cin >> m;

    // 逐行处理每个操作
    for (int i = 0; i < m; ++i) {
        int operationType;
        cin >> operationType;  // 读取操作类型，1为插入，0为删除

        if (operationType == 1) {
            int q, p;
            cin >> q >> p;  // 插入操作的整数q和位置p
            insertAtPosition(cursorList, q, p);
        } else if (operationType == 0) {
            int q;
            cin >> q;  // 删除操作的整数q
            removeValue(cursorList, q);
        }
    }

    // 输出最终列表
    for (int i = 0; i < cursorList.size(); ++i) {
        cout << cursorList[i] << " ";
    }

    return 0;
}
