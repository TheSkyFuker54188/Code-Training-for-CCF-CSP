// 2015年09月 第A题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000;

int n;
int num[MAX];

int seg = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] == num[i + 1])
            continue;
        else
            seg++;
    }
    cout << seg;
}