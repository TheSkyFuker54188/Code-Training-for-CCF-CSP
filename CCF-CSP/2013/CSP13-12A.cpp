// 2013年12月 第A题
// 算法 + 数据结构）

#include <iostream>
using namespace std;

int x[10001] = {0};

int main()
{
    int n;
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x[temp]++;
    }

    int max = 0, k;
    for (int i = 1; i <= 10001; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
            k = i;
        }
    }
    cout << k;
}