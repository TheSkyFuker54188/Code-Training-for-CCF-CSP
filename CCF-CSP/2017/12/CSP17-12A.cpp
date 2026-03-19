// 2017年12月 第A题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000;
int n;
int a[MAX];

int dif = MAX * MAX;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (abs(a[i] - a[j]) < dif)
                dif = abs(a[i] - a[j]);
        }

    cout << dif;
}