#include <iostream>
//     #include<algorithm>
using namespace std;

int sum = 0;
int main() {
    int n;
    cin >> n;  // 输入数的个数
    int sum = 0;  // 初始化总和为0
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  // 输入每个数
        if (x >= 0) {
            sum += x;  // 如果数大于等于0，将其加到总和中
        }
    }
    cout << sum << endl;  // 输出结果
    return 0;
}