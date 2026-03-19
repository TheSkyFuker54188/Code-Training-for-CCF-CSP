// 2017年12月 第B题
// 算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000 + 1;

int n, k;
int a[MAX];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        a[i] = 1;

    int cnt = n;
    int num = 1;
    int ptr = 0;
    while (cnt != 1)
    {
        while (a[ptr] == 0)
        {
            ptr++;
            ptr %= n;
        }
        if (num % k == 0 || num % 10 == k)
        {
            a[ptr] = 0;
            cnt--;
        }
        num++;
        ptr++;
        ptr %= n;
    }
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            cout << i + 1;
}