// 2016年09月 第A题
// 算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000;

int price[MAX];
int gap[MAX];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n - 1; i++)
        gap[i] = abs(price[i] - price[i + 1]);
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (gap[i] > ans)
            ans = gap[i];
    cout << ans;
}